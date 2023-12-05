#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node*next; 
};
class Queue
{
private:
	Node*q; 
	Node*tail;
	int size; 
public:
	int getsize();
	Queue();
	~Queue();
	void push(int n);
	
	int pop();
	void print();
	Queue*copy();
	Queue*merge(Queue*queue);
	bool isempty();
	double getavg();
	int countOver(double value);
};
