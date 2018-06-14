#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>



using namespace std;

struct nodo {
	int nro;
	char usr;
	char doc;
	struct nodo *sgte;
};

struct cola {
	nodo *delante;
	nodo *atras;
};

void encolar(struct cola &q, int valor, char usuario, char documento) {
	struct nodo *aux = new(struct nodo);

	aux->usr == usuario;
	aux->doc == documento;
	aux->nro = valor;
	aux->sgte = NULL;

	if (q.delante == NULL)
		q.delante = aux;
	else 
		(q.atras)->sgte = aux;

		q.atras = aux;
}
int desencolar(struct cola &q) {
	int num;
	char usr;
	char doc;
	struct nodo *aux;

	aux = q.delante;
	num = aux->nro;
	usr = aux->usr;
	doc = aux->doc;
	q.delante = (q.delante)->sgte;
	delete(aux);

	return num;
}

void muestraCola(struct cola q) {
	struct nodo *aux;
	aux = q.delante;

	while (aux != NULL) {
		cout << "   " << aux->doc << "   " << aux->nro << "   " << aux->usr << endl;
		aux = aux->sgte;
	}
}

void vaciaCola(struct cola &q) {
	struct nodo *aux;

	while (q.delante != NULL) {
		aux = q.delante;
		q.delante = aux->sgte;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;
}

void menu() {
	cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
	cout << "1. ENCOLAR		" << endl;
	cout << "2. DESENCOLAR	" << endl;
	cout << "3. MOSTRAR COLA" << endl;
	cout << "4. VACIAR COLA	" << endl;
	cout << "5. SALIR		" << endl;

	cout << "\n INGRESE OPCION : ";
}

void main() {
	struct cola q;

	q.delante = NULL;
	q.atras = NULL;

	int numero;
	char documento;
	char usuario;
	int op;
	int x;

	system("color 0b");

	do {
		menu(); cin >> op;
		switch (op) {
		case 1:
			cout << "\n NOMBRE DEL ARCHIVO: "; cin >> documento;
			cout << "\n NUMERO DE PAGINAS: "; cin >> numero;
			cout << "\n NOMBRE DE USUARIO: "; cin >> usuario;
			encolar(q, numero, usuario, documento);
			cout << "\n\n\t\t Documento: " << documento << "Paginas: " << numero<<"Usuario: " << usuario << "encolando ...\n\n";
			break;

		case 2:
			x = desencolar(q);
			cout << "\n\n\t\t DOCUMENTO " << x << " desencolado.... \n\n";
			break;

		case 3:
			cout << "\n\n MOSTRANDO COLA \n\n";
			if (q.delante != NULL) muestraCola(q);
			else cout << "\n\n\t Cola vacia...!" << endl;
			break;

		case 4:
			vaciaCola(q);
			cout << "\n\n\t Hecho..\n\n";
			break;
		}
		cout << endl << endl;
		system("pause"); system("cls");
	} while (op != 5);

}