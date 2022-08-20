#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define lgtab 1047138


void init(int tab[lgtab]){
    for(int i =0; i<lgtab;++i){
        tab[i]=rand()%1000;
    }
}

void initinv(int tab[lgtab]){
    for(int i=0;i<lgtab;++i){
        tab[i]=lgtab-i;
    }
}

void initgood(int tab[lgtab]){
        for(int i=0;i<lgtab;++i){
        tab[i]=i;
    }
}


void affiche(int tab[lgtab]){
    for(int i=0; i<lgtab;++i){
        printf("%d, ",tab[i]);
    }
    printf("\n");
}

void tri_naif(int tab[lgtab]){
    clock_t begin = clock();
    unsigned n=0;
    int temp;
    unsigned perm=0;
    for(int i=0;i<lgtab;i++){
        for(int j=1;j<lgtab;++j){
            if(tab[j-1]>tab[j]){
                temp=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=temp;
                ++perm;
            }
            ++n;
        }
    }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("La fonction a executé %u itération, pour %u permutation pour une durée de %f sec\n",n,perm,time_spent);
}

void buble_sort(int tab[lgtab]){
    clock_t begin = clock();
    unsigned int n=0;
    unsigned perm = 0;
    int temp;
    for(int i=0;i<lgtab;++i ){
        for(int j=lgtab-1;j>i;--j){
            if(tab[j-1]>tab[j]){
                temp=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=temp;
                ++perm;
            }
            ++n;
        }
    }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("La fonction a executé %u itération, pour %u permutation pour une durée de %f sec\n",n,perm,time_spent);
}

/*
int plusepetit(int tab[lgtab],int ind,int * u){
    int mini=tab[ind];
    printf("%d\n",mini);
    for(int j=ind;j<lgtab;++j){
        u++;
        if(tab[j]<tab[mini]){
            mini=j;
            }
    }
    return mini;
}
*/
void triselec(int tab[lgtab]){
    clock_t begin = clock();
    int temp;
    int mini;
    int n=0;
    int comp=0;
    for(int i=0;i<lgtab;++i){
        n++;
        mini=i;
        for(int j=i;j<lgtab;++j){
            n++;
            if(tab[j]<tab[mini]){
                comp++;
                mini=j;
                }
         }  
        temp=tab[i];
        tab[i]=tab[mini];
        tab[mini]=temp;
    }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("La fonction a executé %u itération, pour %u comparaison pour une durée de %f sec\n",n,comp,time_spent);
}
void tri_insert(int tab[lgtab]){
    clock_t begin = clock();
        int n=0;
        int comp=0;
        int tmp;
        int j;
        for(int i=0; i<lgtab;++i){
            tmp=tab[i];
            j=i;
            ++n;
            ++comp;
            while(j>0 && tab[j]>tab[j-1]){
                ++n;
                tab[j]=tab[j-1];
                j--;
            }   
            tab[j]=tmp;
        }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("La fonction a executé %u itération, pour %u comparaison pour une durée de %f sec\n",n,comp,time_spent);
}


int rang(int tab[lgtab], int min, int max, int val,int * u){
    //printf("%d | %d \n",min,max);
    (*u) ++;
    int m=(min+max)/2;
    //printf("%d |%d \n",m,max-min);
    if(max==min){return min;}
    
    if(tab[m]<val) return rang(tab,m+1,max,val,u);
    else return rang(tab,min,m,val,u);
}


void tri_insert_dico(int tab[lgtab]){
    clock_t begin = clock();
    int n=0;
    int comp=0;
    int tmp;
    int a;
    int j;
    for(int i=0; i<lgtab;++i){
        tmp=tab[i];
        ++n;++comp;
        j=i;
        a=rang(tab,0,i,tmp,&n);
        while(j>a){
            ++n;
            tab[j]=tab[j-1];
            j--;
        }   
        tab[j]=tmp;
    }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("La fonction a executé %u itération, pour %u comparaison pour une durée de %f sec\n",n,comp,time_spent);
}
void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}



void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}
  
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}
int main(){
    int tab[lgtab] ; int tmp[lgtab];
    /*initinv(tab);
    clock_t begin = clock();
    triRapid(tab,0,lgtab-1);
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("durrée : %f\n",time_spent);
    affiche(tab);*/
    initinv (tab);
    tri_insert(tab);
    affiche(tab);
    //clock_t begin1 = clock();
    //triFusion(0,lgtab-1,tab,tmp);  
    //clock_t end1 = clock();
    //float time_spent1 = (float)(end1 - begin1) / CLOCKS_PER_SEC;
    //printf("durrée : %f\n",time_spent1);
}   