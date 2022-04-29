/**********************************************************

* AUTOR : TheLuigy

* CORREO: theluigy13etv@gmail.com

* CANAL : Algoritmos y Algo m�s

* FECHA : 02/01/2016

**********************************************************/
#include <iostream>
#include <stdio.h>	/* print, scanf */
#include <string.h>
#include <stdlib.h>	/* system */
#include <locale.h> /* setlocale */

#define MAX 80

#define VALOR_CENTINELA -1
using namespace std;
/* Estructuras */

struct producto {
	
	int codigo;
	
	char nombre[MAX];
	
	float costo;
	
	float precio;
	
	int cantidad;
	
};



typedef struct producto Producto;



/* Opciones del Men� */

void menuPrincipal();

void menuInsertar();

void menuBuscar();

void menuEliminar();

void menuMostrar();

void menuModificar();

void menuEliminarFisica();



/* Funciones para manejar el archivo directamente */

Producto *obtenerProductos(int *n); /* Obtiene un vector din�mico de productos */

char existeProducto(int codigoProducto, Producto *producto); /* Busca si existe el producto en el archivo de productos */

char insertarProducto(Producto producto); /* Inserta el producto al final del archivo */

char eliminarProducto(int codigoProducto); /* Eliminar el producto de c�digo codigoProducto del archivo */

char eliminacionFisica(); /* Realiza la eliminaci�n f�sica de registros inv�lidos del archivo de productos */

char modificarProducto(Producto producto); /* Modifica el producto en el archivo */

char guardarReporte(); /* Genera un archivo TXT con el reporte de los productos */



/* Funci�n de lectura de cadenas */

int leecad(char *cad, int n);



/* Titular del programa */

void tituloPrincipal();



char linea[MAX];



int main()
{
	setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
	menuPrincipal();
	return 0;	
}



void menuPrincipal()
	
{
	
	char repite = 1;
	
	int opcion = -1;
	
	/* Cuando el usuario ingresa texto en lugar de ingresar una opci�n. El programa no modifica
	
	el valor de opcion. En ese caso, no se debe de ingresar a ninguno de los case, por eso se est�
	
	inicializando la variable opcion con un valor que no permita ejecutar ning�n case. Simplemente,
	
	volver a interar y pedir nuevamente la opci�n. */
	
	
	
	do {
		
		system("cls");
		
		
		
		tituloPrincipal();
		
		
		
		printf("\n\t\t\t\tMENU PRINCIPAL\n");
		
		printf("\n\t\t[1]. Insertar nuevo producto\n");
		
		printf("\t\t[2]. Mostrar listado de productos\n");
		
		printf("\t\t[3]. Eliminar un producto\n");
		
		printf("\t\t[4]. Buscar producto por clave\n");
		
		printf("\t\t[5]. Modificar un producto\n");
		
		printf("\t\t[6]. Eliminaci�n f�sica de registros\n");
		
		printf("\t\t[7]. Salir\n");
		
		printf("\n\t\tIngrese su opci�n: [ ]\b\b");
		
		
		
		/* Lectura segura de un entero */
		
		leecad(linea, MAX);
		
		sscanf(linea, "%d", &opcion);
		
		
		
		switch (opcion) {
			
			
			
		case 1:
			
			menuInsertar();
			
			break;
			
			
			
		case 2:
			
			menuMostrar();
			
			break;
			
			
			
		case 3:
			
			menuEliminar();
			
			break;
			
			
			
		case 4:
			
			menuBuscar();
			
			break;
			
			
			
		case 5:
			
			menuModificar();
			
			break;
			
			
			
		case 6:
			
			menuEliminarFisica();
			
			break;
			
			
			
		case 7:
			
			repite = 0;
			
			break;
			
		}
		
		
		
	} while (repite);
	
}



void menuInsertar()
	
