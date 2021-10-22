#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

// потоки фсканф фпринтф дефайны тайпдефы хедеры

int main(void)
{
	int choice = 0;

	FILE *Ptr, *Ptr_2, *blackrecord; //задефйнен FILE в библиотеке для работы с файлами

	Data client_data;
	Data transfer;

	printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");

	while (choice != -1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Ptr = fopen("record.dat", "r+"); // r+  Открывает файл для чтения/записи
			if (Ptr == NULL)
			{
				puts("Not acess");
			}
			else
			{
				masterWrite(Ptr, client_data);
				free(Ptr);	 //else выполняем фунцию  masterWrit
				fclose(Ptr); // close
			}
			break;
		case 2:
			Ptr = fopen("record.dat", "r+");
			// r+  Открывает файл для чтения/записи
			if (Ptr == NULL)
			{
				puts("Not acess");
			}
			else
			{
				transactionWrite(Ptr, transfer);
				free(Ptr);	 //else выполняем фунцию  transactionWrite
				fclose(Ptr); // close
			}
			break;
		case 3:
			Ptr = fopen("record.dat", "r");				 // r открытие файла для чтения.
			Ptr_2 = fopen("transaction.dat", "r");		 // r открытие файла для чтения.
			blackrecord = fopen("blackrecord.dat", "w"); // w  создать файл для записи, если файла уже существует, он будет открыт, он все имеющиеся в файле данные будут уничтожены.
			if (Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL)
			{
				puts("exit");
			}
			else
			{
				blackRecord(Ptr, Ptr_2, blackrecord, client_data, transfer);
				free(Ptr);
				free(Ptr_2);
				free(blackrecord); //Функция free() возвращает память, на которую указывает параметр ptr, назад в кучу. В резуль­тате эта память может выделяться снова.
				fclose(Ptr);	   // fopen(). Она сохраняет в файл данные, находящиеся в дисковом буфере, и выполняет операцию системного уровня по закрытию файла
				fclose(Ptr_2);
				fclose(blackrecord);
			}
			break;
		default:
			puts("error");
			break;
		}
		printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void masterWrite(FILE *ofPTR, Data Client)
{ // konsol'
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
		   "1 Number account: ",
		   "2 Client name: ",
		   "3 Surname: ",
		   "4 Addres client: ",
		   "5 Client Telnum: ",
		   "6 Client indebtedness: ",
		   "7 Client credit limit: ",
		   "8 Client cash payments: ");
	while (scanf("%d%s%s%s%s%lf%lf%lf",
				 &Client.Number,
				 Client.Name,
				 Client.Surname,
				 Client.addres,
				 Client.TelNumber,
				 &Client.indebtedness,
				 &Client.credit_limit,
				 &Client.cash_payments) != -1)
	{
		fprintf(ofPTR, "%-12d%-11s%-11s%-11s%-16s%20f%12.2f%12.2f\n", // 12 11 выведет максимум
				Client.Number,
				Client.Name,
				Client.Surname,
				Client.addres,
				Client.TelNumber,
				Client.indebtedness,
				Client.credit_limit,
				Client.cash_payments);
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
			   "1 Number account: ",
			   "2 Client name: ",
			   "3 Surname: ",
			   "4 Addres client: ",
			   "5 Client Telnum: ",
			   "6 Client indebtedness: ",
			   "7 Client credit limit: ",
			   "9 Client cash payments:");
	}
}
// fscanf fprintf  что такое поток   valgrind.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void transactionWrite(FILE *ofPTR2, Data transfer)
{
	printf("%s\n%s\n",
		   "1 Number account: ",
		   "2 Client cash payments: ");
	while (scanf("%d %lf", &transfer.Number, &transfer.cash_payments) != -1 )
	{
		fprintf(ofPTR2, "%-3d%-6.2f\n", transfer.Number, transfer.cash_payments);
		printf("%s  %d\n%s  %lf\n",
			   "1 Number account:", transfer.Number,
			   "2 Client cash payments: ", transfer.cash_payments);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer)
{
	while (fscanf(ofPTR, "%d%s%s%s%s%lf%lf%lf", //  Функция fscanf() считывает информацию из потока,
				  &client_data.Number,
				  client_data.Name,
				  client_data.Surname,
				  client_data.addres,
				  client_data.TelNumber,
				  &client_data.indebtedness,
				  &client_data.credit_limit,
				  &client_data.cash_payments) != -1)
	{
		while (fscanf(ofPTR_2, "%d %lf", &transfer.Number, &transfer.cash_payments) != -1)
		{ //  Функция fprintf выполняет форматированный вывод в поток.
			if (client_data.Number == transfer.Number && transfer.cash_payments != 0)
			{
				client_data.credit_limit += transfer.cash_payments;
			}
		}
		fprintf(blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
				client_data.Number,
				client_data.Name,
				client_data.Surname,
				client_data.addres,
				client_data.TelNumber,
				client_data.indebtedness,
				client_data.credit_limit,
				client_data.cash_payments);
		rewind(ofPTR_2);
	}
}