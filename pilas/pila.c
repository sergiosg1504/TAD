// Sergio Sanchez Garcia  70961594Q
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
	if(p == NULL ){
		fprintf(stderr,"Fallo precondición pila no existente!\n");
		return -1;
	}
	else{
    	*p = NULL;
		return 0;
	}
}

int pilaVacia(Pila *p)
{
	if(p == NULL){
		fprintf(stderr,"Fallo precondición pila no existente!\n");
		return -1;
	}
	else if(*p == NULL)
		return 1;
	else
		return 0;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
	tipoCelda *nuevo;
	
	if(p == NULL){
		fprintf(stderr,"Fallo precondición pila no existente!\n");
		return -1;
	}
    else if(NULL == (nuevo = (tipoCelda *)malloc(sizeof(tipoCelda)))){
		fprintf(stderr,"Fallo reserva memoria!\n");
    	return -2;
    }
	else{
		nuevo->elemento = elemento;
		nuevo->sig = *p;
		*p = nuevo;
		return 0;
	}
}

tipoElemento pilaSuprime(Pila *p)
{
	tipoElemento elemento;
	Pila aBorrar;
	
	if(p == NULL){
		fprintf(stderr,"Fallo precondición pila no existente!\n");
		return -1;
	}
	else if(pilaVacia(p)){
		fprintf(stderr,"Fallo la pila ya esta vacía!\n");
		return -2;
	}
	else{
		aBorrar = *p;
		elemento = aBorrar->elemento;
		*p = aBorrar->sig;
		free(aBorrar);
		aBorrar = NULL;
		return elemento;
	}
}
