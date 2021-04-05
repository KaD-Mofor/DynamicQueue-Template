#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>

using namespace std;

template<class T>
class DynamicQueue
{
public:
	
	DynamicQueue();

	~DynamicQueue();

	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	void display(T&);
	void clear();

private:
	struct QueueNode
	{
		T value;           //To hold value in node
		QueueNode* next;   //ptr to next node
	};

	QueueNode* front;    //to mark the front of the queue
	QueueNode* rear;     //to mark the rear
	int num;             //To hold number of items in queue

};


template<class T>
DynamicQueue<T>::DynamicQueue()
{
	front = nullptr;
	rear = nullptr;
	num = 0;
}


template<class T>
DynamicQueue<T>::~DynamicQueue()
{
	clear();
}

template<class T>
inline void DynamicQueue<T>::enqueue(T obj)
{
	QueueNode* newNode = nullptr;

	newNode = new QueueNode;
	newNode->value = obj;
	newNode->next = nullptr;

	//Adjust from front and rear as needed
	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}

	//Update item count
	num++;

}

template<class T>
inline void DynamicQueue<T>::dequeue(T& obj)
{
	QueueNode* temp = nullptr;

	bool ex = isEmpty();

	if (ex)
	{
		throw ex;
	}
	else
	{
		//save front node value in obj
		obj = front->value;

		//remove the front node value and delete it
		temp = front;
		front = front->next;
		delete temp;

		//update item count
		num--;
	}

}

template<class T>
bool DynamicQueue<T>::isEmpty() const
{
	if (num > 0)
		return false;
	else
		return true;
}

template<class T>
inline void DynamicQueue<T>::display(T& obj)
{
	QueueNode* temp = nullptr;    //temp ptr

	bool ex = isEmpty();
	if (ex)
	{
		throw ex;
	}
	else
	{
		QueueNode* Front = front;   //holds front node

		cout << "\nHere are the values in the queue: " << endl;
		while (rear->next != rear)
		{
			cout << front->value << endl;
			obj = front->value;
			temp = front->next;
			front = temp;
		}

		front = Front;   // front's value is reinstated to the original value.
	}
}

template<class T>
inline void DynamicQueue<T>::clear()
{
	T value;    //Dummy variable for dequeue

	while (!isEmpty())
	{
		dequeue(value);
	}
}




#endif // !DYNAMICQUEUE_H
