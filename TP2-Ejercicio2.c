#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

int numeroAleatorio(int min, int max);
void cargarMatriz(int matriz[FILAS][COLUMNAS]); 
void mostrarMatriz(int matriz[FILAS][COLUMNAS]);
void promedioGanancias(int matriz[FILAS][COLUMNAS]);
void maximoMinimo(int matriz[FILAS][COLUMNAS]);


int main(){
    srand(time(NULL)); 
    int matriz[FILAS][COLUMNAS];

    cargarMatriz(matriz); 
    mostrarMatriz(matriz); 
    promedioGanancias(matriz); 
    maximoMinimo(matriz); 

    return 0;
}

int numeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

void cargarMatriz(int matriz[FILAS][COLUMNAS]){
    for(int i=0; i < FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            matriz[i][j] = numeroAleatorio(10000, 50000); 
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS]){
    printf("Matriz cargada: \n"); 
    for(int i=0; i < FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            printf("[%d]",matriz[i][j]); 
        }
        printf("\n"); 
    }
}

void promedioGanancias(int matriz[FILAS][COLUMNAS]){ 
    float promedio = 0; 
    float suma = 0;
    printf("\nPROMEDIO DE GANANCIA POR ANIO\n");  
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            suma += matriz[i][j];  
        }
        promedio = (suma/COLUMNAS); 
        printf("Anio %d: %.2f\n",i+1,promedio); 
    }
}

void maximoMinimo(int matriz[FILAS][COLUMNAS]){
    int max = 0; 
    int min = 50000; 
    int mesMayor, mesMenor, anioMenor, anioMayor;
    int aux = 0; 
    
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            if(matriz[i][j]>max){
                max = matriz[i][j]; 
                mesMayor = j+1; 
                anioMayor= i+1; 
            }
            if(matriz[i][j]<min){
                min = matriz[i][j]; 
                mesMenor = j+1; 
                anioMenor = i+1; 
            }
        }
    }
    printf("\n"); 
    printf("EL VALOR MINIMO ES: %d anio: %d mes: %d\n",min,anioMenor,mesMenor);
    printf("EL VALOR MAXIMO ES: %d anio: %d mes: %d\n",max,anioMayor,mesMayor);
    
}