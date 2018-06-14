#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windowsx.h>

/**\
using namespace std;

typedef struct dobleenlazada {
	int num;
	struct dobleenlazada *siguiente;
	struct dobleenlazada *anterior;
}dobleen;


typedef struct simple1
{
	int num;
	struct simple1 *siguiente;

}simple11;

typedef struct simple2
{
	int num;
	struct simple2 *siguiente;
}simple22;


dobleen *inicio, *final, *recorrido;
simple11 *recorrido2;
simple22 *recorrido3;
dobleen *nuevo;
simple11 *inicio2, *final2, *nuevo2;
simple22 *inicio3, *final3, *nuevo3;


void ingresarsimple1()
{
	system("cls");
	nuevo2 = (simple11 *)malloc(sizeof(simple11));
	nuevo2->num = nuevo->num;
	if (inicio2 == NULL)
	{
		inicio2 = nuevo2;
		final2 = nuevo2;
	}
	else
	{
		final2->siguiente = nuevo2;
		final2 = nuevo2;
		final2->siguiente = NULL;
	}

}

void ingresarsimple2()
{
	system("cls");
	simple22 *aux;
	nuevo3 = (simple22 *)malloc(sizeof(simple22));
	nuevo3->num = nuevo->num;
	nuevo3->siguiente = final3;

	if (inicio3 == NULL)
	{
		inicio3 = nuevo3;
		final3 = nuevo3;
	}
	else
	{
		aux = inicio3;
		inicio3 = nuevo3;
		inicio3->siguiente = aux;
	}
}


void ingresardoble()
{
	system("cls");
	nuevo = (dobleen *)malloc(sizeof(dobleen));
	if (nuevo == NULL)
	{
		cout << "No Hay Espacio En Memoria Para Crear Mas Nodos";
	}
	else
	{
		cout << "Ingresp de Datos";
		cout << "\nIngrese un numero\n";
		cin >> nuevo->num;

		ingresarsimple1();
		ingresarsimple2();

		nuevo->siguiente = NULL;
		if (inicio == NULL)
		{
			inicio = nuevo;
			final = nuevo;
		}
		else
		{
			final->siguiente = nuevo;
			final = nuevo;
			final->siguiente = NULL;
		}

	}
}


void medio(int a) {
	system("cls");
	int ant;
	nuevo = (dobleen *)malloc(sizeof(dobleen));
	if (nuevo == NULL)
		cout << "Memoria llena";
	else {

		cout << " un numero nuevo:"<<endl;
		cin >> nuevo->num;
		cout << "Ingrese posicion:";
		cin >> ant;
		recorrido = inicio;
		for (int i = 1;i < ant;i++) {
			recorrido = recorrido->siguiente;
			aux = recorrido;
			recorrido = recorrido->siguiente;
			if (inicio == NULL) {
				inicio = nuevo;
				final = nuevo;
			}
			else {
				aux->siguiente = nuevo;
				nuevo->anterior = aux;
				nuevo->siguiente = recorrido;
				recorrido->anterior = nuevo;
			}
		}
	}

	_getch();
}
void mostrar()
{
	system("cls");
	recorrido = inicio;
	cout << "	Lista Doblemente Enlazada";
	while (recorrido != NULL)
	{
		cout << recorrido->num << "\n";
		recorrido = recorrido->siguiente;
		_getch();
	}
}

void mostrarsimple1()
{
	system("cls");
	recorrido2 = inicio2;
	cout << "Lista Simple";
	while (recorrido2 != NULL)
	{
		cout << recorrido->num << "\n";
		recorrido2 = recorrido2->siguiente;
		_getch();
	}
}

void mostrarsimple2()
{
	recorrido3 = inicio3;
	cout << "Lista Simple 2";
	while (recorrido3 != NULL)
	{
		cout << recorrido3->num << "\n";
		recorrido3 = recorrido3->siguiente;
	}
	_getch();
}void main()
{
	int opcion = 0;
	while (opcion != 5)

	{
		system("cls");
		cout << "1. Ingresar Datos\n";
		cout << "2. Mostrar Lista Doblemente Enlazada" << endl;
		cout << "3. Mostrar lista Simple 1" << endl;
		cout << "4. Mostrar lista Simple 2" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una Opcion ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			ingresardoble();
			break;

		case 2:
			mostrar();
			break;

		case 3:
			mostrarsimple1();
			break;

		case 4:
			mostrarsimple2();
			break;

		case 5:
			break;

		default:
			cout << "No es una opcion correcta";
			system("pause");
			break;
		}
	}
}