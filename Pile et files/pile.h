#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<locale.h>
#include<stdbool.h>// définition du symbole de dépassement de pile

#define STACKOVERFLOW -1// définition d'une pile à l'aide d'une structure
typedef struct Stack{
    int*tab;// le tableau de données qu'il faut allouer
    int stackMaxSize;  // taille max
    int stackNbElemts; // nb d'éléments actuellement dans la pile
} Stack;// implémentation des Piles avec des tableaux dynamiques
// création d'un pile
void NewStack(Stack**stack, int initialStackSize);bool isStackFull(Stack* stack);bool isStackEmpty(Stack*stack);int push(Stack*stack, int value);int pull(Stack*stack, int*value);int peek(Stack*stack, int*value);int retourne(Stack *stack,Stack *news);
typedef struct Queue {
    int *tab; // Pointer towards dynamically allocated array
    int first; // index of the first element in the array
    int last; // index of the last element in the array
    int queueMaxSize; // maximum number of elements in the Queue
    int queueNbElemt; // current count of elements in the Queue
} Queue;
void NewQueue(Queue **queue, int initialQueueSize);
// teste si la file est vide
bool isQueueEmpty(Queue *queue);
// teste si la file est pleine
bool isQueueFull(Queue *queue);
// ajoute un élément dans la file
int queue(Queue *queue, int value);
// sort un élément de la file
int deQueue(Queue *queue, int *value);