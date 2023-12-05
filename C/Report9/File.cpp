#include "File.h"


File::File(string fileName, int size, string date)
{    
	this->fileName = fileName; 
	this->date = date;
	this->requestCount = 0;
	this->size = size;
}

File::File()
{
}


File::~File()
{
}

void File::show() 
{                                                            
	cout << fileName << " " << size << " " << date << " " << requestCount << endl;
}

void File::addRequest()
{
	requestCount++;
}

string File::getFileName() 
{
	return fileName;
}

int File::getSize()
{
	return size; 
}

int File::getRequestCount()
{
	return requestCount; 
}
