#define _CRT_SECURE_NO_WARNINGS
//----------LIBRERIAS--------------------------------
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <string.h>
using namespace std; 
char numero[50];
int sum = 0, contar = 0, contarHojas = 0, busq = 0;
bool busqueda = false;
int Final = 0;
//----------MENU ELIMINACION--------------------------------
void menudeEliminacion();
typedef struct nodo1 {
	int dato1;
	struct nodo1 *izq1, *dere1, *padre1;
	int fe1, alturaIzq1, alturaDere1;

}arbol1, *parbol1;
//----------ESTRUCTURA DE CADA NODO--------------------------------
struct Nodo {
	int numArbol;
	Nodo *derecha;
	Nodo *izquierda;
	Nodo*padre;
	int a;
};

//----------FUNCION GOTOXY--------------------------------
void gotoxy(int x, int y) {

	HANDLE hCon;//Indificador de un objeto
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);//Control de la consola activa

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);

}

//----------SUPRIMIR--------------------------
int suprimir[100];
typedef struct Nodo *aux;
Nodo *arbol = NULL;
int auxiliar = 0;
/*AVL*/
int sw1 = 0; // Si es 1= insertar, 0=fe
arbol1 *nodo_p, *nuevo, *arbolavl; //Crea las estructuras de tipo puntero.
int buscado1 = 0; //Variable para guardar un valor buscado
arbol1 *PadreAB1, *sHijo1, *predecesor1, *abuelo1, *hijoHijo1;
//Recorridos pre, in, post
void preorden(arbol1 *arbolavl);
void inorden(arbol1 *arbolavl);
void postorden(arbol1 *arbolavl);
void insertarAvl(arbol1 *arbolavl, arbol1 *nuevo1, arbol1 *padre1);
void agregarDatos();
int exiteenArbol(arbol1 *arbolavl, int buscado1);
void verArbol(arbol1 arbolavl, int n);
void graficarArbol1(arbol1, int, int);
void dibujarCuadro(int, int, int, int);
void eliminarNodo1(arbol1 *arbolavl, int buscado1);
void estadoFactorEquilibrio(arbol1 *arbolavl);
void necesidadEquilibrar(arbol1 *arbolavl);
void menuabb();
void vaciarArbol1(arbol1 *arbolavl);

//funciones que reestructuran el árbol
void rotarII();
void rotarDD();
void rotarID();
void rotarDI();

parbol1 NuevoNodoavl(int num);

//Variable "nuevo" almacenará una nueva hoja para el árbol.
parbol1 NuevoNodoavl(int num) {
	nuevo = new (arbol1); //Crea la reserva de espacio en memoria.
	nuevo->dato1 = num;
	nuevo->izq1 = NULL; //Punteros a tierra
	nuevo->dere1 = NULL; //Punteros a tierra
	nuevo->alturaIzq1 = 0; //Setea en cero la altura izquierda el nodo
	nuevo->alturaDere1 = 0; //Setea en cero la altura derecha el nodo
	nuevo->fe1 = nuevo->alturaDere1 - nuevo->alturaIzq1; //Calculo del factor equilibrio, podría asignarse el valor cero desde la entrada.
	return nuevo;
}

/*Variables:
nuevo: Nueva hoja del arbol
recorrer: Es el puntero que esta señalando hacia la raiz del arbol, esta variable recorre el arbol hasta encontrar un espacio null donde guardar el nuevo nodo.
PadreAB: Mantiene un puntero al nodo anterior para referirse a el como el padre del nuevo nodo.
Funciones involucradas:
Recursivamente se llama así mismo hasta encontrar la ubicación donde se guardará el nuevo nodo, envío como parámetros 
(La dirección del lado del árbol hacía donde entrará, La nueva hoja, Referencia al padre).
*/
void insertarAvl(arbol1 *recorrer1, arbol1 *nuevo1, arbol1 *PadreAB1) {

	if (nodo_p == NULL) { //Si es el primer nodo entonces la raíz aún será nula porque no existe nada dentro de ella.		
		nodo_p = nuevo1; //Asignar a la raíz el valor del nuevo nodo creado...
		nodo_p->padre1 = NULL;
	}
	else {
		if (nuevo1->dato1 <= recorrer1->dato1) {
			if (recorrer1->izq1 != NULL) {
				PadreAB1 = recorrer1->izq1;
				//BBcout<<"Padre: "<<PadreAB->dato<<" Nuevo: "<<nuevo->dato<<endl;
				insertarAvl(recorrer1->izq1, nuevo1, PadreAB1);
			}
			else {
				recorrer1->izq1 = nuevo1;
				nuevo1->padre1 = PadreAB1;
				return;
			}
		}
		else if (nuevo1->dato1 > recorrer1->dato1) {
			if (recorrer1->dere1 != NULL) {
				PadreAB1 = recorrer1->dere1;
				//BBcout<<"Padre: "<<PadreAB->dato<<" Nuevo: "<<nuevo->dato<<endl;
				insertarAvl(recorrer1->dere1, nuevo1, PadreAB1);
			}
			else {
				recorrer1->dere1 = nuevo1;
				nuevo1->padre1 = PadreAB1;
				return;
			}
		}
	}
}

//Funcion que devuelve la altura de las ramas y su factor equilibrio, sólo devuelve valores más no calcula nada.
void estadoFactorEquilibrio(arbol1 *recorrer1) {
	if (recorrer1 != NULL) {
		cout << "Dato: " << recorrer1->dato1 << endl;
		cout << "Izquierda: " << recorrer1->alturaIzq1 << ", Derecha: " << recorrer1->alturaDere1 << ", Factor de Equilibrio: " << recorrer1->fe1 << endl;
		estadoFactorEquilibrio(recorrer1->izq1);
		estadoFactorEquilibrio(recorrer1->dere1);
	}
}

//Recorrido preOrden
void preorden(arbol1 *recorrer1) {
	if (recorrer1 != NULL) {
		cout << "\nNUMERO: " << recorrer1->dato1 << endl;

		preorden(recorrer1->izq1);
		preorden(recorrer1->dere1);
	}
}

//Recorrido InOrden
void inorden(arbol1 *recorrer1) {
	if (recorrer1 != NULL) {
		inorden(recorrer1->izq1);
		cout << "\nNUMERO: " << recorrer1->dato1 << endl;

		inorden(recorrer1->dere1);
	}
}

//Recorrido postOrden
void postorden(arbol1 *recorrer1) {
	if (recorrer1 != NULL) {
		postorden(recorrer1->izq1);
		postorden(recorrer1->dere1);
		cout << "\nNUMERO: " << recorrer1->dato1 << endl;

	}
}

