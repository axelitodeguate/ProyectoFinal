#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct nodo {
	int dato;
	struct nodo* siguiente;
	struct nodo* anterior;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

//-----------DECLARACIONES---------------------
void insertarNodoInicio();
void insertarNodoFinal();
void insertarNodoSegundo();
void insertarNodoPenultimo();
void borrarPrimero();
void borrarSegundo();
void borrarUltimo();
void borrarMayor();
void mostrar();
int main();
//------------------------------------------------

//-------------------FUNCIONES--------------------

void insertarNodoInicio() {
	nodo* nuevo = new nodo();
	printf("\nIngrese el dato que desea guardar: ");
	scanf("%d", &nuevo->dato);
	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}
	else {
		primero->anterior = nuevo;
		nuevo->siguiente = primero;
		nuevo->anterior = NULL;
		primero = nuevo;
	}
	printf("\nDato ingresado con exito!");
	_getch();
	main();

}

void insertarNodoFinal() {
	nodo* nuevo = new nodo();
	printf("\nIngrese el dato que desea guardar: ");
	scanf("%d", &nuevo->dato);
	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = ultimo;
		ultimo = nuevo;
	}
	printf("\nDato ingresado con exito!");
	_getch();
	main();
}

void insertarNodoSegundo() {
	nodo* nuevo = new nodo();
	nodo* tercero = new nodo();

	while (primero != NULL) {
		while (primero->siguiente != NULL) {
			printf("\nIngrese el dato que desea guardar: ");
			scanf("%d", &nuevo->dato);
			tercero = primero->siguiente;
			primero->siguiente = nuevo;
			nuevo->siguiente = tercero;
			nuevo->anterior = primero;
			printf("\nDato ingresado con exito!");
			_getch();
			main();
		}
		//SI SOLO HAY UN ELEMENTO
		insertarNodoFinal();
	} 
	//SI NO HAY ELEMENTOS
		printf("\nLa lista esta vacia, no se ingresara el dato!");
		_getch();
		main();
}

void insertarNodoPenultimo() {
	nodo* nuevo = new nodo();
	nodo* ap = new nodo();

	while (primero != NULL) {
		while (primero->siguiente != NULL) {
			printf("\nIngrese el dato que desea guardar: ");
			scanf("%d", &nuevo->dato);
			ap = ultimo->anterior;
			ap->siguiente = nuevo;
			nuevo->siguiente = ultimo;
			nuevo->anterior = ap;
			ultimo->anterior = nuevo;

			printf("\nDato ingresado con exito!");
			_getch();
			main();
		}
		//SI SOLO HAY UN ELEMENTO
		insertarNodoInicio();
	}
		//SI NO HAY ELEMENTOS
	printf("\nLa lista esta vacia, no se ingresara el dato!");
	_getch();
	main();
}

void borrarPrimero() {
	//SI NO HAY ELEMENTOS
	if (primero ==NULL)
	{
		printf("\nLa lista esta vacia, no hay datos que eliminar!");
	}
	//SI HAY SOLO 1 ELEMENTO
	else if (primero->siguiente == NULL) {
		primero = NULL;
		printf("\nNODO ELIMINADO");
	}
	//SI HAY MAS DE UN ELEMENTO
	else {
		primero = primero->siguiente;
		primero->anterior = NULL;
		printf("\nNODO ELIMINADO");
	}
	_getch();
	main();
}

void borrarSegundo() {

	//SI NO HAY ELEMENTOS
	if (primero == NULL)
	{
		printf("\nLa lista esta vacia, no hay datos que eliminar!");
	}
	//SI HAY SOLO 1 ELEMENTO
	else if (primero->siguiente == NULL) {
		printf("\nSOLO HAY UN NODO");
	}
	//SI HAY 2 ELEMENTOS
	else if (primero ->siguiente == ultimo){
		borrarUltimo();
	}
	//SI HAY 3 ELEMENTOS
	else if(primero->siguiente->siguiente == ultimo){

		primero->siguiente = ultimo;
		ultimo->anterior = primero;
		printf("\nprimero-> %d\n", primero->dato);
		printf("ultimo-> %d\n", ultimo->dato);
		printf("\nNODO ELIMINADO");
	}
	//SI HAY MAS DE 3 ELEMENTOS
	else {
		nodo* segundo = new nodo();
		segundo = primero->siguiente;
		primero->siguiente = segundo->siguiente;
		segundo->anterior = primero;
		printf("\nNODO ELIMINADO");
	}
	_getch();
	main();
}

