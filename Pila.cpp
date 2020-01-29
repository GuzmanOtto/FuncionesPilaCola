#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct nodo{
	int valor;
	struct nodo *siguiente;
}tipoNodo;

//Typedef struct nodo tipoNodo: Cuando no lo hace arriba en
typedef tipoNodo *pNodo, *Pila;	//*pNodo crear punteros auxiliar
								//*Pila para el inicio de la pila

/*Funciones con pilas: */
void Push(Pila *pila, int num);
int Pop(Pila *pila,int num);
void MostrarPila(Pila pila);
void Longitud(Pila pila);
void menu();

int main(){
	menu();
	system("PAUSE");
	return 0;
}

//Funcion Insertar (Push)
void Push(Pila *pila, int num){//*pila recoge por referencia el
	pNodo nuevo=NULL;
	/* Crear un nodo nuevo*/
	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor=num;
	if(nuevo!=NULL){
		if(*pila==NULL)	//Verifica si inicio de pila es NULO
		nuevo->siguiente=NULL;
		else
		/*Añadimos nodo en la pila nates nodo anterior, es decir al*/
			nuevo->siguiente=*pila;
		/*Ahora, el comienzo de nuestra pila es el nuevo nodo*/
		*pila=nuevo;
		nuevo=NULL;
	}else
	printf("\nNo se pudo insertar a la pila\n");
}

//Funcion Eliminar (POP) elementos de la pila
int Pop(Pila *pila,int num){//*pila recoge por referencia el inicio de 
	pNodo aux = NULL; /*puntero auxiliar nodo*/
	if(*pila == NULL)
		return 0; /*Pila vacia, no hay nodos en la pila, retornamos*/
	else{
		aux = *pila; /*aux apunta al primer elemento de la pila
		Asignamos inicio de pila al siguiente elemento*/
		*pila = aux->siguiente;
		/*Guardamos el valor de primer nodo de pila como retorno*/
		num = aux->valor;
		/*Borrar el nodo auxiliar que tiene el que estaba en inicio*/
		free(aux);
		return num;
	}
}//Cierra funciom

//Funcion para mostrar elementos de la pila
void MostrarPila(Pila pila){
	pNodo aux = NULL;
	if(pila == NULL)
		printf("\nNo hay elementos, pila vacia\n");
	else{
		aux = pila;
		printf("\n\t\t*****************************************\n");
		printf("  \t\t**          Mostrando la pila          **\n");
		printf("  \t\t*****************************************\n\n");
		while(aux != NULL){
			printf("\t\t\t\tElemento: %d\n", aux->valor);
			aux = aux->siguiente;
		}
	}
}//Cierra la funcion

//Muestra la longitud de la cola
void Longitud(Pila pila){
	pNodo Aux;
	if(pila != NULL){	
		int cont=0;
		Aux = pila;
		while (Aux!=NULL){
			cont++;
			Aux = Aux->siguiente;
		}
		printf("\n\t\t\tLongitud de la pila es: %d", cont);
	}
	else
	printf("\n\t\t    No hay longitud, la pila esta vacia");
	printf("\n\n");
}

//Menu de opciones
void menu(){
	Pila pila=NULL,fin=NULL;
	int val;
	int op=0;
	do{
		system ("cls");
		printf("\n\n\t\t*****************************************\n");
		printf("\t\t**               PILA                  **\n");
		printf("\t\t*****************************************\n");
		printf("\t\t**         1. INSERTAR (Push)          **\n");
		printf("\t\t**         2. ELIMINAR (Pop)           **\n");
		printf("\t\t**         3. VACIAR PILA              **\n");
		printf("\t\t**         4. MOSTRAR PILA             **\n");
		printf("\t\t**         5. LONGITUD PILA            **\n");
		printf("\t\t**         6. SALIR                    **\n");
		printf("\t\t*****************************************\n");
		printf("\t\t\t\tOpcion: ");               scanf("%d",&op);
		
		switch(op){
			case 1: printf("\n\n\t\t\tNumero a insertar:   ");
					cin>>val;
					Push(&pila, val);
					system ("pause");
					break;
			case 2: printf("\n\t\tSe ha eliminado un elemento de la pila\n\n");
					Pop(&pila,val);
					system ("pause");
					break;
			case 3: printf("\n\t    Todos los elementos de la pila fueron eliminados\n\n");
					while(pila != NULL){
						Pop(&pila,val);
					}
					system ("pause");
					break;
			case 4: system("cls");
					MostrarPila(pila);
					system ("pause");
					break;
			case 5: Longitud(pila);
					system ("pause");
					break;
			case 6: printf("\nSaliendo del programa\n");
					break;
		}		
	}while (op!=6);
}
