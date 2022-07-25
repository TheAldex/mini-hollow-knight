#pragma once

#include <stack>
#include <mutex>

typedef std::lock_guard<std::recursive_mutex> MutexLocker;

template<typename T>
class objectPool
{
public:
	objectPool();
	~objectPool();
	T* PopObject();
	void SetSize(int size);
	void Expand();
	void ReturnObject(T* object);
	int ReturnSize();

private:
	std::recursive_mutex _mt;
	std::stack<T*> _objects;
	int _maxSize; // Maximum array size
};
// Create objects by size
template<typename T>
objectPool<T>::objectPool() {}

// Empty the object
template<typename T>
objectPool<T>::~objectPool()
{
	MutexLocker locker(_mt);
	while (!_objects.empty()) {
		T* object = _objects.top();
		_objects.pop();
		delete object;
	}

	_maxSize = 0;
}

template<typename T>
void objectPool<T>::SetSize(int size) {
	_maxSize = size;

	for (int i = 0; i < _maxSize; ++i) {
		T* newObject = new T();
		_objects.push(newObject);
	}
}

// Eject the object
template<typename T>
T* objectPool<T>::PopObject()
{
	MutexLocker locker(_mt);

	// If the object does not exist, expand it
	if (_objects.empty()) {
		Expand();
	}

	T* retVal = _objects.top();
	_objects.pop();
	return retVal;
}

// Expand by putting a new object by its current size
template<typename T>
void objectPool<T>::Expand() {
	MutexLocker locker(_mt);

	for (int i = 0; i < _maxSize; ++i)
	{
		T* newObject = new T();
		_objects.push(newObject);
	}

	_maxSize += _maxSize;
}

// Collect the object
template<typename T>
void objectPool<T>::ReturnObject(T* object)
{
	MutexLocker locker(_mt);
	_objects.push(object);
}

template<typename T>
int objectPool<T>::ReturnSize()
{
	return _objects.size();
}