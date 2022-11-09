#pragma once
#include "StackADT.h"

template<class Type>
class Stack : public StackADT<Type>
{
public:
	Stack(const int& = 0);
	~Stack();
	void push(Type);
	Type pop();
	void Top();
	bool isFull();
	bool isEmpty();
	void printStack();
	void searchInStack(Type);
};

template<class Type>
inline Stack<Type>::Stack(const int& size)
{
	StackADT<Type>::maxSize = size;
	StackADT<Type>::currSize = 0;
	StackADT<Type>::arr = new Type[StackADT<Type>::maxSize]{};
}

template<class Type>
inline Stack<Type>::~Stack()
{
	delete[]StackADT<Type>::arr;
	StackADT<Type>::arr = nullptr;
}

template<class Type>
inline void Stack<Type>::push(Type value)
{
	if (!isFull()) {
		StackADT<Type>::arr[StackADT<Type>::currSize++] = value;
	}
	else {
		cout << "Stack is full, no more space" << endl;
	}
}

template<class Type>
inline Type Stack<Type>::pop()
{
	Type temp = NULL;
	if (!isEmpty()) {
		return StackADT<Type>::arr[--StackADT<Type>::currSize];
	}

	//cout << "Stack is empty, returning garbage value!" << endl;
	
	return temp;
}

template<class Type>
inline void Stack<Type>::Top()
{
	cout << "The top value in stack is: " << StackADT<Type>::arr[StackADT<Type>::currSize - 1] << endl;
}

template<class Type>
inline bool Stack<Type>::isFull()
{
	if (StackADT<Type>::maxSize == StackADT<Type>::currSize) {
		return true;
	}
	return false;
}

template<class Type>
inline bool Stack<Type>::isEmpty()
{
	if (StackADT<Type>::currSize == 0) {
		return true;
	}
	return false;
}

template<class Type>
inline void Stack<Type>::printStack()
{
	cout << "Maximum Size: " << StackADT<Type>::maxSize << endl;
	cout << "Current Size: " << StackADT<Type>::currSize << endl;
	for (int i = 0; i < StackADT<Type>::currSize; i++) {
		cout << StackADT<Type>::arr[i] << endl;
	}
}

template<class Type>
inline void Stack<Type>::searchInStack(Type value)
{
	Stack<Type> tempObj(StackADT<Type>::maxSize);
	Type tempVar = 0;
	int flag = 0;
	
	while (!this->isEmpty()) {

		tempVar = this->pop();
		if (tempVar == value) {

			flag = 1;
			cout << "Found" << endl;
			tempObj.push(tempVar);
			break;

		}
		else {
			tempObj.push(tempVar);
		}

	}

	while(!tempObj.isEmpty()) {

		this->push(tempObj.pop());

	}

	if (flag == 0) {
		cout << "Not Found" << endl;
	}

}
