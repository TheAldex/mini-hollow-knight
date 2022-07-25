#pragma once

template <class T>
class singletonBase
{
protected:
	// Singleton object declaration
	static T* singleton;

	singletonBase() {}
	~singletonBase() {}
public:
	// Get a Singleton Object
	static T* getSingleton();
	// To Release a Singleton Object
	void releaseSingleton();
};

// Singleton object initialization
template<class T>
T* singletonBase<T>::singleton = nullptr;

// Get a Singleton Object
template<class T>
inline T * singletonBase<T>::getSingleton()
{
	// If there are no singletons, create a new one
	if (!singleton) singleton = new T;
	return singleton;
}

// To Release a Singleton Object
template<class T>
inline void singletonBase<T>::releaseSingleton()
{
	// If you have a singleton, release it from memory
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}