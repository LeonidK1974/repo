#pragma once
#include <map>
using namespace std;

enum class TaskStatus {
	NEW,          // �����
	IN_PROGRESS,  // � ����������
	TESTING,      // �� ������������
	DONE	// ���������
};

// ���������� ����������
TaskStatus& operator++(TaskStatus& ts) {
	return (TaskStatus&)(++(int&)ts);
}

//��������� ���-������� ��� map<TaskStatus, int>,
//������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;
