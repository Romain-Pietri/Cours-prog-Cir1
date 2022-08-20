#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <time.h>

typedef struct Node{
    int datan;
    struct Node * g;
    struct Node * d;
    struct Node * p;

}Node;
typedef struct Arbre{
    Node * racine;
    int nbelem;
}Arbre;


typedef struct SingleLinkedListElem {
    Node * data; // donnée utile stocké dans le maillon
    struct SingleLinkedListElem *next; // pointeur vers le maillon suivant
} SingleLinkedListElem;

typedef struct LinkedList {
    SingleLinkedListElem *head; // pointeur vers la tête de liste
    int size;
    SingleLinkedListElem *tail; // pointeur vers la queue de liste
} LinkedList;


typedef struct Queue{   
    LinkedList * list;
}Queue;


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

SingleLinkedListElem *NewLinkedListItem(Node * value) {
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
int inqueue(Queue *q, Node * value){
    if(q==NULL) return 1;
    SingleLinkedListElem *tmp= NewLinkedListItem(value);
    AddNewElemToSingleLinkedList(q->list, tmp);
    return 0;
}
Node * dequeue(Queue *q){
    if(q==NULL || q->list->head==NULL) return NULL;
    Node * v=q->list->head->data;
    RemoveElemFromSingleLinkedList(q->list, q->list->head);
    return v;
}

Arbre *NewArbre() {
    Arbre *tmp;
    tmp =(Arbre*)malloc(sizeof(Arbre));
    if (tmp != NULL) {
        tmp->racine = NULL;
        tmp->nbelem = 0;
    }
    return tmp;
}
Node *Newnode(int value) {
    Node *tmp;
    tmp = (Node *) malloc(sizeof(Node));
    if (tmp != NULL) {
    tmp->datan = value;
    tmp->g = NULL;
    tmp->d= NULL;
    }
    return(tmp);
}
void addelem_( Node* n,Node* item){
    if(item->datan==n->datan) return;
    if(item->datan<n->datan){
        if(n->g==NULL) {n->g=item; return;}
        addelem_(n->g, item);
        return;
    }
    else{
        if(n->d==NULL) {n->d=item; return;}
        addelem_(n->d, item);
        return;
    }
}
int addelemR(Arbre *A, Node* item){
    if(A==NULL) return 0;
    if(A->racine==NULL){A->racine=item; return 1; }
    addelem_(A->racine,item);
    
    return 1;
}
void display_(Node *n){
    if(n==NULL) return;
    //printf("%d |",n->data);
    display_(n->g);
    printf("%2d |",n->datan);
    display_(n->d);
    //printf("%d |",n->data);
}

void display(Arbre *A){
    if(A==NULL || A->racine==NULL) return;
    display_(A->racine);
    printf("\n");
}


void largeur(Arbre * A){
    Queue * Q;
    Node * x;
    NewQueue(&Q);
    inqueue(Q,A->racine);
    while(!isQueueEmpty(Q)){
        x=dequeue(Q);
        printf("%2d |",x->datan);
        if(x->g!=NULL){inqueue(Q,x->g);}
        if(x->d!=NULL){inqueue(Q,x->d);}
    }
    printf("\n");
    
}

int main(){
    printf("\n\n");
    Arbre* A=NewArbre();
    srandom(time(NULL));
    int a;
    printf("Valeurs : \t");
    for(int i=0; i<10;++i){
        a=random()%101;
        printf(" %d ",a);
        addelemR(A,Newnode(a));
    }
    printf("\nParcourt infixe/Pronfondeur :\t");
    display(A);
    printf("Parcourt largeur : \t");
    largeur(A);
    printf("\n\n");
}