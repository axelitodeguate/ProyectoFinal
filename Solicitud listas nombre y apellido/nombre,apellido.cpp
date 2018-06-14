#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include<iostream>
using namespace std;

struct nodo {
	char nombre;
	char apelli;
	nodo *sig;
};
void ingreso(nodo *&, char,char);
void mostrar(nodo *&, char &,char&);

int main() {
	nodo *pila = NULL;
	int opc;
	char nombre, apell;

	do {
		cout << "***************Menu**************" << endl;
		cout << "	1. Ingreso de dato" << endl;
		cout << "	2. Mostrar datos" << endl;
		cout << "	3. Salir" << endl;
		cout << "	Ingrese opcion: " << endl;
		cin >> opc;
		switch (opc) {
		case 1: system("cls");
			cout << "Ingrese nombre:" << endl;
			cin >> nombre;
			cout << "Ingrese apellido:" << endl;
			cin >> apell;
			ingreso(pila, nombre,apell);

			system("cls");
			main();

		case 2: system("cls");
			cout << "Mostrando datos son: \n";
			while (pila != NULL) {
				mostrar(pila, nombre,apell);

				if (pila != NULL) {
					cout << "pila vacia"  << endl;
				}
				else {
					cout << "El dato en la pila es: " << dato << "" << endl;
				}
			}
			system("pause");

			main();
			system("pause");
			break;

		}system("cls");

		return 0;
	} while (opc != 3
}

void ingreso(nodo *&pila, char n,char m) {
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->nombre = n;
	nuevo_nodo->apelli = m;
	nuevo_nodo->sig = pila;
	pila = nuevo_nodo;
}

void mostrar(nodo *&pila, char &n,char &m) {
	nodo *aux = pila;
	nodo *aux2= pila;
	n = aux->nombre;
	n = aux->apelli;
	pila = aux->sig;
	pila = aux2->sig;
	delete aux;

}