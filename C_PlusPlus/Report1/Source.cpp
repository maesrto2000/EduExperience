#include "Queue1.h"
using namespace std;
void main()
{   
	Queue1*q = new Queue1();
	Queue*qcpy = new Queue1();

	
	int n;
	setlocale(LC_ALL, "Russian");
	bool isrun = true;
	int action;
	while (isrun)
	{
		cout << "1-Добавлене элемента очереди" << endl;
		cout << "2-Извлечение элемента из очереди" << endl;
		cout << "3-Вывод очереди на экран" << endl;
		cout << "4-Вычисление значения" << endl;
		cout << "5-Создание копии очереди" << endl;
		cout << "6-Слияние оригинальной очереди с копией и вывод результата на экран" << endl;
		cout << "7-Выход из программы" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			cout << "Введите количество элементов очереди: ";
			cin >> n;
			cout << "Введите очередь: " << endl;
			for (int i = 0; i < n; i++)
			{
				int a;
				cin >> a;
				q->push(a);
			}
				break;
		case 2:
			cout<<q->pop()<<endl;
			break;
		case 3:
			q->print();
			cout << endl;
			break;
		case 4:
			q->function();
			cout << endl;
			break;
		case 5:
			qcpy=q->copy();
			cout <<"Очередь скопирована"<< endl;
			break;
		case 6:
			(q->merge(q))->print();
			cout << endl;
			break;
		case 7:
			isrun=0;
			break;
		}
	}
	system("pause");
}
