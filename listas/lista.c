// Sergio Sanchez Garcia  70961594Q
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}

void imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


// Funciones a implementar

tipoPosicion primero(Lista *l)
{	
	if (l == NULL) {
	    fprintf(stderr,"Fallo precondición lista no existente!\n");
	    return NULL;
	}
	else if (l->raiz == NULL) {
	    fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
	    return NULL;
	}
	else
		return l->raiz;
}

tipoPosicion fin(Lista *l)
{
	if (l == NULL) {
	    fprintf(stderr,"Fallo precondición lista no existente!\n");
	    return NULL;
	}
	else if (l->raiz == NULL) {
	    fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
	    return NULL;
	}
	else
		return l->ultimo;
}

int inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
	tipoCelda *nuevo;
	
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
	}
    else if (p == NULL){
		fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
	}
    else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))){
		fprintf(stderr,"Fallo reserva memoria!\n");
        return -4;
	}
    else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == fin(l))
            l->ultimo = nuevo;
        return 0;
    }
}

int suprime (tipoPosicion p, Lista *l)
{
	tipoPosicion aBorrar;
	
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
	}
    else if (p == NULL){
		fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
	}
	else{
		aBorrar = p->sig;
		p->sig = aBorrar->sig;
		if(p->sig == NULL)
			l->ultimo = p;
		free(aBorrar);
		aBorrar = NULL;
		return 0;
	}
}

tipoPosicion siguiente(tipoPosicion p,Lista *l)
{
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return NULL;
	}
    else if (p == NULL){
		fprintf(stderr,"Fallo precondición posición no válida!\n");
        return NULL;
	}
	else if(p == fin(l))
		return fin(l);
	else
		return p->sig;
}

tipoPosicion localiza (tipoElemento x, Lista *l)
{
	tipoPosicion q;
	
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return NULL;
	}
	else{
		q = l->raiz;
		while(q->sig != NULL){
			if(q->elemento == x)
				return q;
			q = q->sig;
		}
		return fin(l);
	}
}

tipoElemento recupera(tipoPosicion p, Lista *l)
{
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
	}
    else if (p == NULL || p == fin(l)){
		fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
	}
	else
		return p->sig->elemento;
}

int anula(Lista *l)
{
    tipoPosicion aBorrar, aux;
	
    if (l == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
	}
    else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
	}
	else{
		aux = l->raiz->sig;
		while(aux != NULL){
			aBorrar = aux;
			aux = aux->sig;
			free(aBorrar);
			aBorrar = NULL;
		}
		l->ultimo = l->raiz;
		return 0;
	}
	
}

int concatena(Lista *lA, Lista *lB)
{
    if (lA == NULL){
		fprintf(stderr,"Fallo precondición lista lA no existente!\n");
        return -1;
	}
	if (lA->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio de la lista lA no existente!\n");
		return -2;
	}
	if (lB == NULL){
		fprintf(stderr,"Fallo precondición lista lB no existente!\n");
		return -3;
	}
	if (lB->raiz == NULL){
		fprintf(stderr,"Fallo precondición nodo ficticio de la lista lB no existente!\n");
		return -4;
	}
	else{
		lA->ultimo->sig = lB->raiz->sig;
		lA->ultimo = lB->ultimo;
		lB->raiz->sig = NULL;
		lB->ultimo = lB->raiz;;
		return 0;
	}
}