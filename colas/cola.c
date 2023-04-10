// Sergio Sanchez Garcia  70961594Q
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
	if(c == NULL){
		fprintf(stderr,"Fallo precondición cola no existente!\n");
		return -1;
	}
	else{
    	c->fondo = NULL;
		c->frente = NULL;
 	   return 0;
	}
}

int colaVacia(Cola *c)
{
	if(c == NULL){
		fprintf(stderr,"Fallo precondición cola no existente!\n");
		return -1;
	}
    else if(c->fondo == NULL && c->frente == NULL)
    	return 1;
	else
		return 0;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    tipoCelda *nuevo;
	
	if(c == NULL){
		fprintf(stderr,"Fallo precondición cola no existente!\n");
		return -1;
	}
	else if(NULL == (nuevo = (tipoCelda *)malloc(sizeof(tipoCelda)))){
		fprintf(stderr,"Fallo reserva memoria!\n");
		return -2;
	}
	else{
		nuevo->elemento = elemento;
		nuevo->sig = NULL;
		if(colaVacia(c)){
			c->fondo = nuevo;
			c->frente = nuevo;
		}
		else{
			c->fondo->sig = nuevo;
			c->fondo = nuevo;
		}
		return 0;
	}
}

tipoElemento colaSuprime(Cola *c)
{
	tipoCelda *aBorrar;
	tipoElemento elemento;
	
	if(c == NULL){
		fprintf(stderr,"Fallo precondición cola no existente!\n");
		return -1;
	}
	else if(colaVacia(c)){
		fprintf(stderr,"Fallo la cola ya esta vacía!\n");
		return -2;
	}
	else{
		elemento = c->frente->elemento;
		aBorrar = c->frente;
		c->frente = c->frente->sig;
		free(aBorrar);
		aBorrar = NULL;
		if(c->frente == NULL){
			c->frente = NULL;
			c->fondo = NULL;
		}
    	return elemento;
	}
}
