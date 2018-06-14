#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void CrearClave(char clave[]);
void BuscarClave(Clave *&encabezado, char clave[], char ingrediente[]);
void MostrarTabla();
void MostrarDatos(Nodo *&encabezado);
void RegistrarDatos(Nodo *&encabezado, Nodo *&pie, char ingrediente[]);

struct Nodo {
	char unidades[60];
	Nodo *sig;
};

int main() {
	int opc = 0;
	int salida = 0;
	char curso[50];
	char unidades[50];

	while (opc != 4) {
		system("cls");
		cout << "\t1. Crear Curso" << endl;
		cout << "\t2. Insertar" << endl;
		cout << "\t3. Consultar curso y unidades" << endl;
		cout << "\t4. Salir" << endl;
		cin >> opc; cin.ignore();

		switch (opc) {

		case 1:
			system("cls");
			cout << endl;
			cout << "Ingrese el nombre del curso " << endl;
			gets_s(curso);
			CrearClave(curso);
			strcpy_s(curso, "");
			system("pause");
			break;

		case 2:
			system("cls");
			cout << endl;
			cout << "Ingrese el nombre del curso" << endl;
			gets_s(curso);

			while (salida != 1) {
				cout << "Ingrese unidades" << endl;
				gets_s(unidades);

				BuscarClave(cabeza, curso, unidades);
				strcpy_s(unidades, "");

				cout << "Desea Ingresar otra unidad? [SI = 0 | NO = 1]" << endl;
				cin >> salida; cin.ignore();
				cout << endl;
			}
			strcpy_s(curso, "");
			salida = 0;
			system("pause>null");
			break;

		case 3:
			system("cls");
			cout << "-> Curso<-" << endl;
			cout << endl;
			MostrarTabla();
			system("pause>null");
			break;
		}
	}
}

struct Clave {
	char nombre[50];
	Clave *sig;
	Nodo *cab;
	Nodo *pie;
}*cabeza, *fin;


void CrearClave(char clave[]) {
	Clave *nueva_clave = new Clave();
	strcpy_s(nueva_clave->nombre, clave);
	Clave *actual = new Clave();
	actual = cabeza;
	Clave *anterior = new Clave();

	if (cabeza == NULL) {
		cabeza = nueva_clave;
		nueva_clave->sig = NULL;
		fin = cabeza;
	}
	else {
		while (actual != NULL) {
			if (strcmp(clave, actual->nombre) < 0) {
				if (actual == cabeza) {
					nueva_clave->sig = cabeza;
					cabeza = nueva_clave;
					break;
				}
				else {
					anterior->sig = nueva_clave;
					nueva_clave->sig = actual;
					break;
				}
			}
			else if (strcmp(clave, actual->nombre) > 0){
				if (actual == fin) {
					fin->sig = nueva_clave;
					nueva_clave->sig = NULL;
					fin = nueva_clave;
					break;
				}
				else {
					anterior = actual;
					actual = actual->sig;
				}
			}
			else {
				cout << "No se puede ingresar nuevos" << endl;
				break;
			}
		}
	}
}

void BuscarClave(Clave *&encabezado, char clave[], char unidades[]) {
	Clave *buscador = new Clave();
	buscador = encabezado;

	if (buscador != NULL) {
		while (buscador != NULL) {
			if (strcmp(clave, buscador->nombre) == 0) {
				RegistrarDatos(buscador->cab, buscador->pie, unidades);
				break;
			}
			buscador = buscador->sig;
		}
	}
}

void RegistrarDatos(Nodo *&encabezado, Nodo *&pie, char unidades[]) {
	Nodo *nuevo_nodo = new Nodo();
	strcpy_s(nuevo_nodo->unidades, unidades);

	if (encabezado == NULL) {
		encabezado = nuevo_nodo;
		nuevo_nodo->sig = NULL;
		pie = encabezado;
	}
	else {
		pie->sig = nuevo_nodo;
		nuevo_nodo->sig = NULL;
		pie = nuevo_nodo;
	}
}

void MostrarTabla() {
	Clave *actual = new Clave();
	actual = cabeza;

	if (actual != NULL) {
		while (actual != NULL) {
			cout << actual->nombre << endl;
			cout << endl;
			MostrarDatos(actual->cab);
			actual = actual->sig;
		}
	}
}

void MostrarDatos(Nodo *&encabezado) {
	Nodo *actual = new Nodo();
	actual = encabezado;
	if (actual != NULL) {
		while (actual != NULL) {
			cout << " -> " << actual->unidades << endl;
			actual = actual->sig;
		}
	}
	cout << endl;
}
