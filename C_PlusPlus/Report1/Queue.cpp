#include "Queue.h"


int Queue::getsize()
{
	return this->size;
}

Queue::Queue()
{
	this->q = nullptr;
	this->size = 0;
}

Queue::~Queue()
{
}

void Queue::push(int n)
{
	Node*e = new Node;
	e->data = n;
	e->next = nullptr;
	if (this->q == nullptr)
	{
		this->q = e;
		this->tail = e; 
	}
	else
	{
		this->tail->next = e;
		this->tail = e;
	}
	size++;
}


int Queue::pop()
{
	int r = q->data; 
	Node*tmp = q;
	this->q = this->q->next;
	delete tmp;
	size--;
	return r;
}

void Queue::print()
{
	Node*tmp = this->q; 
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

Queue * Queue::copy()
{
	Queue*queue = new Queue();
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		queue->push(tmp->data);
		tmp = tmp->next;
	}
	return queue;
}

Queue * Queue::merge(Queue * queue)
{
	Queue*result = new Queue();
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		result->push(tmp->data);
		tmp = tmp->next;
	}
	Queue*t = queue->copy();
	while (!t->isempty())
	{
		result->push(t->pop());
	}
	return result;
}

bool Queue::isempty()
{
	return this->q == nullptr;
}

double Queue::getavg()
{
	int sum = 0;
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		sum += tmp->data;
		tmp = tmp->next;
	}
	return (double)sum/size;
}

int Queue::countOver(double value)
{
	Node*tmp = this->q;
	int result = 0;
	
	while (tmp != nullptr)
	{
		if (tmp->data > value)
			result++;
		tmp = tmp->next;
	}
	return 0;
}
