#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};

struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    struct Producto *Productos;
};
float calcularCosto(struct Producto producto);
void cargarClientes(struct Cliente *clientes, int cantidadClientes);
void mostrarClientes(struct Cliente *clientes, int cantidadClientes);


int main() {
    srand(time(NULL));
    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    struct Cliente *clientes = (struct Cliente *)malloc(cantidadClientes * sizeof(struct Cliente));

    if (clientes == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    cargarClientes(clientes, cantidadClientes);
    mostrarClientes(clientes, cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

float calcularCosto(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}

void cargarClientes(struct Cliente *clientes, int cantidadClientes) {
    for (int i = 0; i < cantidadClientes; i++) {
        clientes[i].ClienteID = i + 1;
        char nombre[100];
        /*printf("\nIngrese el nombre del cliente %d: ", i + 1);
        scanf("%s", nombre);
        clientes[i].NombreCliente = strdup(nombre);*/
        fflush(stdin); 
        printf("\nINGRESE EL NOMBRE DEL CLIENTE[%d]: ", i + 1);
        gets(nombre); 
        clientes[i].NombreCliente = (char *)malloc((strlen(nombre) + 1) * sizeof(char)); 
        strcpy(clientes[i].NombreCliente, nombre);

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (struct Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10; // Entre 10 y 100
        }
    }
}

void mostrarClientes(struct Cliente *clientes, int cantidadClientes) {
    printf("///LISTA CLIENTES///\n"); 
    for (int i = 0; i < cantidadClientes; i++) {
        printf("\nCLIENTE %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        float totalAPagar = 0.0;
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            struct Producto producto = clientes[i].Productos[j];
            printf("Producto ID: %d, Tipo: %s, Cantidad: %d, Precio Unitario: $%.2f, Costo: $%.2f\n",
                   producto.ProductoID, producto.TipoProducto, producto.Cantidad, producto.PrecioUnitario,
                   calcularCosto(producto));
            totalAPagar += calcularCosto(producto);
        }
        printf("Total a pagar por cliente: $%.2f\n", totalAPagar);
    }
}
