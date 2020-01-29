#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct _nodo{
	int valor;
	struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo, *Cola;

/*Funciones con colas: */
void insertar (Cola *cola,Cola *fin, int num);
int sacar(Cola *cola,Cola *fin, int num);
void MostrarCola(Cola cola);
void Longitud(Cola cola);
void menu();

int main(){
	menu();
	system("PAUSE");
	return 0;
}

//Insertar numeros a la cola
void insertar(Cola *cola,Cola *fin,int num){
	pNodo nuevo=NULL;
	//Crear un nodo nuevo
	nuevo=(pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor = num;
	if(nuevo!=NULL){
		if(*cola==NULL){
			//Es el primer nodo de la lista
			*cola=nuevo;
		}else{
			//Inserciones al final de la cola
			(*fin)->siguiente=nuevo;
		}
		//para terminar las inserciones
		*fin=nuevo;
		nuevo->siguiente=NULL;
		nuevo=NULL;
	}else
		printf("\nNo se pudo insertar en la cola\n");
}//Cierre de la funcion

//Eliminar elemento o elementos de la cola
int sacar(Cola *cola,Cola *fin, int num){
	pNodo aux=NULL; //variable auxiliar para manipular nodo
	//int v=0;		//variable auxiliar
	aux=*cola;
	if(aux==NULL)
		return 0; //Si no hay nodos en la cola retornamos 0
	else{
		if(*cola!=*fin)
			*cola=aux->siguiente;
		else{
			*cola=NULL;
			*fin=NULL;
		}
		num=aux->valor;
		free(aux);
		return num;
	}//fin else
}

//Mostrar elementos de la cola
void MostrarCola(Cola cola){
	pNodo aux=NULL;
	aux=cola;
	if(cola==NULL)
		printf("\nNo hay elementos, cola vacia\n");
	else{
		printf("\n\t\t*****************************************\n");
		printf("  \t\t**          Mostrando la cola          **\n");
		printf("  \t\t*****************************************\n\n");
		while(aux!=NULL){
			printf("\t\t\t\tElemento: %d\n",aux->valor);
			aux=aux->siguiente;
		}
	}
}

//Muestra la longitud de la cola
void Longitud(Cola cola){
	pNodo Aux;
	if(cola != NULL){	
		int cont=0;
		Aux = cola;
		while (Aux!=NULL){
			cont++;
			Aux = Aux->siguiente;
		}
		printf("\n\t\t\tLongitud de la cola es: %d", cont);
	}
	else
		printf("\n\t\t    No hay longitud, la cola esta vacia");
	printf("\n\n");
}

//Menu de opciones
void menu(){
	Cola cola=NULL,fin=NULL;
	int val;
	int op=0;
	do{
		system ("cls");
		printf("\n\n\t\t*****************************************\n");
		printf("\t\t**               COLA                  **\n");
		printf("\t\t*****************************************\n");
		printf("\t\t**         1. INSERTAR (Encolar)       **\n");
		printf("\t\t**         2. ELIMINAR (Desencolar)    **\n");
		printf("\t\t**         3. VACIAR COLA              **\n");
		printf("\t\t**         4. MOSTRAR COLA             **\n");
		printf("\t\t**         5. LONGITUD COLA            **\n");
		printf("\t\t**         6. SALIR                    **\n");
		printf("\t\t*****************************************\n");
		printf("\t\t\t\tOpcion: ");               scanf("%d",&op);
		
		switch(op){
			case 1: printf("\n\n\t\t\tNumero a encolar:   ");
					cin>>val;
					insertar(&cola,&fin,val);
					system ("pause");
					break;
			case 2: printf("\n\t\tSe ha eliminado un elemento de la cola\n\n");
					sacar(&cola,&fin,val);
					system ("pause");
					break;
			case 3: printf("\n\t    Todos los elementos de la cola fueron eliminados\n\n");
					while(cola != NULL){
						sacar(&cola,&fin,val);
					}
					system ("pause");
					break;
			case 4: system("cls");
					MostrarCola(cola);
					system ("pause");
					break;
			case 5: Longitud(cola);
					system ("pause");
					break;
			case 6: printf("\nSaliendo del programa\n");
					break;
		}		
	}while (op!=6);
}
