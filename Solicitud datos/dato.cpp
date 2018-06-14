#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include<iostream>
using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};
void ingreso(nodo *&, int);
void mostrar(nodo *&, int &);

int main() {
	nodo *pila = NULL;
	int opc;
	int dato;

	do {
		cout << "***************Menu**************" << endl;
		cout << "	1. Ingreso de dato"<<endl;
		cout << "	2. Mostrar datos"<<endl;
		cout << "	3. Salir"<<endl;
		cout << "	Ingrese opcion: "<<endl;
		cin >> opc;
		switch (opc) {
		case 1: system("cls");
				cout << "Ingrese dato:"<<endl;
				cin >> dato;
				ingreso(pila, dato);
			
				system("cls");
				main();

		case 2: system("cls");
			cout << "Mostrando datos son: \n";
			while (pila != NULL) {
				mostrar(pila, dato);

				if (pila != NULL) {
					cout << "El dato en la pila es: " << dato << "" << endl;
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
	} while (opc != 3);
}

		void ingreso(nodo *&pila, int n) {
			nodo *nuevo_nodo = new nodo();
			nuevo_nodo->dato = n;
			nuevo_nodo->sig = pila;
			pila = nuevo_nodo;
		}

		void mostrar(nodo *&pila, int &n) {
			nodo *aux = pila;
			n = aux->dato;
			pila = aux->sig;
			delete aux;

		}