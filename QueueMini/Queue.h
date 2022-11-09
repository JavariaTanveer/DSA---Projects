#pragma once
#include "myLL.h"

template<class T>
class Queue
{
protected:
	myLL<T> obj;
public:
	virtual bool isEmpty() = 0;
	virtual void enqueue(T) = 0;
	virtual T dequeue() = 0;
	virtual void display() = 0;
	virtual int size() = 0;
};