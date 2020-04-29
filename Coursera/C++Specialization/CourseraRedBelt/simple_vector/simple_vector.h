#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector() {
		data = nullptr;
		size_ = 0;
		capacity_ = 0;
	};
  explicit SimpleVector(size_t size) : size_(size) , capacity_(size) { 
	  data = new T[size]; 
  }
  ~SimpleVector() {
	  delete[] data;
  }

  T& operator[](size_t index) {
	  return data[index];
  }

  T* begin() {
	  return data;
  }

  T* end() {
	  return &data[Size()];
  }

  const T* begin() const { 
	  return data; 
  } 
  
  const T* end() const { 
	  return &data[Size()];
  }

size_t Size() const {
	  return size_;
  }
  size_t Capacity() const {
	  return capacity_;
  }

  void PushBack(const T& value) {
	  if (size_ == capacity_)
	  {
		  Reserve(capacity_ * 2 + 1);
	  }
	  data[size_++] = value;
  }

  void Reserve(size_t newCapacity) {
	  T* old = data;
	  size_t numToCopy = newCapacity < size_ ? newCapacity : size_;

	  data = new T[newCapacity];
	  for (size_t i = 0; i < numToCopy; i++) {
		  data[i] = old[i];
	  }

	  size_ = numToCopy;
	  capacity_ = newCapacity;

	  delete[] old;
  }

private:
  // Добавьте поля для хранения данных вектора
	T* data; 
	size_t size_;
	size_t capacity_;

};
