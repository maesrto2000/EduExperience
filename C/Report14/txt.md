# Задание 
Реализоввать базу данных “Авиакасса”: Пополнение базы (ввод новых маршрутов). Редактирование базы. Удаление записей. Подбор маршрута с наименьшем временем ожидания при пересадке. Подбор маршрута с наименьшей стоимостью.
```
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
	int year, month, day, hour, minute;
} DateTime; //тип даты

typedef struct
{
	float cost;
	char departurePoint[256]; 
	char destination[256]; 
	DateTime departureTime; 
	DateTime arrivalTime;  
} Trip;

Trip* trips; 
int size;
void loadFile(char*fileName)
{
	int length;
	FILE *fp;
	fp = fopen(fileName, "rb");
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	size = length / sizeof(Trip);
	fseek(fp, 0, SEEK_SET);
	fread(trips, sizeof(Trip), size, fp);
	fclose(fp);
}
void PrintTrips()
{
	printf("%s%19s%18s  %10s %10s     %10s\n", "№", "Пункт отправления", "Пункт назначения", "Стоимость",
		"Дата отправления", "Дата прибытия");
	for (int i = 0; i < size; i++)
	{
		printf("%i. %-18s %-19s%-8.0f  %i.%i.%i %i:%02i       %i.%i.%i %i:%02i\n", i + 1, trips[i].departurePoint,
			trips[i].destination, trips[i].cost, trips[i].departureTime.day,
			trips[i].departureTime.month, trips[i].departureTime.year,
			trips[i].departureTime.hour, trips[i].departureTime.minute, trips[i].arrivalTime.day,
			trips[i].arrivalTime.month, trips[i].arrivalTime.year, trips[i].arrivalTime.hour,
			trips[i].arrivalTime.minute);
	}
}
void SaveToFile(char*filename)
{
	FILE*f = fopen(filename, "wb");
	fwrite(trips, sizeof(Trip), size, f);
	fclose(f);
}

void AddTrip(Trip trip)
{
	trips = (Trip*)realloc(trips, sizeof(Trip) * (size + 1));
	trips[size].arrivalTime.day = trip.arrivalTime.day;
	trips[size].arrivalTime.hour = trip.arrivalTime.hour;
	trips[size].arrivalTime.minute = trip.arrivalTime.minute;
	trips[size].arrivalTime.month = trip.arrivalTime.month;
	trips[size].arrivalTime.year = trip.arrivalTime.year;
	trips[size].departureTime.day = trip.departureTime.day;
	trips[size].departureTime.hour = trip.departureTime.hour;
	trips[size].departureTime.minute = trip.departureTime.minute;
	trips[size].departureTime.month = trip.departureTime.month;
	trips[size].departureTime.year = trip.departureTime.year;
	trips[size].cost = trip.cost;
	strcpy(trips[size].departurePoint, trip.departurePoint);
	strcpy(trips[size].destination, trip.destination);
	size++;
}
int DeleteTrip(int index)//удаление маршрута 
{
	if (index >= 0 && index < size) 
	{
		for (int i = index; i < size - 1; i++)
		{
			trips[i] = trips[i + 1];
		}
		trips = ((Trip*)realloc(trips, sizeof(Trip) * size - 1));
		size--;
		return 0;
	}
	else
	{
		return 1;
	}
}
int timeDifferent(DateTime t1, DateTime t2)
{
	int sec = (t1.hour * 3600 + t1.minute * 60); 
	int sec2 = (t2.hour * 3600 + t2.minute * 60);
	return abs(sec - sec2);
}

int* QuickTrip(char* departure, char* destination)
{
	int tmpSize = 0;
	int* result = malloc(sizeof(int) * 2);
	int* tmpTrips = malloc(sizeof(int));
	int waitingTime = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(trips[i].destination, destination) == 0)
		{
			tmpTrips = realloc(tmpTrips, sizeof(int) * (tmpSize + 1));
			tmpTrips[tmpSize] = i;
			tmpSize++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (strcmp(trips[i].departurePoint, departure) == 0)
		{
			for (int j = 0; j < tmpSize; j++)
			{
				if (strcmp(trips[i].destination, trips[tmpTrips[j]].departurePoint) == 0)
				{
					if (timeDifferent(trips[i].arrivalTime, trips[tmpTrips[j]].departureTime) < waitingTime)
					{
						waitingTime = timeDifferent(trips[i].arrivalTime, trips[tmpTrips[j]].departureTime);
						result[0] = i;
						result[1] = tmpTrips[j];
					}
				}
			}
		}
	}
	return result;
}

int* CheapTrip(char*departure, char*destination)
{
	int tmpSize = 0;
	int* tmpTrips = malloc(sizeof(int));
	float cheapCost = 1000000000.0;
	int* result = malloc(sizeof(int) * 2);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(trips[i].destination, destination) == 0)
		{
			tmpTrips = realloc(tmpTrips, sizeof(int)*(tmpSize + 1));
			tmpTrips[tmpSize] = i;
			tmpSize++;
		}
		if (strcmp(trips[i].destination, destination) == 0 &&
			strcmp(trips[i].departurePoint, departure) == 0)
		{
			cheapCost = trips[i].cost;
			result[0] = i;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (strcmp(trips[i].departurePoint, departure) == 0)
		{
			for (int j = 0; j < tmpSize; j++)
			{
				if (strcmp(trips[i].destination, trips[tmpTrips[j]].departurePoint) == 0)
				{
					if (trips[i].cost + trips[tmpTrips[j]].cost < cheapCost)
					{
						cheapCost = trips[i].cost + trips[tmpTrips[j]].cost;
						result[0] = i;
						result[1] = tmpTrips[j];
					}
				}
			}
		}
	}

	return result;
}
int CheckDate(DateTime dt)
{
	int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (dt.day < 1 || dt.day>days[dt.month])
		return 0;
	if (dt.month < 1 || dt.month>12)
		return 0;
	if (dt.hour < 0 || dt.hour>24)
		return 0;
	if (dt.minute < 0 || dt.minute>60)
		return	0;
	return 1;
}
int main()
{
	setlocale(0, "RU");
	trips = (Trip*)malloc(sizeof(Trip));
	size = 0;
	Trip t;
	Trip* tFind;
	int isrun = 1;
	int action;
	int n, n1;
	char tmp1[256];
	char tmp[256];
	int* resultTrip;
	while (isrun == 1)
	{
		printf("1-добавить рейс\n");
		printf("2-показать рейсы\n");
		printf("3-загрузить из файла\n");
		printf("4-сохранить в файл\n");
		printf("5-редактировать рейс\n");
		printf("6-удалить рейс\n");
		printf("7-наименьшее время ожидания\n");
		printf("8-наименьшая стоимость\n");
		printf("9-выход\n");
		scanf("%d", &action);
		getchar();
		switch (action)
		{
		case 1:
			printf("Введите пункт отправления: ");
			scanf("%s", &t.departurePoint);
			printf("Введите пункт прибытия: ");
			scanf("%s", &t.destination);
			printf("Введите стоимость: ");
			scanf("%f", &t.cost);
			do 
			{
				printf("Введите время отправления: ");
				scanf("%i.%i.%i %i:%i", &t.departureTime.day, &t.departureTime.month, &t.departureTime.year,
					&t.departureTime.hour, &t.departureTime.minute);
				if (CheckDate(t.departureTime) == 0)
				{
					printf("Ошибка в формате даты\n");
				}
				else
					break;
			} while (1);
			do
			{
				printf("Введите время прибытия: ");
				scanf("%i.%i.%i %i:%i", &t.arrivalTime.day, &t.arrivalTime.month, &t.arrivalTime.year,
					&t.arrivalTime.hour, &t.arrivalTime.minute);
				if (CheckDate(t.departureTime) == 0)
				{
					printf("Ошибка в формате даты\n");
				}
				else
					break;
			} while (1);
			AddTrip(t);
			break;
		case 2:
			PrintTrips();
			break;
		case 3:
			printf("Введите имя файла: ");
			loadFile("1.dat");
			printf("Чтение завершено\n");
			break;
		case 4:
			printf("Введите имя файла: ");
			SaveToFile("1.dat");
			printf("Файл загружен\n");
			break;
		case 5:
			PrintTrips();
			printf("Введите номер рейса для редактирования: ");
			scanf("%i", &n);
			printf("Выберите поле для редактирования\n");
			printf("1-Пункт отправления\n");
			printf("2-Пункт назначения\n");
			printf("3-Время отправления\n");
			printf("4-Время прибытия\n");
			printf("5-Стоимость\n");
			scanf("%d", &n1);
			printf("Введите новое значение: ");
			n--;
			switch (n1)
			{
			case 1:
				scanf("%s", &trips[n].departurePoint);

				break;
			case 2:
				scanf("%s", &trips[n].destination);
				break;
			case 3:
				do
				{
					printf("Введите время отправления: ");
					scanf("%i.%i.%i %i:%i", &t.departureTime.day, &t.departureTime.month, &t.departureTime.year,
						&t.departureTime.hour, &t.departureTime.minute);
					if (CheckDate(t.departureTime) == 0)
					{
						printf("Ошибка в формате даты\n");
					}
					else
						break;
				} while (1);
			case 4:
				do
				{
					printf("Введите время прибытия: ");
					scanf("%i.%i.%i %i:%i", &t.arrivalTime.day, &t.arrivalTime.month, &t.arrivalTime.year,
						&t.arrivalTime.hour, &t.arrivalTime.minute);
					if (CheckDate(t.departureTime) == 0)
					{
						printf("Ошибка в формате даты\n");
					}
					else
						break;
				} while (1);
				break;
			case 5:
				scanf("%f", &trips[n].cost);
				break;
			}
			break;
		case 6:
			PrintTrips();
			printf("Введите номер удаляемого рейса: ");
			scanf("%i", &n);
			if (DeleteTrip(n - 1) == 1)
			{
				printf("Введён неверный индекс!\n");
				break;
			}
			printf("Рейс успешно удалён!\n");
			break;
		case 7:
			printf("Введите место отправления: ");
			gets(tmp);
			printf("Введите место назначения: ");
			gets(tmp1);
			resultTrip = QuickTrip(tmp, tmp1);
			printf("%s-%s\n", trips[resultTrip[0]].departurePoint, trips[resultTrip[0]].destination);
			printf("%s-%s\n", trips[resultTrip[1]].departurePoint, trips[resultTrip[1]].destination);
			break;
		case 8:
			printf("Введите место отправления: ");
			gets(tmp);
			printf("Введите место назначения: ");
			gets(tmp1);
			resultTrip = CheapTrip(tmp, tmp1);
			printf("%s-%s\n", trips[resultTrip[0]].departurePoint, trips[resultTrip[0]].destination);
			printf("%s-%s\n", trips[resultTrip[1]].departurePoint, trips[resultTrip[1]].destination);
			break;
		case 9:
			isrun = 0;
			break;
		}
	}

	trips = NULL;
	free(trips);
	return 0;
}
