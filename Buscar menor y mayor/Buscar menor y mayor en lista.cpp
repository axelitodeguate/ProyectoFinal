#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct arbol
{
	int dato;
	arbol *i, *d;
}*elemento, *aux, *cabecera, *ant, *aux2, *ant2;

int dato;

int buscar(void);
void insertar(void);
void buscarmenmay(void);
void buscarmaymen(void);
void eliminar(void);

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}



int buscar(void)
{
	if (!cabecera)
	{
		cout << "No hay arbol";
		return(0);
	}
	ant = NULL;
	aux = cabecera;
	while (aux)
	{
		if (dato == aux->dato)
			return(1);
		else
		{
			ant = aux;
			if (dato>aux->dato)
				aux = aux->d;
			else
				aux = aux->i;
		}
	}
	return(0);
}

void insertar(void)
{
	if (!cabecera)
	{
		cabecera = new(arbol);
		cabecera->dato = dato;
		cabecera->d = NULL;
		cabecera->i = NULL;
		return;
	}
	if (!buscar())
	{
		aux = new(arbol);
		aux->dato = dato;
		aux->i = NULL;
		aux->d = NULL;
		if (dato>ant->dato)
			ant->d = aux;
		else
			ant->i = aux;
	}
	else
		cout << "\n\nDato existente";
}

void buscarmenmay(void)
{
	aux2 = aux->d;
	ant2 = aux;
	while (aux2->i)
	{
		ant2 = aux2;
		aux2 = aux2->i;
	}
	aux->dato = aux2->dato;
	if (aux2->d)
		ant2->i = aux2->d;
	delete(aux2);
	ant2->d = NULL;
}

void buscarmaymen(void)
{
	aux2 = aux->i;
	ant2 = aux;
	while (aux2->d)
	{
		ant2 = aux2;
		aux2 = aux2->d;
	}
	aux->dato = aux2->dato;
	if (aux2->i)
		ant2->d = aux2->i;
	delete(aux2);
	ant2->i = NULL;
}

void eliminar(void)
{
	if (!buscar())
	{
		cout << "\n\nElemento no encontrado.";
		return;
	}
	if (aux->d == NULL && aux->i == NULL)
	{
		if (ant->dato>dato)
			ant->i = NULL;
		else
			ant->d = NULL;
		delete(aux);
	}
	else
	if (aux->d != NULL)
		buscarmenmay();
	else
		buscarmaymen();
	cout << "\n\nElemento Borrado";
}

void main(void)
{
	int y, opc;
	do
	{
		system("cls");
		y = 10;
		gotoxy(10, y++);
		cout << "0 - Salir";
		gotoxy(10, y++);
		cout << "1 - Buscar";
		gotoxy(10, y++);
		cout << "2 - Insertar";
		gotoxy(10, y);
		cout << "3 - Borrar";
		gotoxy(10, y += 5);
		cout << "Cual es su opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 0: break;
		case 1: cout << "\n\nDato a buscar: ";
			cin >> dato;
			if (buscar())
				cout << "\n\nDato existe";
			else
				cout << "\n\nDato inexistente";
			break;
		case 2: cout << "\n\nDato a insertar: ";
			cin >> dato;
			insertar();
			cout << "\n\nDato Insertado";
			break;
		case 3: cout << "\n\nDato a borrar: ";
			cin >> dato;
			eliminar();
			break;
		default: cout << "\n\nOpcion incorrecta";
		}
		if (opc) _getch();
	} while (opc);
}