//Vaciar el arbol
void vaciarArbol1(arbol1 *recorrer1) {
	if (recorrer1 != NULL) {
		postorden(recorrer1->izq1);
		postorden(recorrer1->dere1);

		if (recorrer1->dato1 == nodo_p->dato1) {
			nodo_p = NULL;
		}
		else {
			delete(recorrer1);//Liberamos la memoria.
		}
	}
}

//Imprime el árbol en vertical con el fin de no montar valores. La forma de verlo es rotarla 90 grados a la derecha.
/*
El puntero se va hasta el tope de la derecha, mientras va entrando cada vez más a la derecha va aumentando
espacios en "X" para simular la altura o profundidad del nodo en el arbol.
En cada impresión de nodo salta una línea hacía abajo.
De esta forma los nodos nunca se rozan y siempre se mantienen ordenados según la forma del árbol.
*/
void verArbol1(arbol1 *recorrer1, int n) {
	if (recorrer1 == NULL)
		return;
	verArbol1(recorrer1->dere1, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	cout << recorrer1->dato1 << endl;

	verArbol1(recorrer1->izq1, n + 1);
}

//Imprime el árbol en horizontal o en su forma normal.
/*
Utilizando la librería conio.h se puede indicar la ubicación de cada impresión del nodo.
Si entra a la derecha suma 5 espacios en X u 1 espacio en Y, inversamente si va hacia la izquierda resta los
5 espacios en X u 1 espacio en Y.
*/
void graficarArbol1(arbol1 *recorrer1, int x, int y) {

	if (recorrer1 == NULL)
		return;

	graficarArbol1(recorrer1->dere1, x + 6, y + 2);
	if (recorrer1->dere1)
	{
		int diag;
		for (diag = 91; diag <= 92; diag++)
		{
			gotoxy(x + 5, y + 1); printf("%c", diag);
		}
		gotoxy(x + 4, y + 2); cout << "(";

		gotoxy(x + 8, y + 2); cout << ")";
	}
	gotoxy(x, y); _cprintf("%d", recorrer1->dato1);

	graficarArbol1(recorrer1->izq1, x - 5, y + 2);
	if (recorrer1->izq1)
	{
		int diagin;
		for (diagin = 46; diagin <= 47; diagin++)
		{
			gotoxy(x - 3, y + 1); printf("%c", diagin);
		}
		gotoxy(x - 7, y + 2); cout << "(";
		gotoxy(x - 3, y + 2); cout << ")";
	}
}

//Función para buscar un dato en el árbol según si es mayor o menor así mismo va navegando en el arbol hasta encontrar el dato buscado.
int existeNodo = 0; //Si es 0 no existe, y si es 1 si existe.
int buscarDato(arbol1 *recorrer1, int buscado1) {
	if (recorrer1 == NULL) {
		cout << "Arbol Vacio o el nodo no existe" << endl;
	}
	else {
		if (buscado1<recorrer1->dato1) {
			buscarDato(recorrer1->izq1, buscado1);
		}
		else if (buscado1>recorrer1->dato1) {
			buscarDato(recorrer1->dere1, buscado1);
		}
		else {
			existeNodo = 1;
			PadreAB1 = recorrer1->padre1;
			//ABBcout<<"Padre: "<<PadreAB->dato<<" Nodo buscado: "<<recorrer->dato<<endl;
			cout << "\n\nEl nodo SI existe" << endl;
			cout << "NUMERO: " << recorrer1->dato1 << endl;



			return existeNodo;
		}
	}
}


//Función que devuelve 0 si el dato existe en un arbol y 1 si no existe.
//Esta función es utilizada por la función Insertar para validar que el nodo que se ingresa no existe en el árbol, si no existe deja insertar.
int exiteenArbol(arbol1 *recorrer1, int buscado1) {
	if (recorrer1 == NULL) {
		return 1;
	}
	else {
		if (buscado1<recorrer1->dato1) {
			exiteenArbol(recorrer1->izq1, buscado1);
		}
		else if (buscado1>recorrer1->dato1) {
			exiteenArbol(recorrer1->dere1, buscado1);
		}
		else {
			return 0;
		}
	}
}


//Analizar si el arbol no está vacío y si el nodo a eliminar no es la raíz. 
/*
Si el árbol es vacío lo notifica y si el nodo a eliminar es la raíz también lo indica con el fin de impedir la eliminación y mantener el control.
Si el el arbol no es vacío y nodo a eliminar no es la raíz entonces se llama a eliminar para proceder con el borrado del nodo.
*/
arbol1 *analizarAB;
void arbolVacio(arbol1 *recorrer1, int buscado1) {
	analizarAB = recorrer1;
	bool existeNodo = false;

	if (analizarAB == NULL) {
		cout << "Arbol Vacio" << endl;
		return;
	}
	else {
		if (analizarAB->dato1 == buscado1) {
			cout << "No se puede eliminar la Raiz" << endl;
			return;
		}
		else {
			eliminarNodo1(recorrer1, buscado1);
		}
	}
}


/*
Punteros utilizadas: *recorrer, *PadreAB, *sHijo, *predecesor, *abuelo;
Evalúa cual es los tres casos principales aplica la eliminación
*/
void eliminarNodo1(arbol1 *recorrer1, int buscado1) {

	if (recorrer1 != NULL) { // Se asegura que el arbol no esté vacío.
		if (buscado1 < recorrer1->dato1) { //Si el dato a encontrar es menos que busque por la rama izquierda.
			PadreAB1 = recorrer1; //Se hace una copia de recorrer en el padre antes de la siguiente recursiva...
			eliminarNodo1(recorrer1->izq1, buscado1); //Entra recursivamente a la rama izquierda.
		}
		else if (buscado1 > recorrer1->dato1) { //Si el dato a encontrar es mayor que busque por la rama derecha.
			PadreAB1 = recorrer1; //Se hace una copia de recorrer en el padre antes de la siguiente recursiva...
			eliminarNodo1(recorrer1->dere1, buscado1); //Entra recursivamente a la rama derecha.
		}
		else {

			//El elemento a eliminar es hoja, aplica al caso 1	
			if (recorrer1->izq1 == NULL && recorrer1->dere1 == NULL) {//Condiciones para aplicar al caso 1
				if (PadreAB1->izq1 == recorrer1) { //Detectamos si el nodo a eliminar esta a la izquierda del Padre
					PadreAB1->izq1 = NULL; //Si está a la izquierda del Padre solo tendremos que ponerl al Padre en su parte izquierda a Null
					delete(recorrer1); //Liberamos la memoria.
				}
				else { //Si el nodo no estaba a la izquierda, entonces estará a la derecha del Padre
					PadreAB1->dere1 = NULL; //Ponemos a Null su parte derecha del Padre
					delete(recorrer1);//Liberamos la memoria.
				}
			}
			else//Sino cumple lo anterior entonces no es hoja...

				//Si el nodo a eliminar tiene un hijo se aplica el caso 2
				if ((recorrer1->izq1 == NULL && recorrer1->dere1 != NULL) || (recorrer1->izq1 != NULL && recorrer1->dere1 == NULL)) {	//Condiciones para aplicar al caso 2

					if (recorrer1->izq1 == NULL && recorrer1->dere1 != NULL) { //Detectando el hijo del nodo a eliminar, si el hijo está a la derecha...
						sHijo1 = recorrer1->dere1; //Guardamos la dirección del nodo hijo
												   //abuelo=recorrer->padre; //Guardamos la dirección del padre del padre
						if (PadreAB1->izq1 == recorrer1) {//Detectamos si el nodo a eliminar está a la izquierda de padre...
							PadreAB1->izq1 = sHijo1;//Asignamos el nodo hijo del nodo eliminado al Padre en su parte izquierda.
							sHijo1->padre1 = PadreAB1; //Enlazamos al hijo al nuevo padre
							delete(recorrer1); //Liberamos la memoria del nodo descartado...
						}
						else { //Si el nodo a eliminar no estaba a la izquierda del Padre, entonces estará a la derecha...
							PadreAB1->dere1 = sHijo1; //Asignamos el nodo hijo del nodo eliminado al Padre en su parte derecha.
							sHijo1->padre1 = PadreAB1; //Enlazamos al hijo al nuevo padre
							delete(recorrer1); //Liberamos la memoria del nodo descartado...
						}
					}
					else {//Si el hijo del nodo a eliminar no estaba a la derecha, entonces estará a la izquierda...
						sHijo1 = recorrer1->izq1;//Guardamos la dirección del nodo hijo
						if (PadreAB1->izq1 == recorrer1) { //Detectamos si el nodo a eliminar está a la derecha de padre...
							PadreAB1->izq1 = sHijo1;//Asignamos el nodo hijo del nodo eliminado al Padre en su parte izquierda.
							sHijo1->padre1 = PadreAB1; //Enlazamos al hijo al nuevo padre
							delete(recorrer1);//Liberamos la memoria del nodo descartado...
						}
						else { //Si el nodo a eliminar no estaba a la izquierda del Padre, entonces estará a la derecha...
							PadreAB1->dere1 = sHijo1;//Asignamos el nodo hijo del nodo eliminado al Padre en su parte derecha.
							sHijo1->padre1 = PadreAB1; //Enlazamos al hijo al nuevo padre
							delete(recorrer1);//Liberamos la memoria del nodo descartado...
						}
					}
				}
				else {

					//Si no se cumple ninguno de las condiciones anteriores es porque el nodo tiene dos hijos y aplica al caso 3

					if (recorrer1->izq1 != NULL && recorrer1->dere1 != NULL) {//Condiciones para aplicar al caso 3
																			  //Encontraremos al predecesor, es decir al nodo más a la derecha de la rama izquierda.

						predecesor1 = recorrer1->izq1; //asignamos al predecesor la posición izquierda del nodo a eliminar
													   //Si el nodo a sustituir al padre no tiene hijos...
						if (predecesor1->izq1 == NULL && predecesor1->dere1 == NULL) { //Si las partes izquierda y derecha son nulas entonces el nodo a subir no tiene hijos y además es el predecesor que sustituirá al nodo a eliminar.
							recorrer1->dato1 = predecesor1->dato1; //Asignamos el dato del nuevo predecesor al nodo a eliminar
							recorrer1->izq1 = NULL;
							delete(predecesor1);	//Liberamos la memoria del nodo descartado...
						}
						else {
							predecesor1 = recorrer1->dere1; //asignamos al predecesor la posición derecha del nodo a eliminar
															//Si el nodo a sustituir al padre no tiene hijos...
							if (predecesor1->izq1 == NULL && predecesor1->dere1 == NULL) { //Si las partes izquierda y derecha son nulas entonces el nodo a subir no tiene hijos y además es el predecesor que sustituirá al nodo a eliminar.
								recorrer1->dato1 = predecesor1->dato1;//Asignamos el dato del nuevo predecesor al nodo a eliminar
								recorrer1->dere1 = NULL;
								delete(predecesor1);	//Liberamos la memoria del nodo descartado...
							}
							else {
								predecesor1 = recorrer1->izq1; //asignamos al predecesor la posición izquierda del nodo a eliminar
								if (predecesor1->dere1 == NULL) { //Si el predecesor no tiene hijos a la derecha él será el seleccionado
									recorrer1->dato1 = predecesor1->dato1; //Asignar el dato de predecesor al nodo a eliminar...
									recorrer1->izq1 = predecesor1->izq1;//Redireccionamos su parte izquierda para los hijos de ese lado.
									sHijo1 = predecesor1->izq1;
									sHijo1->padre1 = recorrer1;
									delete(predecesor1); //Liberamos la memoria del nodo descartado...
								}
								else {
									predecesor1 = recorrer1->dere1;//Asinamos a predecesor la posición derecha del nodo a eliminar
									if (predecesor1->izq1 == NULL) { //Si el predecesor no tiene hijos a la izquierda, él será el seleccionado.
										recorrer1->dato1 = predecesor1->dato1; //Asignar el dato de predecesor al nodo a eliminar...
										recorrer1->dere1 = predecesor1->dere1;//Redireccionamos su parte izquierda para los hijos de ese lado.
										sHijo1 = predecesor1->dere1;
										sHijo1->padre1 = recorrer1;
										delete(predecesor1);//Liberamos la memoria del nodo descartado...
									}
									else {
										predecesor1 = recorrer1->izq1; //Asignamos a predecesor la posición izquierda del nodo a eliminar...
										sHijo1 = predecesor1; //Hacemos una copia de la posición de predecesor 

										while (sHijo1->dere1 != NULL) { //Recorreremos hasta el más a la derecha de la rama izquierda...
											predecesor1 = sHijo1; //Guardar la posición anterior en predecesor y el Hijo estará una posición adelante.
											sHijo1 = sHijo1->dere1; //Nos movemos una posición más adelante para el siguiente ciclo.
										}
										//cout<<"\nPredecesor: "<<predecesor->dato<<" sHijo: "<<sHijo->dato<<" Recorrer: "<<recorrer->dato<<endl;
										recorrer1->dato1 = sHijo1->dato1; //Asignamos al nodo a eliminar el dato de valor mas a la derecha de la rama izquierda
										predecesor1->dere1 = sHijo1->izq1;//Apuntamos a la derecha al predecesor la dirección izquierda del Hijo
										hijoHijo1 = sHijo1->izq1;
										hijoHijo1->padre1 = predecesor1;
										//predecesor->izq=NULL; //Quitamos el apuntador del nodo izquierdo del predecesor porque ya no existirá en esa posición
										delete(sHijo1);

									}
								}
							}


						}
					}
				}
		}
	}
	else {
		cout << "El nodo no se encuentra en el arbol" << endl;
	}
}


/*
Se calcula la altura de cada rama y su factor de equilibrio.
La función se va hasta la izquierda del arbol para luego empezar a mandar los datos de altura a los niveles superiores del arbol.
Si la altura de la rama izquierda es mayor que la derecha entonces sube el valor de la rama izquierda para luego calcular el
factor de equilibrio del nodo padre, así hasta llegar al nodo raíz.
*/
int altura(arbol1 *recorrer1) {
	if (recorrer1 == NULL)//Si el nodo está vació entonces que salga.
		return 0; //Devuelve el valor cero.
	else {
		recorrer1->alturaIzq1 = altura(recorrer1->izq1);
		recorrer1->alturaDere1 = altura(recorrer1->dere1);
		recorrer1->fe1 = recorrer1->alturaDere1 - recorrer1->alturaIzq1;

		if (recorrer1->alturaIzq1 > recorrer1->alturaDere1)
			return recorrer1->alturaIzq1 + 1;
		else
			return recorrer1->alturaDere1 + 1;
	}
}


/*
Esta función analiza durante una busqueda si existe un factor de equilibrio que sea 2 o -2, si fuera el caso apunta al padre a ese nodo y
luego apunta al hijo para evaluar si el signo de este es positivo o negativo y así determinar el tipo de rotación que se necesita para
balancear el árbol.
El funcionamiento es:
Buscar el valor (-2) o (2) en el factor equilibrio de cualquier nodo del arbol.
Si es (-2) significa que existe desbalance a la izquierda y si el hijo es también (-) negativo significa que es el caso Rotación Izquierda Izquierda, y si fuera positivo es una Rotación Izquierda Derecha.
Si es (2) significa que existe desbalance a la derecha y si el hijo es también (+) positivo significa que es el caso Rotación Derecha Derecha, y si fuera negativo es una Rotación Derecha Izquierda.
*/
//arbol *PadreAB, *sHijo, *predecesor;
//Con esta función analizo si es necesario equilibrar el árbol, esta función busca el valor -2 o 2.
void necesidadEquilibrar(arbol1 *recorrer1) { 
	if (recorrer1 != NULL) {

		necesidadEquilibrar(recorrer1->izq1);
		necesidadEquilibrar(recorrer1->dere1);

		if ((recorrer1->fe1 == 2) || (recorrer1->fe1 == -2)) {
			system("cls");
			cout << "Es necesario equilibrar el arbol" << endl;

			PadreAB1 = recorrer1;
			sHijo1 = PadreAB1->dere1;

			//Identificar Si es el caso  RDD, Rotación Derecha, Derecha.
			if ((PadreAB1->fe1>1) && (sHijo1->fe1>0)) {
				cout << "Rotacion derecha derecha." << endl;
				cout << " Padre: " << PadreAB1->dato1 << " Hijo: " << sHijo1->dato1 << endl;
				_getch();
				rotarDD();
				altura(nodo_p);
				return;
				//Identificar Si es el caso  RDI, Rotación Derecha, Izquierda.
			}
			else if ((PadreAB1->fe1>1) && (sHijo1->fe1<0)) {
				cout << "Rotacion derecha izquierda." << endl;
				cout << " Padre: " << PadreAB1->dato1 << " Hijo: " << sHijo1->dato1 << endl;
				_getch();
				rotarDI();
				altura(nodo_p);
				return;
			}
			else {

				PadreAB1 = recorrer1;
				sHijo1 = PadreAB1->izq1;

				//Identificar Si es el caso  RII, Rotación Izquierda, Izquierda.
				if ((PadreAB1->fe1<-1) && (sHijo1->fe1<0)) {
					cout << "Rotacion izquierda izquierda." << endl;
					cout << " Padre: " << PadreAB1->dato1 << " Hijo: " << sHijo1->dato1 << endl;
					_getch();
					rotarII();
					altura(nodo_p);
					return;
					//Identificar Si es el caso  RID, Rotación Izquierda, Derecha.	
				}
				else if ((PadreAB1->fe1<-1) && (sHijo1->fe1>0)) {
					cout << "Rotacion izquierda Derecha." << endl;
					cout << " Padre: " << PadreAB1->dato1 << " Hijo: " << sHijo1->dato1 << endl;
					_getch();
					rotarID();
					altura(nodo_p);
					return;
				}
			}
			return;
		}
	}
}


//Rotación Derecha Izquierda
void rotarDI() {
	if (PadreAB1 == nodo_p) {

		hijoHijo1 = sHijo1->izq1; //Ubico al hijo del hijo...

		nodo_p = hijoHijo1; //Cambiar el apuntador de la raíz.

		hijoHijo1->padre1 = NULL; //Aseguro que el padre de la raíz se quede en NULL

		hijoHijo1->dere1 = sHijo1; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo1->padre1 = hijoHijo1; //El hijo debe apuntar a su nuevo padre.
		if (sHijo1->izq1 != NULL) {
			sHijo1->izq1 = hijoHijo1->izq1;
		}
		else {
			sHijo1->izq1 = NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
		}

		//sHijo->dere=NULL; // Apuntar a Null la parte derecha del hijo, ya que ahora no tendrá Hijos...

		hijoHijo1->izq1 = PadreAB1; //El nuevo padre debe apuntar al hijo derecho.

		if (PadreAB1->izq1 == NULL) {
			PadreAB1->izq1 = NULL; //El antiguo padre debe apuntar ahora a nu
		}

		PadreAB1->dere1 = NULL; //el antiguo padre debe apuntar ahora a null
		PadreAB1->padre1 = hijoHijo1; //Apuntar al nuevo padre ...
	}
	else {

		abuelo1 = PadreAB1->padre1;

		hijoHijo1 = sHijo1->izq1; //Ubico al hijo del hijo...

		hijoHijo1->padre1 = abuelo1; //Aseguro que el padre de la raíz se quede apuntando al abuelo

		hijoHijo1->dere1 = sHijo1; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo1->padre1 = hijoHijo1; //El hijo debe apuntar a su nuevo padre.

		if (sHijo1->izq1 != NULL) {
			sHijo1->izq1 = hijoHijo1->izq1;
		}
		else {
			sHijo1->izq1 = NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			
		}

		//sHijo->dere=NULL; // Apuntar a Null la parte derecha del hijo, ya que ahora no tendrá Hijos...

		hijoHijo1->izq1 = PadreAB1; //El nuevo padre debe apuntar al hijo derecho.

		if (PadreAB1->izq1 == NULL) {
			PadreAB1->izq1 = NULL; //El antiguo padre debe apuntar ahora a nu
		}

		PadreAB1->dere1 = NULL; //el antiguo padre debe apuntar ahora a null
		PadreAB1->padre1 = hijoHijo1; //Apuntar al nuevo padre ...

		abuelo1->dere1 = hijoHijo1;
	}
}


//Rotación  Izquierda Derecha
void rotarID() {
	if (PadreAB1 == nodo_p) {

		hijoHijo1 = sHijo1->dere1; //Ubico al hijo del hijo...

		nodo_p = hijoHijo1; //Cambiar el apuntador de la raíz.

		hijoHijo1->padre1 = NULL; //Aseguro que el padre de la raíz se quede en NULL

		hijoHijo1->izq1 = sHijo1; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo1->padre1 = hijoHijo1; //El hijo debe apuntar a su nuevo padre.

		sHijo1->dere1 = NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			

		PadreAB1->izq1 = NULL; //El antiguo padre debe apuntar ahora a null 

		hijoHijo1->dere1 = PadreAB1; //El nuevo padre debe apuntar al hijo derecho.


		if (PadreAB1->dere1 == NULL) {
			PadreAB1->dere1 = NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB1->padre1 = hijoHijo1; //Apuntar al nuevo padre ...
	}
	else {

		abuelo1 = PadreAB1->padre1;

		hijoHijo1 = sHijo1->dere1; //Ubico al hijo del hijo...

		hijoHijo1->padre1 = abuelo1; //Aseguro que el padre de la raíz se quede apuntando al abuelo
		abuelo1->izq1 = hijoHijo1;

		hijoHijo1->izq1 = sHijo1; // el nuevo padre debe apuntar al hijo izquierdo.		
		sHijo1->padre1 = hijoHijo1; //El hijo debe apuntar a su nuevo padre.

		sHijo1->dere1 = NULL; //Apuntar a Null la parte izquierda del hijo, ya que ahora no tendrá hijos...			


		hijoHijo1->dere1 = PadreAB1; //El nuevo padre debe apuntar al hijo derecho.

		PadreAB1->izq1 = NULL; //El antiguo padre debe apuntar ahora a null 

		if (PadreAB1->dere1 == NULL) {
			PadreAB1->dere1 = NULL; //El antiguo padre debe apuntar ahora a nu
		}
		PadreAB1->padre1 = hijoHijo1; //Apuntar al nuevo padre ...
	}
}

//Rotación  Derecha Derecha
void rotarDD() {
	if (PadreAB1 == nodo_p) {
		nodo_p = sHijo1;

		//sHijo->dere=hijoHijo;
		//hijoHijo->padre=sHijo;
		//hijoHijo->dere=NULL;

		sHijo1->izq1 = PadreAB1;
		PadreAB1->padre1 = sHijo1;
		PadreAB1->dere1 = NULL;

		sHijo1->padre1 = NULL;

	}
	else {
		abuelo1 = PadreAB1->padre1;
		abuelo1->dere1 = PadreAB1->dere1;
		sHijo1->padre1 = abuelo1;
		sHijo1->izq1 = PadreAB1;
		PadreAB1->padre1 = sHijo1;
		PadreAB1->dere1 = NULL;
	}
}


//Rotación  Izquierda Izquierda
void rotarII() {
	if (PadreAB1 == nodo_p) {
		nodo_p = sHijo1;

		hijoHijo1 = sHijo1->izq1;

		sHijo1->dere1 = PadreAB1;
		PadreAB1->izq1 = NULL;
		PadreAB1->padre1 = sHijo1;

		sHijo1->padre1 = NULL;

		//PadreAB->dere=hijoHijo;
		//hijoHijo->padre=PadreAB;

		//sHijo->dere=PadreAB;


	}
	else {
		abuelo1 = PadreAB1->padre1;
		abuelo1->izq1 = PadreAB1->izq1;
		sHijo1->padre1 = abuelo1;
		sHijo1->dere1 = PadreAB1;
		PadreAB1->padre1 = sHijo1;
		PadreAB1->izq1 = NULL;
	}
}

//Dibuja dos cuadrados para hacer la carátula
void dibujarCuadro(int x1, int y1, int x2, int y2) {
	int i;
	for (i = x1 + 1; i<x2; i++) {
		gotoxy(i, y1); _cputs("-");//linea horizontal superior
		gotoxy(i, y2); _cprintf("-");//linea horizontal inferior
	}
	for (i = y1 + 1; i<y2; i++) {
		gotoxy(x1, i); _cprintf("|");//linea vertical izquierda
		gotoxy(x2, i); _cprintf("|");//linea vertical derecha
	}
}


//Con el fin de automatizar o apresurar el ingreso masivo de datos se genera esta función
/*
Pregunta cuántos datos se ingresarán y en base a la cantidad irá solicitando los datos en forma contínua.
*/
void agregarDatos(int a) {
	system("cls");

	arbolavl = nodo_p; //Se apunta a recorrer en al mismo nodo donde apunta la raíz
	nuevo = NuevoNodoavl(a); //Almacena el nuevo nodo para luego insertarlo en el arbol.

	if (nuevo->dato1 != 0) {
		if (exiteenArbol(arbolavl, nuevo->dato1) == 1) { //Evalua si el nodo ya existe en el arbol.
			PadreAB1 = nodo_p;
			insertarAvl(arbolavl, nuevo, PadreAB1);

			altura(arbolavl);
			necesidadEquilibrar(arbolavl);
		}
		else {
			cout << "El numero ya existe en el arbol" << endl;
			_getch();
		}
	}
	else {
		vaciarArbol1(nodo_p);
		system("cls");
		verArbol1(nodo_p, 0);
		cout << "El arbol ha sido eliminado porque ingreso el numero cero " << endl;
		_getch();

		return;
	}

	verArbol1(nodo_p, 0);

}
/*AVL*/
Nodo *crearNodo(int n, Nodo *padre) {        //Funcion creacion del nodo

	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->numArbol = n;
	nuevo_nodo->derecha = NULL;
	nuevo_nodo->izquierda = NULL;
	nuevo_nodo->padre = padre;
	cout << endl;
	return nuevo_nodo;
}

void insertaNodo(Nodo *&arbol, int n, Nodo *padre) { //Funcion para insertar nodo

	if (arbol == NULL) { 				//Si el arbol esta vacio

		Nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;

	}
	else {

		int valoraiz = arbol->numArbol;
		if (n < valoraiz) {
			insertaNodo(arbol->izquierda, n, arbol);
		}
		else {
			insertaNodo(arbol->derecha, n, arbol);
		}
	}
}
void Buscado(Nodo *arbol, int n) {		//Funcion para  buscar y eleminar dato

	if (arbol == NULL) {

		return;
	}
	else if (n<arbol->numArbol) {			//Si el dato es menor

		Buscado(arbol->izquierda, n); //Buscar por la izquierda

	}
	else if (n>arbol->numArbol) {		//Si el dato es mayor

		Buscado(arbol->derecha, n); //Busca por la derecha

	}
	else {//Se encontro el dato

		busqueda = true;
	}
}

void llenarArbol1() {
	system("cls");
	fstream arch;
	char linea[120];
	char * token;
	char * token2;
	int num, num2;
	string nom;
	bool line;
	
	gotoxy(25, 10); printf("INGRESE EL NOMBRE DEL ARCHIVO: ");
	scanf("%s", &numero);
	strcat(numero, ".txt");
	arch.open(numero, ios::in);

	int co = 0;
	if (arch.fail())
	{
		system("cls");
		gotoxy(10, 25); cout << "ARCHIVO NO ENCONTRADO\n\n" << endl;

		system("pause");
		exit(EXIT_FAILURE);
	}
	while (!arch.eof())
	{
		co = co + 1;


		_getch();

		arch.getline(linea, 120);

		if (co == 1) {

			token = strtok(linea, ",");

			while (token != NULL)
			{

				num = atoi(token);
				token = strtok(NULL, ",");
				busqueda = false;

				Buscado(arbol, num);
				if (busqueda == false) {
					insertaNodo(arbol, num, NULL);
					agregarDatos(num);
				}
			}
		}
		if (co = 2) {
			cout << "LOS DATOS PARA EL ARBOL FUERON AGREGADOS EXITOSAMENTE\n\n" << endl;
			cout << "LOS DATOS QUE SE PUEDEN ELIMINAR FUERON AGREGADOS EXITOSAMENTE\n\n " << endl;

			token2 = strtok(linea, ",");
			while (token2 != NULL)
			{
				num2 = atoi(token2);
				suprimir[Final] = num2;
				Final++;
				token2 = strtok(NULL, ",");

			}
		}
	}
	arch.close();
}

void BorraNodo(Nodo *adios) {

	adios->izquierda = NULL;
	adios->derecha = NULL;

	delete adios;
}
void reemplazarNodo(Nodo *arbol, Nodo *nuevoNodo) {//Funcion para reemplazar nodos para eliminar de un solo hijo

	if (arbol->padre) {//arbol->padre se le asigna su nuevo hijo

		if (arbol->numArbol == arbol->padre->izquierda->numArbol) { 	//Remplazar hijo izquierdo
			arbol->padre->izquierda = nuevoNodo;
		}
		else if (arbol->numArbol == arbol->padre->derecha->numArbol) { //Remplazar hijo derecho
			arbol->padre->derecha = nuevoNodo;
		}
	}
	if (nuevoNodo) {

		//asignar nuevo padre
		nuevoNodo->padre = arbol->padre;
	}

}
Nodo *Minimo(Nodo*arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izquierda) {
		return Minimo(arbol->izquierda);
	}
	else {
		return arbol;
	}
}

int diag1;
int diagin1;

void mostraArbol(Nodo *Arbol, int auxY) {
	if (Arbol == NULL) {//Arbol vacio nada que mostrar
		return;
	}
	auxiliar += 4;//variable que permite posicionarse en el eje X
	//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
	mostraArbol(Arbol->izquierda, auxY + 2);
	gotoxy(9 + auxiliar - auxY, 15 + auxY);//posiciona el nodo segun sus variables en X y en Y
	cout << Arbol->numArbol << endl << endl;//Muestra el dato del nodo respectivo
	if (Arbol->derecha)
	{
		for (diag1 = 91; diag1 <= 92; diag1++)
		{
			gotoxy(9 + auxiliar - auxY, 14 + auxY); printf("%c", diag1);
			gotoxy(8 + auxiliar - auxY, 15 + auxY); cout << "(";
			gotoxy(11 + auxiliar - auxY, 15 + auxY); cout << ")";
		}
	}
	else
	{
		for (diagin1 = 46; diagin1 <= 47; diagin1++)
		{
			gotoxy(9 + auxiliar - auxY, 14 + auxY); printf("%c", diagin1);
			gotoxy(8 + auxiliar - auxY, 15 + auxY); cout << "(";
			gotoxy(11 + auxiliar - auxY, 15 + auxY); cout << ")";
		}
	}
	mostraArbol(Arbol->derecha, auxY + 2);//Se para hasta el nodo mas a la derecho del árbol
//Se debe tener el cuenta el funcionamiento de la recursividad la cual implementa una pila para almacenar las instrucciones
}

void reemplazarNodoPorderecha(Nodo *arbol, Nodo *nuevoNodo) {//Funcion para reemplazar nodos para eliminar de un solo hijo

	if (arbol->padre) {//arbol->padre se le asigna su nuevo hijo
		cout << "ENTRO 2" << endl;
		if (arbol->numArbol == arbol->padre->izquierda->numArbol) { 	//Remplazar hijo izquierdo
			arbol->padre->izquierda = nuevoNodo;
		}
		else if (arbol->numArbol == arbol->padre->derecha->numArbol) { //Remplazar hijo derecho
			arbol->padre->derecha = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		cout << "ENTRO" << endl;
		//asignar nuevo padre
		nuevoNodo->padre = arbol->padre;
	}

}

void BuscandoPadre(Nodo *arbol, Nodo *dir) {


	if (arbol == NULL) {

	}
	else {
		BuscandoPadre(arbol->derecha, dir);


		if (arbol->izquierda == dir) {

			cout << arbol->numArbol << endl;

			arbol->izquierda = NULL;
			delete(dir);
			system("pause");

		}

		if (arbol->derecha == dir) {

			cout << arbol->numArbol << endl;
			arbol->derecha = NULL;
			delete(dir);
			system("pause");

		}
		BuscandoPadre(arbol->izquierda, dir);

	}

}


void eliminaNodo(Nodo *nodoEliminar) { //Funcion para eliminar el dato encontrado

	Nodo * dir = NULL;


	if (nodoEliminar->izquierda && nodoEliminar->derecha) {//si el nodo tiene hijo izquierdo e hijo derecho

		Nodo *menor = Minimo(nodoEliminar->derecha);
		nodoEliminar->numArbol = menor->numArbol;
		eliminaNodo(menor);
	}
	else if (nodoEliminar->izquierda) {//Si tiene hijo izquierdo

		reemplazarNodo(nodoEliminar, nodoEliminar->izquierda);
		BorraNodo(nodoEliminar);
	}
	else if (nodoEliminar->derecha) {	//Si tiene hijo derecho

		reemplazarNodo(nodoEliminar, nodoEliminar->derecha);
		BorraNodo(nodoEliminar);
	}
	else {//Nodo que no tenga hijos HOJA
		cout << "EL DATO SE ENCONTRO" << endl;
		system("pause");
		BuscandoPadre(arbol, nodoEliminar);
		system("pause");
	}
}

Nodo *minimoDerecha(Nodo*arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->derecha) {
		return Minimo(arbol->derecha);
	}
	else {
		return arbol;
	}
}
void eliminacion(Nodo *arbol, int n) {		//Funcion para  buscar y eleminar dato

	if (arbol == NULL) {

		return;
	}
	else if (n<arbol->numArbol) {			//Si el dato es menor

		eliminacion(arbol->izquierda, n); //Buscar por la izquierda

	}
	else if (n>arbol->numArbol) {		//Si el dato es mayor

		eliminacion(arbol->derecha, n); //Busca por la derecha

	}
	else {//Se encontro el dato

		eliminaNodo(arbol);

	}
}

void eliminarNodoPorderecha(Nodo *nodoEliminar) { //Funcion para eliminar el dato encontrado
	Nodo * dir = NULL;
	if (nodoEliminar->izquierda && nodoEliminar->derecha) {//si el nodo tienehijo izquierdo e hijo derecho
		Nodo *menor = minimoDerecha(nodoEliminar->izquierda);
		nodoEliminar->numArbol = menor->numArbol;
		eliminarNodoPorderecha(menor);
	}
	else if (nodoEliminar->izquierda) {//Si tiene hijo izquierdo
		reemplazarNodo(nodoEliminar, nodoEliminar->derecha);
		BorraNodo(nodoEliminar);
	}
	else if (nodoEliminar->derecha) {	//Si tiene hijo derecho
		reemplazarNodo(nodoEliminar, nodoEliminar->izquierda);
		BorraNodo(nodoEliminar);
	}
	else {//Nodo que no tenga hijos HOJA
		cout << " EL DATO SE ENCONTRO" << endl;
		system("pause");
		BuscandoPadre(arbol, nodoEliminar);
		system("pause");
	}
}

void eliminarPorder(Nodo *arbol, int n) {		//Funcion para  buscar y eleminar dato
	if (arbol == NULL) {
		return;
	}
	else if (n<arbol->numArbol) {			//Si el dato es menor
		eliminarPorder(arbol->izquierda, n); //Buscar por la izquierda
	}
	else if (n>arbol->numArbol) {		//Si el dato es mayor
		eliminarPorder(arbol->derecha, n); //Busca por la derecha
	}
	else {//Se encontro el dato
		eliminarNodoPorderecha(arbol);
	}
}

void llenarArbol() {
	fstream arch;
	char linea[120];
	char * token;
	char * token2;
	int num, num2;
	string nom;
	bool line;
	gotoxy(45, 5); cout << "*BIENVENIDO* " << endl;
	gotoxy(25, 10); printf("INTRODUZCA EL NOMBRE DEL ARCHIVO(SIN .txt): ");
	scanf("%s", &numero);
	strcat(numero, ".txt");
	arch.open(numero, ios::in);
	int co = 0;
	if (arch.fail())
	{
		system("cls");
		gotoxy(10, 25); cout << "NO APARECE NINGUN ARCHIVO CON ESE NOMBRE\n\n" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	while (!arch.eof())
	{
		co = co + 1;
		_getch();
		arch.getline(linea, 120);
		if (co == 1) {
			token = strtok(linea, ",");
			while (token != NULL)
			{
				num = atoi(token);
				token = strtok(NULL, ",");
				busqueda = false;

				Buscado(arbol, num);
				if (busqueda == false) {
					insertaNodo(arbol, num, NULL);
				}
			}
		}
		if (co = 2) {
			cout << "LOS DATOS PARA EL ARBOL FUERON AGREGADOS EXITOSAMENTE\n\n" << endl;
			cout << "LOS DATOS QUE SE PUEDEN ELIMINAR FUERON AGREGADOS EXITOSAMENTE\n\n " << endl;

			token2 = strtok(linea, ",");
			while (token2 != NULL)
			{
				num2 = atoi(token2);
				suprimir[Final] = num2;
				Final++;
				token2 = strtok(NULL, ",");
			}
		}
	}
	arch.close();
}

bool Buscar(int a) {
	for (int i = 1; i < Final; i++) {
		if (suprimir[i] == a) {
			return true;
		}
	}
	return false;
}

void menudeEliminacion() {
	int a;
	system("cls");
	cout << "DATOS QUE SE PUEDEN ELIMINAR:" << endl;
	for (int i = 1; i < Final; i++) {
		cout << suprimir[i] << endl;
	}
	cout << "DATOS A ELIMINAR:" << endl;
	cin >> a;
	if (Buscar(a) == true) {
		int opcion2 = 0;
		do
		{
			system("cls");
			gotoxy(45, 7); cout << "*ELIMINACION*" << endl;
			gotoxy(30, 9); cout << "||1. ELIMINACION POR LA IZQUIERDA   ||" << endl;
			gotoxy(30, 10); cout << "||2. ELIMINACION POR LA DERECHA     ||" << endl;
			gotoxy(30, 11); cout << "||3. REGRESAR AL MENU               ||" << endl;
			gotoxy(30, 13); cout << "    INGRESE UNA OPCION : [  ]";
			gotoxy(56, 13); cin >> opcion2;
			switch (opcion2)
			{
			case 1:
				eliminacion(arbol, a);
				menuabb();
				break;
			case 2:
				eliminarPorder(arbol, a);
				menuabb();
				break;
			default:
				break;
			}
		} while (opcion2 = 3); {
			menuabb();
		}
	}
	else {
		cout << "EL DATO NO ES VALIDO PARA ELIMINAR" << endl;
		system("pause");
	}

}
void menuabb() {
	int dato;
	int op = 0;
	int op2 = 0;
	auxiliar = 0;
	int opc = 0;
	system("cls");
	do {
		system("cls");
		gotoxy(15, 7);  cout << "**********MENU ABB***********************" << endl;
		gotoxy(15, 8);  cout << "*1.       CARGAR DATOS                  *" << endl;
		gotoxy(15, 9);  cout << "*2.       MOSTRAR                       *" << endl,
		gotoxy(15, 10);	cout << "*3.       ELIMINAR                      *" << endl;
		gotoxy(15, 11); cout << "*4.       DATOS DEL ARBOL               *" << endl;
		gotoxy(15, 12); cout << "*5.       BUSCAR DATO                   *" << endl;
		gotoxy(15, 13); cout << "*6.       SALIR                         *" << endl;
		gotoxy(15, 14); cout << "*    INGRESE UNA OPCION : [  ]          *";
		gotoxy(15, 15);  cout << "*****************************************" << endl;
		gotoxy(51,14); cin >> opc;
		switch (opc)
		{
		case 1:
			system("cls");
			llenarArbol();
			break;
		case 2:
			system("cls");
			cout << "\tMOSTRANDO ARBOL" << endl;
			auxiliar = 0;
			mostraArbol(arbol, 0);
			cout << endl << endl << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			menudeEliminacion();
			break;
		case 4:
			system("cls");
			cout << "LA SUMA DE LOS NODOS ES:" << sum << endl;
			cout << "LA CANTIDAD DE NODOS ES: " << contar << endl;
			cout << "LA CANTIDAD DE HOJAS SON:" << contarHojas << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			busqueda = false;
			cout << "INGRESE UN DATO A BUSCAR" << endl;
			cin >> busq;
			Buscado(arbol, busq);
			if (busqueda == true) {
				cout << "EL DATO FUE ENCONTRADO" << endl;
			}
			else {
				cout << "EL DATO NO PUDO SER ENCONTRADO" << endl;
			}
			system("pause");
			break;
		default:
			break;
		}
	} while (opc != 6);
}
void menuavl() {
	//intro();
	int opcion = 0;
	while (opcion != 11) {
		system("cls");
		gotoxy(15,5);cout << "************************** MENU AVL************************\n\n";
		gotoxy(15, 6);cout << "* 1.  Llenar Arbol                                       *\n";
		gotoxy(15, 7);cout << "* 2.  Mostrar PreOrden ,InOrden y PostOrden              *\n";
		gotoxy(15, 8);cout << "* 3.  Graficar Arbol - Rotado 90 grados                  *\n";
		gotoxy(15, 9);cout << "* 4.  Mostrar Arbol                                      *\n";
		gotoxy(15, 10);cout <<"* 5.  Altura del arbol                                   *\n";
		gotoxy(15, 11);cout <<"* 6.  Eliminar dato                                      *\n";
		gotoxy(15, 12);cout <<"* 7.  Buscar dato                                        *\n";
		gotoxy(15, 13);cout <<"* 8. Vaciar el arbol                                     *\n";
		gotoxy(15, 14);cout <<"* 9. Salir                                               *\n";
		gotoxy(15, 15); cout<<"* Selecione una opcion :_________                        *\n";
		gotoxy(15, 16); cout <<"**********************************************************\n";
		gotoxy(40, 15); cin >> opcion;
		arbolavl = nodo_p;
		switch (opcion) {
		case 1:
			llenarArbol1();
			break;
		case 2:
			system("cls");
			cout << "--------------PreOrden----------------" << endl;
			preorden(arbolavl);
			_getch();
			system("cls");
			cout << "---------------InOrden--------------------" << endl;
			inorden(arbolavl);
			_getch();
			system("cls");
			cout << "----------------POSTORDEN-----------------" << endl;
			postorden(arbolavl);
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "-------------ARBOL AVL---------------------" << endl;
			verArbol1(arbolavl, 0);
			_getch();
			break;
		case 4:
			system("cls");
			gotoxy(25, 2); _cprintf("---------------ARBOL AVL----------------");
			graficarArbol1(arbolavl, 40, 5);
			_getch();
			break;
		case 5:
			system("cls");
			cout << "La Altura del arbol es: " << altura(arbolavl) << endl;
			_getch();
			break;
		case 6:
			system("cls");
			cout << "Dato a eliminar: "; cin >> buscado1;
			arbolVacio(arbolavl, buscado1);
			arbolavl = nodo_p;
			altura(arbolavl);
			arbolavl = nodo_p; 
			necesidadEquilibrar(arbolavl); 
			cout << "Se ha eliminado el nodo" << endl;
			_getch();
			break;
		case 7:
			system("cls");
			cout << "Nodo a buscar: "; cin >> buscado1;
			buscarDato(arbolavl, buscado1);
			_getch();
			break;
		case 8:
			system("cls");
			cout << "Vaciar Arbol" << endl;
			vaciarArbol1(arbolavl);

			_getch();
			break;
		case 11:
			break;
		default:
			cout << "No es una opcion correcta";
			break;
		}
	}
	_getch();
}

void MenuPrincipal() {
	int op = 0;
	do {
		system("cls");
		gotoxy(25, 7);  cout << "------------------MENU PRINCIPAL-----------------" << endl;
		gotoxy(25, 8);  cout << "-                  1. MENU ABB                  -" << endl;
		gotoxy(25, 9);  cout << "-                  2.MENU AVL                   -" << endl;
		gotoxy(25, 10); cout << "-                  3. SALIR                     -" << endl;
		gotoxy(25, 11); cout << "-    INGRESE UNA OPCION :                       -" << endl;;
		gotoxy(25, 12);  cout <<"------------------------------------------------" << endl;
		gotoxy(53, 11); cin >> op;
		switch (op)
		{
		case 1:
			system("cls");
			menuabb();
			system("pause");
			break;
		case 2:

			menuavl();

		default:
			break;
		}
	} while (op != 3);
}

int main() {
	system("color F2");

	Nodo *miArbol = NULL;
	MenuPrincipal();
	return 0;
}