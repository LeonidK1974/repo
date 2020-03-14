#pragma once
#include <string>
#include <tuple>
#include "TaskStatus.h"

using namespace std;

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
	// ћетод сложени€ всех существующих обновлений с нетронутыми значени€ми
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

/*class TeamTasks {
public:
	// ѕолучить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return team_tasks.at(person);
	}

	// ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
	void AddNewTask(const string& person) {
		++team_tasks[person][TaskStatus::NEW];
	}

	// ќбновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count) {

		TasksInfo updated_ti, untouched_ti;

		if (team_tasks.count(person) == 0)
		{
			return { updated_ti, untouched_ti };
		}

		auto& current_ti = team_tasks.at(person);

		TaskStatus item = TaskStatus::NEW;

		do
		{
			if (task_count == 0) {
				if (current_ti[item] > 0 && item != TaskStatus::DONE) {
					untouched_ti[item] = current_ti[item];
				}
			}
			else {

				if (task_count < current_ti[item] && (item != TaskStatus::DONE)) {
					updated_ti[static_cast<TaskStatus>(static_cast<int>(item) + 1)] = task_count;
					untouched_ti[item] = current_ti[item] - task_count;
					task_count = 0;
				}
				else if ((task_count == current_ti[item] && (item != TaskStatus::DONE))) {
					updated_ti[static_cast<TaskStatus>(static_cast<int>(item) + 1)] = current_ti[item];
					task_count = 0;
				}
				else
				{
					if (current_ti[item] > 0) {
						updated_ti[static_cast<TaskStatus>(static_cast<int>(item) + 1)] = current_ti[item];
					}
					task_count -= current_ti[item];
				}

			}


			if (item == TaskStatus::DONE) {
				break;
			}

			++item;
		} while (1);


		item = TaskStatus::NEW;
		TasksInfo updated_ti_copy = updated_ti;
		TasksInfo untouched_ti_copy = untouched_ti;

		do
		{
			if (item == TaskStatus::NEW) {
				if (untouched_ti_copy[item] > 0) {
					current_ti[item] = untouched_ti_copy[item];
				}
				else {
					current_ti[item] = 0;
				}
			}
			else if (item == TaskStatus::DONE) {
				if (updated_ti_copy[item] > 0) {
					current_ti[item] += updated_ti_copy[item];
				}
			}
			else {
				current_ti[item] = updated_ti_copy[item] + untouched_ti_copy[item];
			}

			if (item == TaskStatus::DONE) {
				break;
			}
			++item;
		} while (1);

		return { updated_ti,  untouched_ti };
	}

private:
	map<string, TasksInfo> team_tasks;
};*/


