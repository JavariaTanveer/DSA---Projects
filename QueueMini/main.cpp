#include "myLL.h"
#include "myQueue.h"

template<class T> 
myQueue <T> reverseQueue(myQueue <T> obj)
{
	int size = obj.size();
	myQueue <T> Reverse;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < obj.size() - 1; j++)
		{
			obj.enqueue(obj.dequeue());
		}
		Reverse.enqueue(obj.dequeue());
	}
	return Reverse;
}

int main()
{
	myQueue<char> q1;
    q1.enqueue('A');
	q1.enqueue('B');
	q1.enqueue('C');
	q1.enqueue(' ');
	q1.enqueue('D');
	q1.enqueue('E');
	q1.enqueue('F');
	cout<<"------------Before Reversing the Data-----------------"<<endl;
	q1.display();
	
	cout<<"------------After Reversing the Data-----------------"<<endl;
	myQueue<char> reverseQ1 = reverseQueue(q1);
	reverseQ1.display();
	return 0;
}