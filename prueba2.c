#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void ejecutar_archivo(char* nombre_archivo, char* argumentos[]);

int main() {
    char input[100]; // Cadena para almacenar la entrada del usuario en un arreglo
    char* palabra; // palabra generado a partir de la entrada del usuario
    char* argumentos[10+1]; // Arreglo de argumentos para el archivo ejecutable guarda
    int i; // Contador para recorrer el arreglo de argumentos
    
    // Ciclo principal ejecutar comandos hasta que se ingrese "EXIT" en la terminal simulada 
    while (1) {
        // Imprimir prompt y obtener entrada del usuario
        printf("$");
        fgets(input, sizeof(input), stdin);//es para poder revcibir la entrada del usuario
        input[strlen(input)-1] = '\0'; // Remover el salto de línea al final 
        
        // Salir del ciclo si se ingresa "EXIT"
        if (strcmp(input, "EXIT") == 0) { //strcmp compara dos cadenas de caracteres y deveuelve 0 si son iguales 
            break;
        }
        
        // Pasar la entrada del usuario en nombre de archivo y argumentos
        i = 0;
        palabra = strtok(input, " ");//strtok  divide la cadena en palabras separadas
        while (palabra != NULL && i < 10) {
            argumentos[i] = palabra; //se guarda la palabra en argumentos 
            palabra = strtok(NULL, " ");
            i++;
        }
        argumentos[i] = NULL; // Agregar NULL al final del arreglo de argumentos
        
        // Ejecutar archivo con los argumentos correspondientes
        ejecutar_archivo(argumentos[0], argumentos+1); //el primer para,etro toma el nombre y el segundo los usamos para pasar un puntero a los argumentos
    }
    
    return 0;
}

// Función que ejecuta un archivo ejecutable dado su nombre y argumentos
void ejecutar_archivo(char* nombre_archivo, char* argumentos[]) {
    // Crear nuevo proceso
	int pid;
    pid = fork();
    if (pid == -1) {
        printf("Error al crear proceso\n");
        exit(EXIT_FAILURE);
    }
    // Proceso hijo: ejecutar archivo
    else if (pid == 0) {
        // Ejecutar archivo con los argumentos correspondientes
        execv(nombre_archivo, argumentos);
        // En caso de que execv falle, imprimir mensaje de error
        printf("Error al ejecutar archivo escribe un archivo valido\n");
        exit(EXIT_FAILURE);
    }
    // Proceso padre: esperar a que termine el proceso hijo
    else {
        int status;
        waitpid(pid, &status, 0);// esparamos a que  termine el proceso con waitpid
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {// Validar que el archivo se haya ejecutado correctamente ya que devuelve 0 si es correcto
            fprintf(stderr, "Error al ejecutar archivo %s\n", nombre_archivo);
        }
    }
}

