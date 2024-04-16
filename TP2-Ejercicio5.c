//3. Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cantNombres 5
#define longitudMax 50

void cargarNombres(char **vector,int cantidad, char buffer[longitudMax]); 
void mostrarNombres(char **vector, int cantidad, char buffer[longitudMax]);
void liberoMemoria(char **vector, int cantidad);

int main(){
    int cantidad;
    printf("\nCANTIDAD DE NOMBRES QUE VA A INGRESAR: ");
    scanf("%d",&cantidad);  
    char **vector = (char **)malloc(cantidad * sizeof(char *)); //reservo memoria dinamica. doble puntero
    char buffer[longitudMax]; 

    if(vector == NULL){
        printf("Error al asignar memoria\n"); 
        return 1; 
    }

    cargarNombres(vector,cantidad,buffer); 
    mostrarNombres(vector,cantidad,buffer); 
    liberoMemoria(vector,cantidad); 

    free(vector); 

    return 0; 
}

void cargarNombres(char **vector, int cantidad, char buffer[longitudMax]){
    fflush(stdin);
    for(int i=0; i<cantidad; i++){
        printf("INGRESE NOMBRE[%d]: ",i+1); 
        gets(buffer);

        //reserva de memoria para el nombre y copio contenido
        vector[i] =(char *)malloc((strlen(buffer) + 1) * sizeof(char)); 
        strcpy(vector[i], buffer);  
    }
}

void mostrarNombres(char **vector, int cantidad, char buffer[longitudMax]){
    for(int i=0; i<cantidad; i++){
        printf("%d: %s \n", i+1, vector[i]); 
    }
}

void liberoMemoria(char **vector, int cantidad){
    for(int i=0; i<cantidad; i++){
        free(vector[i]); 
    }
}