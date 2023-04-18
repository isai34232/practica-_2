#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int pid,pis;
	pid=getuid();
	
	if (pid==0){
		printf("[proceso creado] ID=%d \n", getuid());
	}
	else{
		printf("[soy el Padre] ID=%d \n",getuid());
	}
	

	printf("Aqui el nuevo proceso= %d\n",getuid());

	return(0);
}