{
	
	Producto producto;
	
	int codigoProducto = 0;
	
	char repite = 1;
	
	char respuesta[MAX];
	
	
	
	do {
		
		system("cls");
		
		tituloPrincipal();
		
		printf("\n\t\t\t==> INSERTAR PRODUCTO <==\n");
		
		
		
		/* Se pide el c�digo del producto a insertar */
		
		printf("\n\tC�digo de producto: ");
		
		leecad(linea, MAX);
		
		sscanf(linea, "%d", &codigoProducto);
		
		
		
		/* Se verifica que el producto no haya sido almacenado anteriormente */
		
		if (!existeProducto(codigoProducto, &producto)) {
			
			
			
			producto.codigo = codigoProducto;
			
			
			
			/* Se piden los dem�s datos del producto a insertar */
			
			printf("\tNombre del producto: ");
			
			leecad(producto.nombre, MAX);
			
			
			
			printf("\tCosto del producto ($): ");
			
			leecad(linea, MAX);
			
			sscanf(linea, "%f", &producto.costo);
			
			
			
			printf("\tPrecio del producto ($): ");
			
			leecad(linea, MAX);
			
			sscanf(linea, "%f", &producto.precio);
			
			
			
			printf("\tCantidad: ");
			
			leecad(linea, MAX);
			
			sscanf(linea, "%d", &producto.cantidad);
			
			
			
			/* Se inserta el producto en el archivo */
			
			if (insertarProducto(producto)) {
				
				printf("\n\tEl producto fue insertado correctamente\n");
				
				
				
			} else {
				
				printf("\n\tOcurri� un error al intentar insertar el producto\n");
				
				printf("\tInt�ntelo mas tarde\n");
				
			}
			
		} else {
			
			/* El producto ya existe, no puede ser insertado. */
			
			printf("\n\tEl producto de c�digo %d ya existe.\n", codigoProducto);
			
			printf("\tNo puede ingresar dos productos distintos con el mismo c�digo.\n");
			
		}
		
		
		
		printf("\n\tDesea seguir ingresando productos? [S/N]: ");
		
		leecad(respuesta, MAX);
		
		
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			
			repite = 0;
			
		}
		
		
		
	} while (repite);
	
}



void menuBuscar()
	
{
	
	Producto producto;
	
	int codigoProducto;
	
	char repite = 1;
	
	char respuesta[MAX];
	
	
	
	do {
		
		system("cls");
		
		tituloPrincipal();
		
		printf("\n\t\t\t==> BUSCAR PRODUCTO POR CODIGO <==\n");
		
		
		
		/* Se pide el c�digo del producto a buscar */
		
		printf("\n\tC�digo de producto: ");
		
		leecad(linea, MAX);
		
		sscanf(linea, "%d", &codigoProducto);
		
		
		
		/* Se verifica que el producto a buscar, exista */
		
		if (existeProducto(codigoProducto, &producto)) {
			
			
			
			/* Se muestran los datos del producto */
			
			printf("\n\tC�digo del producto: %d\n", producto.codigo);
			
			printf("\tNombre del producto: %s\n", producto.nombre);			
			
			printf("\tCosto del producto: %.1f $\n", producto.costo);
			
			printf("\tPrecio del producto: %.1f $\n", producto.precio);
			
			printf("\tCantidad: %d\n", producto.cantidad);
			
			
			
		} else {
			
			/* El producto no existe */
			
			printf("\n\tEl producto de c�digo %d no existe.\n", codigoProducto);
			
		}
		
		
		
		printf("\n\tDesea seguir buscando alg�n producto? [S/N]: ");
		
		leecad(respuesta, MAX);
		
		
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			
			repite = 0;
			
		}
		
		
		
	} while (repite);
	
}



void menuEliminar()
	
