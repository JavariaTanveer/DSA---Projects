#include "Queue.h"
#pragma once
template <class T>
class myQueue : public Queue<T>
{ 
public:
	bool isEmpty();
	void enqueue(T);
	T dequeue();
	void display();
	int size();
};

template<class T>
bool myQueue<T>::isEmpty()
{
	return Queue<T>::obj.isEmpty();
}

template<class T>
void myQueue<T>::enqueue(T value)
{
	Queue<T>::obj.insertAtEnd(value);
}

template<class T>
T myQueue<T>::dequeue()
{
	return Queue<T>::obj.deleteFromHead();
}

template<class T>
void myQueue<T>::display()
{
	Queue<T>::obj.display();
}

template<class T>
int myQueue<T>::size()
{
	return Queue<T>::obj.Size();
}
