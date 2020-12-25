/* подключение необходимых библиотек */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int File;



void SignalTransmission(int n)
{
	char EndByte, * SignalName;

	if (n != SIGUSR1 && n != SIGALRM)
		return;

	EndByte = n == SIGUSR1 ? '\0' : '\n'; /* \0 - байт null, завершение строки. \n - новая строка */
	SignalName = n == SIGUSR1 ? (char*)"SIGUSR1" : (char*)"SIGALRM";
	printf("%csignal: %s\n", EndByte, SignalName);
	printf("\nFile content:\n");  /* вывод содержимого файла */
	while (read(File, &EndByte, 1) == 1)
	{
	write(1, &EndByte, 1);
	
	}
	printf("\n");
	lseek(File, 0, SEEK_SET); /* функция, устанавливающая указатель положения в файле*/
	kill(getppid(), SIGUSR1);
}

void CloseFile()
{
	close(File);
	exit(0);
}
int main(int arguments)
{
	char Filename[10], Buf; /* Filename - название текстового файла */
	int i = 0, Bytes, Sek, Pid, Read; /* Bytes - кол-во байт, Sek - время ожидания (в секундах), Pid - идентификатор процесса */
	printf("File name: ");  /* указать имя файла */
	scanf("%s", &Filename);
	printf("set number of Bytes: "); /* указать количество байтов для записи */
	scanf("%d", &Bytes);
	printf("set seconds: "); /* указать время ожидания в секундах*/
	scanf("%d", &Sek);
	
	/* открытие файла с именем, указанным в Filename */
	
	File = open(Filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

	Pid = fork(); /* у исходного процесса создаётся потомок-двойник в идентичном состоянии */
	
	/* опираясь на значение, возвращаемое fork(), один процесс идет в 0 а второй в default */
	
	switch(Pid) {
		case -1:
		/* ощибка создания потомка-двойника */
		perror("fork failed!");
		exit(1);
		case 0:
		/* дочерний процесс*/
		signal(SIGUSR1, SignalTransmission);
		signal(SIGALRM, SignalTransmission); /*сигнал, генерируемый таймером, который установлен функцией alarm() */
		alarm(Sek);  /* функция alarm() для установки таймера */
		pause();
		default:
		/* родительский процесс */
		signal(SIGUSR1, CloseFile);
		do {
			Read = read(0, &Buf, 1);
			if (Buf == '\r' || Buf == '\n' || Read <= 0)
				break;
			if (i < Bytes) {  /* запись только указанного количества байт. все, на что не хватает байт - не записывается */
				write(File, &Buf, 1);
				i++;
			}
		} 
		while (Read > 0);
		lseek(File, 0, SEEK_SET);
		kill(Pid, SIGUSR1);
	}
	
	return(0);
}