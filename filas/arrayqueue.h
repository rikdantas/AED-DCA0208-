#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct arrayqueue {
    int frente;
    int tras;
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arrayqueue* inicializar(int tamArray) {
    struct arrayqueue* fila = (struct arrayqueue*)malloc(sizeof(struct arrayqueue));
    fila -> elementos = (int*)calloc(tamArray, sizeof(int));
    fila->tamanho = tamArray;
    frente = -1;
    tras = -1;
    fila->qtdade = 0;
    return fila;
}

//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayqueue**
//se a fila encher, simplesmente n�o enfileire
void enfileirar(struct arrayqueue** fila, int val) {
    if((*fila) == NULL){
        (*fila) = inicializar(10);
    }

    //Quando a fila n�o tem elementos
    if((*fila)->qtdade == 0){
        (*fila)->frente++;
        (*fila)->elementos[(*fila->qtdade)] = val;
        (*fila)->tras++;
        (*fila)->qtdade++;
    }
    //Quando a fila tem elementos, podendo estar em sua capacidade m�xima ou n�o
    else{
        //Quando a fila tem elementos, mas ainda n�o esta totalmente preenchida
        if((*fila->qtdade) != (*fila)->tamanho){
            (*fila) -> tras++;
            (*fila) -> tras = (*fila) -> tras % (*fila) -> tamanho;
            (*fila) -> elementos[(*fila)->tras] = val;
            (*fila) -> qtdade++;
        }
        //Quando a fila tem elementos e est� totalmente preenchida
        else{
            return;
        }
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if(fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        fila->frente++;
        fila->qtdade--;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if(fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        return fila->frente;
    }
}
