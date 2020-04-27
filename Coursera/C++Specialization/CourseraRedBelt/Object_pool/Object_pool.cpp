#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate() {
		if (!dismissed_.empty()) {
			T* subject = dismissed_.front();
			allocated_.insert(subject);
			dismissed_.pop_front();
			return subject;
		}
		T* object = new T;     // то что я понимаю под созданием объекта
		allocated_.insert(object);
		return object;       // указатель должен быть на объект в множестве
	}                     // или сам объект должен быть указателем

	T* TryAllocate() {
		if (!dismissed_.empty()) {
			T* subject = dismissed_.front();
			allocated_.insert(subject);
			dismissed_.pop_front();
			return subject;
		}
		return nullptr;
	}

	void Deallocate(T* object) {
		auto result = allocated_.find(object);
		if (result == end(allocated_)) { // как не за линейную сложность найти
			throw invalid_argument("");  // и удалить объект из множества выделенных
		}
		dismissed_.push_back(object);
		allocated_.erase(result);
	}

	~ObjectPool()
	{
		for (const auto& i : allocated_)
		{
			delete i;
		}

		for (const auto& i : dismissed_)
		{
			delete i;
		}
	};


private:
	// Добавьте сюда поля
	set<T*> allocated_; // множество выделенных
	deque<T*> dismissed_; // множество освобождённых
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}

