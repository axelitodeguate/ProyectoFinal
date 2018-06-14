#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

struct nodo {
	int dato;
	struct nodo *izq, *der;
};

typedef struct nodo *aux;


aux crearNodo(int x)
{
	aux nuevoNodo = new(struct nodo);
	nuevoNodo->dato = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;

	return nuevoNodo;
}

aux reubicar(aux izq, aux der)
{
	if (izq == NULL) return der;
	if (der == NULL) return izq;

	aux centro = reubicar(izq->der, der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}

void elimina(aux &arbol, int x)
{
	if (arbol == NULL) return;

	if (x<arbol->dato)
		elimina(arbol->izq, x);
	else if (x>arbol->dato)
		elimina(arbol->der, x);

	else
	{
		aux borrar = arbol;
		arbol = reubicar(arbol->izq, arbol->der);
		delete  borrar;
	}
}
void insertarNodo(nodo *& arbol, int n) {

	if (arbol == NULL) {
		nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
		printf("Nodo creado");
	}
	else {
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) {
			insertarNodo(arbol->izq, n);
			printf("Nodo creado");
		}
		else {
			insertarNodo(arbol->der, n);
			printf("Nodo creado");
		}
	}
}


void mostrarArbol(nodo *arbol, int cont) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);

	}
}
void busqueda(nodo *arbol, int cont, int num) {


	bool numero = false, encon = false;


	if (arbol == NULL) {
		return;
	}
	else {


		busqueda(arbol->der, cont + 1, num);


		if (arbol->dato == num) {
			cout << "numero  encontrado " << endl;
			numero = true;
		}

		busqueda(arbol->izq, cont + 1, num);

	}

	if (arbol == NULL)
	{
		if (numero == false) {


			cout << "Numeor no encontrado";
		}
	}
}
void menu() {

	int opc,num;
	aux arbol = NULL; 

	int n=0; 
	int x; 



	do {
		system("cls");
		cout << "----------Menu---------\n\n";
		cout << " 1. Insertar" << endl;
		cout << " 2. Eliminar" << endl;
		cout << " 3. mostrar" << endl;
		cout << " 4. Buscar." << endl;
		cout << " 5. Salir." << endl;
		cout << "\n Ingrese opcion: ";
		cin >> opc;
		switch (opc)
		{
			system("cls");

		case 1:
			system("cls");
			cout << "Valor para nodo: ";
			cin >> x;
			insertarNodo(arbol, x);
			break;

		case 3:
			cout << "Mostrando el arbol completo" << endl << endl;
			mostrarArbol(arbol,n);
			cout << "\n";
			system("pause");
			break;


		case 2:
			system("cls");

			cout << " Valor a eliminar: "; cin >> x;
			elimina(arbol, x);
			cout << "\n\tEliminado\n";

			system("pause");
			break;
		case 4:
			system("cls");
			cout << "\nBusqueda de nodo";
			cout << "Ingrese un numero a buscar:";
			cin >> num;
			busqueda(arbol,n, num);
			cout << "\n\n";

			system("pause");
			break;
		default: "opcion invalida";
			break;
		}
	} while (opc != 5);
}



int main()
{
	menu();
	system("pause");
	return 0;
}