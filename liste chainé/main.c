#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SingleLinkedListElem {
    int data; // donnée utile stocké dans le maillon
    struct SingleLinkedListElem *next; // pointeur vers le maillon suivant
} SingleLinkedListElem;

typedef struct LinkedList {
    SingleLinkedListElem *head; // pointeur vers la tête de liste
    int size;
    SingleLinkedListElem *tail; // pointeur vers la queue de liste
} LinkedList;

LinkedList *NewLinkedList() {
    LinkedList *tmp;
    tmp =(LinkedList*)malloc(sizeof(LinkedList));
    if (tmp != NULL) {
        tmp->head = NULL;
        tmp->tail = NULL;
        tmp->size = 0;
    }
    return tmp;
}

SingleLinkedListElem *NewLinkedListItem(int value) {
    SingleLinkedListElem *tmp;
    tmp = (SingleLinkedListElem *) malloc(sizeof(SingleLinkedListElem));
    if (tmp != NULL) {
    tmp->data = value;
    tmp->next = NULL;
    }
return(tmp);}

int AddNewElemToSingleLinkedList(LinkedList *list ,SingleLinkedListElem * elem) {
    if (list == NULL || elem == NULL || elem->next!=NULL) return 0;
    // si la liste est vide
    if (list->tail == NULL) {
        list->tail = elem;
        list->head = elem;
        list->size = 1;
    }
    else {
        // on ajoute l'élément en fin
        list->tail->next = elem;
        list->tail = elem;
        list->size += 1;
        }
    return 1;}

int RemoveElemFromSingleLinkedList(LinkedList *list, SingleLinkedListElem * elem) {
    // on peut traiter un certain nombre de cas d'erreur
    // La liste n'existe pas
    if (list == NULL) return(0);
    // liste vide ou anomalie
    if ((list->head == NULL) || (list->tail == NULL)) return(0);
    // anomalie sur la taille
    if ((list->head == list->tail) && (list->size != 1)) return(0);
    // pas d'élément dans la liste ou elem invalide
    if ((list->size == 0) || (elem == NULL)) return(0);
    // initialisation d'un pointeur sur l'élément courant
    SingleLinkedListElem *tmp = list->head;
    // previous désigne l'élément qui précède l'élément courant
    SingleLinkedListElem *previous = NULL;
    // l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste
    if ((elem == list->head) && (elem == list->tail)) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        free(elem);
        return(1);
    }
    // il est en tête, on supprime la tête
    if (elem == list->head) {
        list->head = elem->next;
        list->size--;
        free(elem);
        return(1);
    }// Recherche du maillon dans le reste de la liste chaînée
    while ((tmp != NULL) && (tmp != elem)) {
        previous = tmp;
        tmp = tmp->next;
    }
    // s'il est en queue, on supprime la queue
    if ((previous != NULL) && (tmp == elem) && (tmp->next==NULL)) {
        list->tail = previous;
        previous->next = NULL;
        list->size--;
        free(elem);
        return(1);
    }
    // s'il est au milieu, on supprime l'élément
    if ((previous !=NULL) && (tmp == elem) && (tmp->next!=NULL)) {
        previous->next = elem->next;
        list->size--;
        free(elem);
        return(1);
    }
    // l'élément recherché n'a pas été trouvé
    return(0);
}

void _displaylist(SingleLinkedListElem* elm){
    printf("%3d |",elm->data);
    if(elm->next!=NULL)  _displaylist(elm->next);
    return;
}

void Displaylist(LinkedList * liste){
    if (liste == NULL || liste->head==NULL) return;
    _displaylist(liste->head);
    printf("\n");
}

void Initrand(LinkedList * list, int listsize){
    for (int i = 0; i < listsize; ++i) {
        SingleLinkedListElem * elem = NewLinkedListItem(rand()%20);
        // ajout du maillon à la liste
        AddNewElemToSingleLinkedList(list, elem);
    }
}

SingleLinkedListElem * getelement(LinkedList *list, int pos){
    if(pos>list->size) return NULL;
    SingleLinkedListElem * tmp=list -> head;
    for(int i=1;i<pos;++i){
        tmp=tmp->next;
    }
    return tmp;
}

int insertelmhead(LinkedList * list, SingleLinkedListElem * elm1){
    if(list==NULL) return 0;
    if(list->head==NULL){list->size=1; list->tail=elm1;}
    else{
        elm1->next=list->head;
        list->head=elm1;
        list->size++;
    }
    return 0;
}