{
	
	Producto producto;
	
	int codigoProducto;
	
	char repite = 1;
	
	char respuesta[MAX];
	
	
	
	do {
		
		system("cls");
		
		tituloPrincipal();
		
		printf("\n\t\t\t==> ELIMINAR PRODUCTO POR CODIGO <==\n");
		
		
		
		/* Se pide el c�digo del producto a eliminar */
		
		printf("\n\tC�digo de producto: ");
		
		leecad(linea, MAX);
		
		sscanf(linea, "%d", &codigoProducto);
		
		
		
		/* Se verifica que el producto a buscar, exista */
		
		if (existeProducto(codigoProducto, &producto)) {
			
			
			
			/* Se muestran los datos del producto */
			
			printf("\n\tC�digo del producto: %d\n", producto.codigo);
			
			printf("\tNombre del producto: %s\n", producto.nombre);			
			
			printf("\tCosto del producto: %.1f $\n", producto.costo);
			
			printf("\tPrecio del producto: %.1f $\n", producto.precio);
			
			printf("\tCantidad: %d\n", producto.cantidad);
			
			
			
			printf("\n\tSeguro que desea eliminar el producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				if (eliminarProducto(codigoProducto)) {
					
					printf("\n\tProducto eliminado satisfactoriamente.\n");
					
				} else {
					
					printf("\n\tEl producto no pudo ser eliminado\n");
					
				}
				
			}
			
			
			
		} else {
			
			/* El producto no existe */
			
			printf("\n\tEl producto de c�digo %d no existe.\n", codigoProducto);
			
		}
		
		
		
		printf("\n\tDesea eliminar otro producto? [S/N]: ");
		
		leecad(respuesta, MAX);
		
		
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			
			repite = 0;
			
		}
		
		
		
	} while (repite);
	
}



void menuMostrar()
	
