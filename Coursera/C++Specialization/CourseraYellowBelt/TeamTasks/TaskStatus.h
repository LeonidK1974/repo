#pragma once
#include <map>
using namespace std;

enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE	// завершена
};

// перегрузка инкремента
TaskStatus& operator++(TaskStatus& ts) {
	return (TaskStatus&)(++(int&)ts);
}

//Объявляем тип-синоним для map<TaskStatus, int>,
//позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
