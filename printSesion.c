#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int pid,pis;
	pid=fork();
	
	if (pid==0){
		printf("[proceso creado] ID=%d \n", getsid(pid));
	}
	else{
		printf("[soy el Padre] ID=%d \n",getsid(pid));
	}
	
	//pis=getsid(pid);
	printf("Aqui el nuevo proceso= %d\n",getsid(pid));
	//printf("adios pid=%d\n",getpid());
	return(0);
}
