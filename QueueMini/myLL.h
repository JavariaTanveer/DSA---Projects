#include "LinkedList.h"

#pragma once
template <class T>
class myLL : public LinkedList<T>
{
protected:
	int size = {};
public:
	myLL() :LinkedList<T>()
	{}
	void insertAtEnd(T);
	T deleteFromHead();
	bool isEmpty();
	int Size();
	void display();
};

template<class T>
void myLL<T>::insertAtEnd(T value)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<T>::head == nullptr)
	{
		LinkedList<T>::head = newNode;
	}
	else
	{
		Node<T>* anotherNewNode = LinkedList<T>::head;
		while (1)
		{
			if (anotherNewNode->next == nullptr)
			{
				anotherNewNode->next = newNode;
				break;
			}
			anotherNewNode = anotherNewNode->next;
		}
	}
	++size;
}

template<class T>
T myLL<T>::deleteFromHead()
{
	T value = {};
	if (LinkedList<T>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		value = LinkedList<T>::head->data;
		delete[] LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		--size;
	}
	else
	{
		value = LinkedList<T>::head->data;
		Node<T>* newNode = LinkedList<T>::head;
		LinkedList<T>::head = LinkedList<T>::head->next;
		delete[] newNode;
		newNode = nullptr;
		--size;
	}
	return value;
}

template<class T>
bool myLL<T>::isEmpty()
{
	if (LinkedList<T>::head == nullptr)
	{
		return true;
	}
	return false;
}

template<class T>
int myLL<T>::Size()
{
	return size;
}

template<class T>
void myLL<T>::display()
{
	if (LinkedList<T>::head == nullptr)
	{
		cout << "Linked List is Empty.\n";
	}
	else
	{
		int i = 0;
		Node<T>* newNode = LinkedList<T>::head;
		for (newNode; newNode != nullptr; newNode = newNode->next, ++i)
		{
			cout << i << ". " << newNode->data << endl;
		}
		cout << endl;
	}
}