#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include<stdio.h>
using namespace std;
/*Valter Oliva
  Javier Aguirre
  Axel carrera
*/
struct nodo
{
	int dato;
	nodo *d;
	nodo *i;
};

void insertarnodo(nodo *&, int a);
nodo *arbol = NULL;
void mostrararbol(nodo *, int a,int b);

int main()
{
	int dato, opc, cont = 0,cont2=0;

	do {
		cout << "*************Menu*************" << endl;
		cout << "1.Insertar" << endl;
		cout << "2.Mostrar" << endl;
		cout << "3.Salir" << endl;
		cout << "Escoja su opcion: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese Un Numero:"<<endl;
			cin >> dato;
			insertarnodo(arbol, dato);
			system("pause");
			break;
		case 2:
			mostrararbol(arbol, cont,cont2);
			cout << "\n";
			system("pause");
			break;
		default:
			cout << "Numero no valido";
			system("pause");
		}
		system("cls");
	} while (opc != 3);
	system("pause");
	return 0;
}
void insertarnodo(nodo *&arbol, int a)
{
	int raiz;
	if (arbol == NULL)
	{
		nodo *n_nodo = new nodo();

		n_nodo->dato = a;
		n_nodo->d = NULL;
		n_nodo->i = NULL;
		nodo *nuevo_nodo = n_nodo;
		arbol = nuevo_nodo;
	}
	else
	{
		raiz = arbol->dato;
		if (a < raiz)
		{
			insertarnodo(arbol->i, a);
		}
		else
		{
			insertarnodo(arbol->d, a);
		}
	}
}

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hcon, dwpos);
}

void mostrararbol(nodo *arbol, int cont,int cont2)
{
	if (arbol == NULL)
	{
		cout << " " << endl;
	}
	else
	{
		mostrararbol(arbol->d, cont + 1,cont2+1);
		
			cout << "  ";
		
			gotoxy(25-cont2, 9+cont);cout << arbol->dato << endl;
		mostrararbol(arbol->i, cont + 1,cont2 -1);

	}
}