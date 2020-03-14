#include <map>
#include <string>
#include <tuple>

using namespace std;


// перегрузка инкремента
TaskStatus& operator++(TaskStatus& ts) {
	return (TaskStatus&)(++(int&)ts);
}

class TeamTasks {
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
};