{
	
	Producto *productos;
	
	int numeroProductos;
	
	int i;
	
	float costoTotal;
	
	float precioTotal;
	
	int cantidadTotal;
	
	char respuesta[MAX];
	
	
	
	system("cls");
	
	tituloPrincipal();
	
	productos = obtenerProductos(&numeroProductos); /* Retorna un vector din�mico de productos */
	
	
	
	if (numeroProductos == 0) {
		
		printf("\n\tEl archivo est� vac�o!!\n");
		
		system("pause>nul");
		
		
		
	} else {
		
		printf("\n\t\t    ==> LISTADO DE PRODUCTOS REGISTRADOS <==\n");
		
		printf(" ------------------------------------------------------------------------------\n");
		
		printf("%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "COSTO $", "PRECIO $", "CANTIDAD");
		
		printf(" ------------------------------------------------------------------------------\n");
		
		
		
		/* Se recorre el vector din�mico de productos */
		
		costoTotal = 0;
		
		precioTotal = 0;
		
		cantidadTotal = 0;
		
		for (i = 0; i < numeroProductos; i++) {
			
			if (productos[i].codigo != VALOR_CENTINELA) {
				
				printf("%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].costo, productos[i].precio, productos[i].cantidad);
				
				costoTotal += productos[i].costo;
				
				precioTotal += productos[i].precio;
				
				cantidadTotal += productos[i].cantidad;
				
			}
			
		}
		
		printf(" ------------------------------------------------------------------------------\n");
		
		printf("\t\t\t      TOTAL: %15.1f%15.1f%8d\n", costoTotal, precioTotal, cantidadTotal);
		
		
		
		printf("\n\tDesea guardar el reporte en un archivo de texto? [S/N]: ");
		
		leecad(respuesta, MAX);
		
		
		
		if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			
			if (guardarReporte()) {
				
				printf("\n\tEl reporte fue guardado con �xito\n");
				
			} else {
				
				printf("\n\tOcurri� un error al guardar el reporte\n");
				
			}
			
			
			
			system("pause>nul");
			
		}
		
	}
	
}



void menuModificar()
	
{
	
	Producto producto;
	
	int codigoProducto;
	
	char repite = 1;
	
	char respuesta[MAX];
	
	
	
	do {
		
		system("cls");
		
		tituloPrincipal();
		
		printf("\n\t\t\t==> MODIFICAR PRODUCTO POR CODIGO <==\n");
		
		
		
		/* Se pide el c�digo del producto a modificar */
		
		printf("\n\tC�digo de producto: ");
		
		leecad(linea, MAX);
		
		sscanf(linea, "%d", &codigoProducto);
		
		
		
		/* Se verifica que el producto a buscar exista */
		
		if (existeProducto(codigoProducto, &producto)) {
			
			
			
			/* Se muestran los datos del producto */
			
			printf("\n\tNombre del producto: %s\n", producto.nombre);
			
			printf("\tCosto del producto ($): %.1f\n", producto.costo);
			
			printf("\tPrecio del producto ($): %.1f\n", producto.precio);
			
			printf("\tCantidad: %d\n", producto.cantidad);
			
			
			
			printf("\n\tElija los datos a modificar\n");
			
			
			
			/* Modificaci�n del nombre del producto */
			
			printf("\n\tNombre del producto actual: %s\n", producto.nombre);
			
			printf("\tDesea modificar el nombre del producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				printf("\tNuevo nombre del producto: ");
				
				leecad(producto.nombre, MAX);
				
			}
			
			
			
			/* Modificaci�n del costo del producto */
			
			printf("\n\tCosto del producto actual: %.1f\n", producto.costo);
			
			printf("\tDesea modificar el costo del producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				printf("\tNuevo costo del producto: ");
				
				leecad(linea, MAX);
				
				sscanf(linea, "%f", &producto.costo);
				
			}
			
			
			
			/* Modificaci�n del precio del producto */
			
			printf("\n\tPrecio del producto actual: %.1f\n", producto.precio);
			
			printf("\tDesea modificar el precio del producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				printf("\tNuevo precio del producto: ");
				
				leecad(linea, MAX);
				
				sscanf(linea, "%f", &producto.precio);
				
			}
			
			
			
			/* Modificaci�n de la cantidad del producto */
			
			printf("\n\tCantidad del producto actual: %d\n", producto.cantidad);
			
			printf("\tDesea modificar la cantidad del producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				printf("\tNueva cantidad del producto: ");
				
				leecad(linea, MAX);
				
				sscanf(linea, "%d", &producto.cantidad);
				
			}
			
			
			
			printf("\n\tEst� seguro que desea modificar los datos del producto? [S/N]: ");
			
			leecad(respuesta, MAX);
			
			
			
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				
				/* Se modifica el producto en el archivo */
				
				if (modificarProducto(producto)) {
					
					printf("\n\tEl producto fue modificado correctamente\n");
					
					
					
				} else {
					
					printf("\n\tOcurri� un error al intentar modificar el producto\n");
					
					printf("\tInt�ntelo mas tarde\n");
					
				}
				
			}
			
		} else {
			
			/* El producto no existe */
			
			printf("\n\tEl producto de c�digo %d no existe.\n", codigoProducto);
			
		}
		
		
		
		printf("\n\tDesea modificar alg�n otro producto? [S/N]: ");
		
		leecad(respuesta, MAX);
		
		
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			
			repite = 0;
			
		}
		
		
		
	} while (repite);
	
}



void menuEliminarFisica()
	
{
	
	char respuesta[MAX];
	
	
	
	
	
	system("cls");
	
	tituloPrincipal();
	
	printf("\n\t\t==> ELIMINAR FISICAMENTE REGISTROS DEL ARCHIVO <==\n");
	
	
	
	/* Se pide el c�digo del producto a eliminar */
	
	printf("\n\tSeguro que desea proceder con la eliminaci�n f�sica? [S/N]: ");
	
	leecad(respuesta, MAX);
	
	
	
	if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		
		if (eliminacionFisica()) {
			
			printf("\n\tLa eliminaci�n f�sica se realiz� con �xito.\n");
			
		} else {
			
			printf("\n\tOcurri� alg�n error en la eliminaci�n f�sica.\n");
			
		}
		
		
		
		system("pause>nul");
		
	}
	
}



Producto *obtenerProductos(int *n)
	
