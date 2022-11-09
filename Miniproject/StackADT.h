#pragma once
#include <iostream>
using namespace std;

template<class Type>
class StackADT 
{
public:
	virtual void push(Type) = 0;
	virtual Type pop() = 0;
	virtual void Top() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
protected:
	Type* arr;
	int maxSize;
	int currSize;
};