#include "pile.h"
#include <stdbool.h>
#include <stdlib.h>
#define STACKOVERFLOW -1
// création d'une pile
// stack : nom de la pile
// initialStackSize : taille de la pile en nombre de valeurs empilables
void NewStack(Stack **stack, int initialStackSize) {
    // allocation de la structure pile
    *stack= (Stack *) malloc(sizeof(Stack));
    if (*stack != NULL) {
        // allocation du tableau de données
        (*stack)->tab = (int *)malloc(sizeof(int)*initialStackSize);
    if (((*stack)->tab) != NULL) {
        // initialisation des paramètres de la pile
        (*stack)->stackMaxSize = initialStackSize;
        (*stack)->stackNbElemts = 0;
    }
    else {
        // la pile n'a pas pu être créée, stack vaut NULL
        free(*stack);
    *stack = NULL;
    }
    }
}

// teste si la piles est pleine
bool isStackFull(Stack * stack) {
    return((stack->stackNbElemts >= stack->stackMaxSize));
};
// teste si la pile est vide
bool isStackEmpty(Stack *stack) {
    return(stack->stackNbElemts == 0);
}
// pousse une valeur sur la pile
int push(Stack *stack, int value) {
    if (!isStackFull(stack)) {
        stack->tab[stack->stackNbElemts] = value;
        stack->stackNbElemts++;
    return(0);
    }
    else {
        return(STACKOVERFLOW);
    }
}
// récupère la valeur au sommet de la pile
int pull(Stack *stack, int *value) {
    if (!isStackEmpty(stack)) {
        *value=stack->tab[stack->stackNbElemts -1];
        stack->stackNbElemts--;
        // COMPLETER LE CODE ICI ************************
        
        return(EXIT_SUCCESS);
    }
    return(EXIT_FAILURE);
    }

int peek(Stack *stack, int *value) {
    if (!isStackEmpty(stack)) {
        // COMPLETER LE CODE ICI ************************
        *value=stack->tab[stack->stackNbElemts -1];
        return(EXIT_SUCCESS);
    }
    return(EXIT_FAILURE);
    }
    
int retourne(Stack *stack,Stack *news){
    int value;
    Stack  tmp=*stack;
    int tours =stack->stackNbElemts;
    for(int i=0;i<tours;i++){
        pull(&tmp, &value);
        push(news, value);  
    }
    return(EXIT_SUCCESS);
}

void NewQueue(Queue **queue, int initialQueueSize) {
    *queue = (Queue *)malloc(sizeof(Queue));
    if (*queue != NULL) {
        (*queue)->tab = (int *)malloc(sizeof(int)*initialQueueSize);
        if (((*queue)->tab) != NULL) {
            for (int i = 0; i < initialQueueSize; i++) (*queue)->tab[i] = 0;
            (*queue)->first = -1;
            (*queue)->last = -1;
            (*queue)->queueNbElemt = 0;
            (*queue)->queueMaxSize = initialQueueSize;
        }
        else {
            free(*queue);
            *queue = NULL;
    }
}
}
bool isQueueEmpty(Queue *queue) {
    return(queue->queueNbElemt == 0);
}
bool isQueueFull(Queue *queue) {
    return(queue->queueNbElemt == queue->queueMaxSize);
}
// Ajout d'un élément dans la file
int queue(Queue *queue, int value) { // gestion de la file en tableau circulaire
    // si la file est pleine, on ne fait rien
    if (isQueueFull(queue)) return(EXIT_FAILURE);
    // si la file est vide
    // écriture du premier élément dans la file
    if (isQueueEmpty(queue)) {
        queue->first = 0;
        queue->last = 0;
        queue->queueNbElemt = 1;
        queue->tab[queue->last] = value;
        } 
    else {
        queue->last++;
        queue->last=queue->last%queue->queueMaxSize;
        queue->queueNbElemt ++;
        queue->tab[queue->last] = value;
        // écriture d'un élément dans la file
        // COMPLETER ICI
        // calculer la position du prochain élément et le stocker
    }

    return(EXIT_SUCCESS);
}

// Sortie d'un élément de la file

int deQueue(Queue *queue, int *value) {
    if(isQueueEmpty(queue)) return(EXIT_FAILURE);
    *value=queue->tab[queue->first];
    queue->queueNbElemt--;
    queue->first++;
    queue->first%=queue->queueMaxSize;
    return(EXIT_SUCCESS);
}