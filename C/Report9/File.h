#pragma once
#include <string>
#include <iostream>
using namespace std;
class File
{
private: 
	int size;
	string fileName;
	string date;
	int requestCount;
public: 
	File(string fileName, int size, string date);
	File();/ 
	~File();
	void show();
	void addRequest();
	string getFileName(); 
	int getSize();
	int getRequestCount();
};