{
	
	FILE *archivo;
	
	Producto producto;
	
	Producto *productos; /* Vector din�mico de productos */
	
	int i;
	
	
	
	/* Abre el archivo en modo lectura */
	
	archivo = fopen("productos.dat", "rb");
	
	
	
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		
		*n = 0; /* No se pudo abrir. Se considera n  */
		
		productos = NULL;
		
		
		
	} else {
		
		
		
		fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
		
		*n = ftell(archivo) / sizeof(Producto); /* # de productos almacenados en el archivo. (# de registros) */
		
		productos = (Producto *)malloc((*n) * sizeof(Producto)); /* Se reserva memoria para todos los productos almacenados en el archivo */
		
		
		
		/* Se recorre el archivo secuencialmente */
		
		fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
		
		fread(&producto, sizeof(producto), 1, archivo);
		
		i = 0;
		
		while (!feof(archivo)) {
			
			productos[i++] = producto;
			
			fread(&producto, sizeof(producto), 1, archivo);
			
		}
		
		
		
		/* Cierra el archivo */
		
		fclose(archivo);
		
	}
	
	
	
	return productos;
	
}



char existeProducto(int codigoProducto, Producto *producto)
	
{
	
	FILE *archivo;
	
	char existe;
	
	
	
	/* Abre el archivo en modo lectura */
	
	archivo = fopen("productos.dat", "rb");
	
	
	
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		
		existe = 0;
		
		
		
	} else {
		
		existe = 0;
		
		
		
		/* Se busca el producto cuyo c�digo coincida con codigoProducto */
		
		fread(&(*producto), sizeof(*producto), 1, archivo);
		
		while (!feof(archivo)) {
			
			if ((*producto).codigo == codigoProducto) {
				
				existe = 1;
				
				break;
				
			}
			
			fread(&(*producto), sizeof(*producto), 1, archivo);
			
		}
		
		
		
		/* Cierra el archivo */
		
		fclose(archivo);
		
	}
	
	
	
	return existe;
	
}



char insertarProducto(Producto producto)
	
{
	
	FILE *archivo;
	
	char insercion;
	
	
	
	/* Abre el archivo para agregar datos al final */
	
	archivo = fopen("productos.dat", "ab");	/* A�ade datos al final. Si el archivo no existe, es creado */
	
	
	
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		
		insercion = 0;
		
		
		
	} else {
		
		fwrite(&producto, sizeof(producto), 1, archivo);
		
		insercion = 1;
		
		
		
		/* Cierra el archivo */
		
		fclose(archivo);
		
	}
	
	
	
	return insercion;
	
}



/* ELiminaci�n l�gica de un registro */

char eliminarProducto(int codigoProducto)
	
{
	
	FILE *archivo;
	
	FILE *auxiliar;
	
	Producto producto;
	
	char elimina;
	
	
	
	/* Abre el archivo para leer */
	
	archivo = fopen("productos.dat", "r+b");	/* Modo lectura/escritura. Si el archivo no existe, es creado */
	
	
	
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		
		elimina = 0;
		
		
		
	} else {
		
		/* Se busca el registro que se quiere borrar. Cuando se encuentra, se sit�a en esa posici�n mediante la 
		
		funci�n fseek y luego se modifica el campo clave de ese registro mediante alg�n valor centinela, eso se logra 
		
		con fwrite. Hasta all� se ha logrado una eliminaci�n L�GICA. Porque el registro sigue ocupando espacio en el archivo f�sico */
		
		
		
		elimina = 0;
		
		fread(&producto, sizeof(producto), 1, archivo);
		
		while (!feof(archivo)) {
			
			if (producto.codigo == codigoProducto) {
				
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				
				producto.codigo = VALOR_CENTINELA;
				
				fwrite(&producto, sizeof(producto), 1, archivo);
				
				elimina = 1;
				
				break;
				
			}
			
			fread(&producto, sizeof(producto), 1, archivo);
			
		}
		
		
		
		/* Cierra el archivo */
		
		fclose(archivo);
		
	}
	
	
	
	return elimina;
	
}