int swapLinked(LinkedList * list, SingleLinkedListElem * elm1,SingleLinkedListElem * elm2){
    if(list->head==NULL && elm1!=elm2){return 0;}
    SingleLinkedListElem * tmp=list->head;
    bool verif1,verif2=true;
    int pos1,pos2;
    for(int i=1;i<list->size+1;++i){
        if(tmp==elm1){verif1=true; pos1=i;}
        if(tmp==elm2){verif2=true; pos2=i;}
        tmp=tmp->next; 
    }
    if(verif1!=verif2 && verif1!=true) return 0;
    tmp=list->head;


    if(elm1 !=list->head && elm2!=list->head){
        
        int j=0;
        SingleLinkedListElem *tmp1=elm1->next;
        SingleLinkedListElem *tmp2=elm2->next;
        while(tmp!=NULL){
            if(j==pos1-1){elm2->next=tmp1; tmp->next=elm2;}
            if(j==pos2-1){elm1->next=tmp2; tmp->next=elm1;}
            ++j;
            tmp=tmp->next;
        }
    }
    if(elm2==list->head) return swapLinked(list,elm2, elm1);
    if(elm1==list->head){
        SingleLinkedListElem *tmp1=elm1->next;
        SingleLinkedListElem *tmp2=elm2->next;
        while(tmp!=NULL){
            if (tmp->next==elm2){
                tmp->next=elm1;
                elm1->next=tmp2;
                elm2->next=tmp1;
                list->head=elm2;
            }
            tmp=tmp->next;
        }
    }
    

    return 1;
}

int concactLinked(LinkedList*list, LinkedList *l1, LinkedList *l2){
    if(l1->head==NULL || l2->head==NULL)return 0;
    list->head=l1->head;
    SingleLinkedListElem * tmp=list->head;
    while(tmp->next!=NULL){tmp=tmp->next;}
    tmp->next=l2->head;
    list->tail=l2->tail;
    list->size=l1->size+l2->size;
    return 1;
}
/*
int main(){
    LinkedList *MyListe2 = NewLinkedList();
    LinkedList *MyListe1 = NewLinkedList();
    LinkedList *MyListe = NewLinkedList();
    // Ajout des valeurs 10-20-30 .. à la liste
    Initrand(MyListe2, 20);
    Initrand(MyListe1, 10);

for(int i=0;i<list->size+1;++i){
            if(tmp==elm1){verif1=true; pos1=i;}
            if(tmp==elm2){verif2=true; pos2=i;}
            tmp=tmp->next; 
        }
        if(verif1!=verif2 && verif1!=true) return 0;
        tmp=list->head;
    //Displaylist(MyListe2);
    //insertelmhead(MyListe2,getelement(MyListe1,2));
    //Displaylist(MyListe2);


    Displaylist(MyListe2);
    swapLinked(MyListe2,getelement(MyListe2, 10),getelement(MyListe2, 1));

    //Displaylist(MyListe1);
    Displaylist(MyListe2);
    //concactLinked(MyListe,MyListe1,MyListe2);
    //Displaylist(MyListe);
}*/







//pile chainé

typedef struct Stack{
    LinkedList * list;
}Stack;


void NewStack(Stack **stack){
    *stack= (Stack *) malloc(sizeof(Stack));
    if (*stack != NULL) {
        (*stack)->list=NewLinkedList();}
    else{free(*stack);}
}
int isStackEmpty(Stack *stack){
    if(stack->list->size==0) return 1;
    return 0;
}
int push(Stack *stack, int value){
    if(stack==NULL) return 1;
    SingleLinkedListElem *tmp= NewLinkedListItem(value);
    AddNewElemToSingleLinkedList(stack->list, tmp);
    return 0;
}
int pull(Stack *stack, int *value){
    if(stack==NULL || stack->list->tail==NULL) return 1;
    *value=stack->list->tail->data;
    RemoveElemFromSingleLinkedList(stack->list, stack->list->tail);
    return 0;
}
int stackpeek(Stack *stack, int *value){
    if(stack==NULL || stack->list->tail==NULL) return 1;
    *value=stack->list->tail->data;
    return 0;
}
//File chainé

typedef struct Queue{   
    LinkedList * list;
}Queue;


void NewQueue(Queue **q){
    *q= (Queue *) malloc(sizeof(Queue));
    if (*q != NULL) {
        (*q)->list=NewLinkedList();}
    else{free(*q);}
}
int isQueueEmpty(Queue *q){
    if(q->list->size==0) return 1;
    return 0;
}
int inqueue(Queue *q, int value){
    if(q==NULL) return 1;
    SingleLinkedListElem *tmp= NewLinkedListItem(value);
    AddNewElemToSingleLinkedList(q->list, tmp);
    return 0;
}
int dequeue(Queue *q, int *value){
    if(q==NULL || q->list->head==NULL) return 1;
    *value=q->list->head->data;
    RemoveElemFromSingleLinkedList(q->list, q->list->head);
    return 0;
}
int queuepeek(Queue *q, int *value){
    if(q==NULL || q->list->head==NULL) return 1;
    *value=q->list->head->data;
    return 0;
}
/*
int main(){
    Queue *s;
    NewQueue(&s);
    
    for(int i =0;i<10;++i){
        printf("%d |",i);
        inqueue(s, i);
    }
    int v;
    for(int i =0;i<10;++i){
        dequeue(s, &v);
        printf("\n%d ",v);
    }

}*/