#include <iostream>
#include "File.h"

void sort(File*& files, int size)
{
	File tmp; 
	for(int i=0 ; i<size; i++) 
		for(int j = 0; j<size-i-1; j++) 
			if (files[j].getFileName() > files[j + 1].getFileName())
			{
				tmp = files[j]; 
				files[j] = files[j+1];
				files[j + 1] = tmp;
			}

}
void printFiles(File* files, int size) 
	for (int i = 0; i < size; i++)
		files[i].show();
}
void filterBySize(File* files, int size, int maxSize) 
{
	for (int i = 0; i < size; i++)
		if (files[i].getSize() > maxSize) 
			files[i].show(); 

}
void filterByReqest(File* files, int size, int maxCount) 
{
	for (int i = 0; i < size; i++)
		if (files[i].getRequestCount() > maxCount) 
			files[i].show(); 
}
void main()
{
	setlocale(0, "RU");
	File* f; 
	int size;
	size = 3; 
	f = new File[size]; 
	f[0] = File("B", 12, "12.12.12"); 
	f[1] = File("A", 45, "12.12.12");
	f[2] = File("C", 393, "12.1.12");
	f[0].addRequest(); 
	f[0].addRequest();
	f[0].addRequest();
	cout << "Отсортированный по имени файлу список " << endl;
	sort(f, size); 
	printFiles(f, size); 
	cout << endl; 
	cout << "Файлы больше 13 байт " << endl;
	filterBySize(f, size, 13); 
	cout << endl;
	cout << "Файлы c кол-вом обращений больше 2" << endl;
	filterByReqest(f, size, 2);
	system("PAUSE >> VOID");
}