char eliminacionFisica()
	
{
	
	FILE *archivo;
	
	FILE *temporal;
	
	Producto producto;
	
	char elimina = 0;
	
	
	
	archivo = fopen("productos.dat", "rb");
	
	temporal = fopen("temporal.dat", "wb");
	
	
	
	if (archivo == NULL || temporal == NULL) {
		
		elimina = 0;
		
	} else {
		
		/* Se copia en el archivo temporal los registros v�lidos */
		
		fread(&producto, sizeof(producto), 1, archivo);
		
		while (!feof(archivo)) {
			
			if (producto.codigo != VALOR_CENTINELA) {
				
				fwrite(&producto, sizeof(producto), 1, temporal);
				
			}
			
			fread(&producto, sizeof(producto), 1, archivo);
			
		}
		
		/* Se cierran los archivos antes de borrar y renombrar */
		
		fclose(archivo);
		
		fclose(temporal);
		
		
		
		remove("productos.dat");
		
		rename("temporal.dat", "productos.dat");
		
		
		
		elimina = 1;
		
	}
	
	
	
	return elimina;
	
}



char modificarProducto(Producto producto)
	
{
	
	FILE *archivo;
	
	char modifica;
	
	Producto producto2;
	
	
	
	/* Abre el archivo para lectura/escritura */
	
	archivo = fopen("productos.dat", "rb+");
	
	
	
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		
		modifica = 0;
		
		
		
	} else {
		
		modifica = 0;
		
		fread(&producto2, sizeof(producto2), 1, archivo);
		
		while (!feof(archivo)) {
			
			if (producto2.codigo == producto.codigo) {
				
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				
				fwrite(&producto, sizeof(producto), 1, archivo);
				
				modifica = 1;
				
				break;
				
			}
			
			fread(&producto2, sizeof(producto2), 1, archivo);
			
		}
		
		
		
		fclose(archivo);
		
	}
	
	
	
	/* Cierra el archivo */
	
	return modifica;
	
}



char guardarReporte()
	
