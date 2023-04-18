/*en este programa imprimimos la informacion de grupo del proceso*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
	int pid;
	pid = fork();
	printf("Aqui tenemos grupo de procesos");
	if (pid==0) {
		//sleep(1);
		printf("\n[H] MiPadre= %5d     Yo= %5d\n",
		getppid(), getpid());
	} else {
	printf("\n[P] MiPadre= %5d   Yo= %5d   MiHijo= %5d\n",
	getppid(), getpid(), pid);//esta funcion devuelve el id del grupo
	//del proceso actual
	}
	return 0;
}
