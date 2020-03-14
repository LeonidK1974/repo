class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_tasks.at(person);
    }
    void AddNewTask(const string& person) {
        person_tasks[person][TaskStatus::NEW] += 1;
    }
 
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;
 
        if (person_tasks.count(person)) {
            TasksInfo& currentTask = person_tasks[person];
 
            for (auto& tasks : currentTask) {
                    switch (tasks.first) {
                    case TaskStatus::NEW:
                        if (tasks.second) {
                            untouched_tasks[tasks.first] = max(tasks.second - task_count, 0);
                            if (untouched_tasks.at(tasks.first)) {
                                updated_tasks[TaskStatus::IN_PROGRESS] = tasks.second - untouched_tasks[tasks.first];
                                /*if (currentTask[TaskStatus::IN_PROGRESS]) {
                                    untouched_tasks[TaskStatus::IN_PROGRESS] = currentTask[TaskStatus::IN_PROGRESS];
                                }*/
                                untouched_tasks[TaskStatus::IN_PROGRESS] = currentTask[TaskStatus::IN_PROGRESS];
                                untouched_tasks[TaskStatus::TESTING] = currentTask[TaskStatus::TESTING];
                                task_count = 0;
                            }
                            else {
                                updated_tasks[TaskStatus::IN_PROGRESS] = tasks.second;
                                task_count -= tasks.second;
                            }
                        }
                        break;
                    case TaskStatus::IN_PROGRESS:
                        if (tasks.second) {
                            untouched_tasks[tasks.first] = max(tasks.second - task_count, 0);
                            if (untouched_tasks.at(tasks.first)) {
                                updated_tasks[TaskStatus::TESTING] = tasks.second - untouched_tasks[tasks.first];
                                /*if (currentTask[TaskStatus::TESTING]) {
                                    untouched_tasks[TaskStatus::TESTING] = currentTask[TaskStatus::TESTING];
                                }*/
                                untouched_tasks[TaskStatus::TESTING] = currentTask[TaskStatus::TESTING];
                                task_count = 0;
                            }
                            else {
                                updated_tasks[TaskStatus::TESTING] = tasks.second;
                                task_count -= tasks.second;
                            }
                        }
                        break;
                    case TaskStatus::TESTING:
                        if (tasks.second) {
                            untouched_tasks[tasks.first] = max(tasks.second - task_count, 0);
                            if (untouched_tasks.at(tasks.first)) {
                                updated_tasks[TaskStatus::DONE] = tasks.second - untouched_tasks[tasks.first];
                            }
                            else {
                                updated_tasks[TaskStatus::DONE] = tasks.second;
                            }
                        }
                        task_count = 0;
                        break;
                    }                
            }
 
            AddUpdates(updated_tasks, untouched_tasks, currentTask);
        }
 
        return make_tuple(updated_tasks, untouched_tasks);
    }
 
private:
    // Метод сложения всех существующих обновлений с нетронутыми значениями
    void AddUpdates(const TasksInfo& update, TasksInfo& untouched, TasksInfo& target) {
        for (auto& status : { TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE }) {
            if (update.count(status) || untouched.count(status)) {
                if (status != TaskStatus::DONE) {
                    target[status] = 0;
                }
 
                if (update.count(status)) {
                    target[status] += update.at(status);
                }
                if (untouched.count(status)) {
                    target[status] += untouched.at(status);
                    if (untouched.at(status) == 0) {
                        untouched.erase(status);
                    }
                }
                if (target[status] == 0) {
                    target.erase(status);
                }
            }
        }
    }
 
    map<string, TasksInfo> person_tasks;
};