// MapInMap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>

using namespace std;

enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

const TasksInfo& GetPersonTasksInfo(const map<string, TasksInfo>& team_tasks, const string& person) {
	return team_tasks.at(person);
}

tuple<TasksInfo, TasksInfo> PerformPersonTasks(map<string, TasksInfo>& team_tasks,
	const string& person, int task_count) {
	TasksInfo current_ti = GetPersonTasksInfo(team_tasks, person);
	int undone_task_count = 0;

	for (auto it = current_ti.begin(); it != --current_ti.end(); it++) {
		//apply to all from begin to second last elemen
		undone_task_count += it->second;				
	}
	if (undone_task_count < task_count) {
		task_count = undone_task_count;
	}
		
	TasksInfo updated_tasks, untouched_tasks;
	return { updated_tasks,  untouched_tasks };
}

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
	map<string, TasksInfo> team_tasks{ {"Leon",{{TaskStatus::NEW , 3}, {TaskStatus::IN_PROGRESS , 0} , {TaskStatus::TESTING , 0}, {TaskStatus::DONE , 0}}}, {"Ivan",{{TaskStatus::NEW , 1}, {TaskStatus::IN_PROGRESS , 2} , {TaskStatus::TESTING , 1}, {TaskStatus::DONE , 3}}} };

	PrintTasksInfo(GetPersonTasksInfo(team_tasks, "Leon"));
	PrintTasksInfo(GetPersonTasksInfo(team_tasks, "Ivan"));

	TasksInfo updated_tasks, untouched_tasks;
	//tie(updated_tasks, untouched_tasks) = PerformPersonTasks(team_tasks, "Leon", 2);
	tie(updated_tasks, untouched_tasks) = PerformPersonTasks(team_tasks, "Ivan", 2);
}