{
	
	FILE *archivo;
	
	char guardado;
	
	Producto *productos;
	
	int numeroProductos;
	
	int i;
	
	float costoTotal;
	
	float precioTotal;
	
	int cantidadTotal;
	
	
	
	productos = obtenerProductos(&numeroProductos); /* Retorna un vector din�mico de productos */
	
	
	
	if (numeroProductos == 0) {
		
		guardado = 0;
		
		
		
	} else {
		
		/* Abre el archivo en modo texto para escritura */
		
		archivo = fopen("reporte.txt", "w");
		
		
		
		if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
			
			guardado = 0;
			
			
			
		} else {
			
			fprintf(archivo, "\n\t\t    ==> LISTADO DE PRODUCTOS REGISTRADOS <==\n");
			
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			
			fprintf(archivo, "%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "COSTO $", "PRECIO $", "CANTIDAD");
			
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			
			
			
			/* Se recorre el vector din�mico de productos */
			
			costoTotal = 0;
			
			precioTotal = 0;
			
			cantidadTotal = 0;
			
			for (i = 0; i < numeroProductos; i++) {
				
				if (productos[i].codigo != VALOR_CENTINELA) {
					
					fprintf(archivo, "%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].costo, productos[i].precio, productos[i].cantidad);
					
					costoTotal += productos[i].costo;
					
					precioTotal += productos[i].precio;
					
					cantidadTotal += productos[i].cantidad;
					
				}
				
			}
			
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			
			fprintf(archivo, "\t\t\t      TOTAL: %15.1f%15.1f%8d", costoTotal, precioTotal, cantidadTotal);
			
			
			
			guardado = 1;
			
			
			
			/* Cierra el archivo */
			
			fclose(archivo);
			
		}
		
	}
	
	
	
	return guardado;
	
}



int leecad(char *cad, int n)
	
{
	
	int i, c;
	
	
	
	/* Hay que verificar si el buffer est� limpio o si hay un '\n'
	
	dejado por scanf y, en ese caso, limpiarlo:
	
	*/
	
	
	
	/* 1 COMPROBACI�N DE DATOS INICIALES EN EL BUFFER */
	
	
	
	/* Empezamos leyendo el primer caracter que haya en la entrada. Si es
	
	EOF, significa que no hay nada por leer, as� que cerramos la cadena,
	
	dej�ndola "vac�a" y salimos de la funci�n retornando un valor de 0
	
	o falso, para indicar que hubo un error */
	
	c = getchar();
	
	if (c == EOF) {
		
		cad[0] = '\0';
		
		return 0;
		
	}
	
	
	
	/* Si el valor le�do es '\n', significa que hab�a un caracter de nueva l�nea
	
	dejado por un scanf o funci�n similar. Simplemente inicializamos i a 0,
	
	para indicar que los siguientes caracteres que leamos iremos asignando a
	
	partir del primer caracter de la cadena. */
	
	if (c == '\n') {
		
		i = 0;
		
	} else {
		
		/* Si no hab�a un '\n', significa que el caracter que le�mos es el primer
		
		caracter de la cadena introducida. En este caso, lo guardamos en la
		
		posici�n 0 de cad, e inicializamos i a 1, porque en este caso, como ya
		
		tenemos el primer caracter de la cadena, continuaremos agregando 
		
		caracteres a partir del segundo.
		
		
		
		*/
		
		cad[0] = c;
		
		i = 1;
		
	}
	
	
	
	/* 2. LECTURA DE LA CADENA */
	
	
	
	/* El for empieza con un ; porque estamos omitiendo la inicializaci�n del contador,
	
	ya que fue inicializado en el punto anterior.
	
	Este c�digo lee un caracter a la vez,lo agrega a cad, y se repite hasta que
	
	se encuentre un fin de l�nea, fin de archivo, o haya le�do la cantidad m�xima
	
	de caracteres que se le indic�. Luego, cierra la cadena agregando un '\0'
	
	al final. Todo esto es muy similar a la forma en que los compiladores suelen
	
	implementar la funci�n fgets, s�lo que en lugar de getchar usan getc o fgetc
	
	*/
	
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		
		cad[i] = c;
		
	}
	
	cad[i] = '\0';
	
	
	
	/*3. LIMPIEZA DEL BUFFER */
	
	
	
	/* Finalmente limpiamos el buffer si es necesario */
	
	if (c != '\n' && c != EOF) /* es un caracter */
		
		while ((c = getchar()) != '\n' && c != EOF);
	
	
	
	/* La variable c contiene el �ltimo caracter le�do. Recordemos que hab�a 3 formas
	
	de salir del for: que hayamos encontrando un '\n', un EOF, o que hayamos llegado
	
	al m�ximo de caracteres que debemos leer. Si se da cualquiera de los dos
	
	primeros casos, significa que le�mos todo lo que hab�a en el buffer, por lo que
	
	no hay nada que limpiar. En el tercer caso, el usuario escribi� m�s caracteres
	
	de los debidos, que a�n est�n en el buffer, por lo que hay que quitarlos, para
	
	lo cual usamos el m�todo que vimos poco m�s arriba
	
	*/
	
	
	
	return 1;
	
}



void tituloPrincipal()
	
{
	
	int i;
	
	printf("\n     ======================================================================\n");
	
	printf("\t\t\t     OPERACIONES CON ARCHIVOS\n");
	
	printf("\t   Creaci�n, reportes, eliminaci�n, b�squeda y actualizaci�n\n");
	
	printf("\t\t    Copyright 2016 | Algoritmos y Algo m�s\n");
	
	printf("     ======================================================================\n");
	
	
	
	i = 0;
	
	putchar('\n');
	
	for (; i < 80; i++) {
		
		putchar('_');
		
	}
	
}