void borrarUltimo() {
	//SI NO HAY ELEMENTOS
	if (primero == NULL)
	{
		printf("\nLa lista esta vacia, no hay datos que eliminar!");
	}
	//SI HAY SOLO 1 ELEMENTO
	else if (primero->siguiente == NULL) {
		primero = NULL;
		printf("\nNODO ELIMINADO");
	}
	//SI HAY MAS DE UN ELEMENTO
	else {
		ultimo = ultimo->anterior;
		ultimo->siguiente = NULL;
		printf("\nNODO ELIMINADO");
	}
	_getch();
	main();
}

void borrarMayor() {
	//SI NO HAY ELEMENTOS
	if (primero == NULL)
	{
		printf("\nLa lista esta vacia, no hay datos que eliminar!");
		_getch();
		main();
	}
	//SI HAY SOLO 1 ELEMENTO
	else if (primero->siguiente == NULL) {
		primero = NULL;
		printf("\nNODO ELIMINADO");
		_getch();
		main();
	}
	//SI HAY MAS DE UN ELEMENTO
	else {
		nodo* actual = new nodo();
		nodo* mayor = new nodo();
		mayor = actual;
		actual = primero;
		if (primero != NULL) {
			while (actual != NULL) {
				if (mayor<actual )
				{
					mayor = actual;
				}
				actual = actual->siguiente;
			}
			printf("el mayor es-> %d\n", mayor->dato);
			printf("\nprimero-> %d\n", primero->dato);
			printf("ultimo-> %d\n", ultimo->dato);
			_getch();
			main();
		}
		else {
			printf("\nLa lista esta vacia, ingrese datos primero!");
			_getch();
			main();
			printf("\nNODO ELIMINADO");
		}
		_getch();
		main();
	}
}

void mostrar() {
	nodo* actual = new nodo();
		actual = primero;
		if (primero != NULL) {
			while (actual != NULL) {
				printf(" %d ", actual->dato);
				actual = actual->siguiente;
			}
			printf("\nprimero-> %d\n", primero->dato);
			printf("ultimo-> %d\n", ultimo->dato);
			_getch();
			main();
		}else {
			printf("\nLa lista esta vacia, ingrese datos primero!");
			_getch();
			main();
		}
}
//---------------------------------------------

//---------------MAIN------------------------------
int main() {
	system("cls");
	int seleccion;
	printf("***************MENU PRINCIPAL***************\n");
	printf("*                                          *\n");
	printf("*    1. INSERTAR AL INICIO                 *\n");
	printf("*    2. INSERTAR AL FINAL                  *\n");
	printf("*    3. INSERTAR EN SEGUNDA POSICION       *\n");
	printf("*    4. INSERTAR EN PENULTIMA POSICION     *\n");
	printf("*    5. BORRAR EL PRIMER ELEMENTO          *\n");
	printf("*    6. BORRAR EL SEGUNDO ELEMENTO         *\n");
	printf("*    7. BORRAR EL ULTIMO ELEMENTO          *\n");
	printf("*    8. BORRAR EL ELEMENTO MAYOR           *\n");
	printf("*    9. MOSTRAR LISTA                      *\n");
	printf("*    0. SALIR                              *\n");
	printf("*                                          *\n");
	printf("********************************************\n\n");
	printf("SELECCION-----> ");

	cin>>seleccion;
	while (seleccion != 0) {
		switch (seleccion) {
		case 1:
			insertarNodoInicio();
			break;

		case 2:
			insertarNodoFinal();
			break;

		case 3:
			insertarNodoSegundo();
			break;

		case 4:
			insertarNodoPenultimo();
			break;

		case 5:
			borrarPrimero();
			break;

		case 6:
			borrarSegundo();
			break;

		case 7:
			borrarUltimo();
			break;

		case 8:
			borrarMayor();
			break;

		case 9:
			mostrar();
			break;

		default:
			printf("\nSELECCION NO VALIDA\n\n");
			_getch();
			main();
		}
	}

	return 0;
}