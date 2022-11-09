#include "Node.h"
#include <iostream>
using namespace std;

#pragma once
template<class T>
class LinkedList
{
protected:
	Node<T>* head;
public:
	LinkedList();
	virtual void insertAtEnd(T) = 0;
	virtual T deleteFromHead() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
	virtual int Size() = 0;
};

template<class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}
