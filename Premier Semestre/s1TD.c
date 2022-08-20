#define SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*
int main(){
    int AB=0;

    int AC=0;

    int BC=0;

    printf("AB ?");

    scanf("%d",&AB);

    printf("AC ?");

    scanf("%d",&AC);

    printf("BC ?");

    scanf("%d",&BC);

    if(AB<AC+BC && AC<AB+BC && BC<AC+AB){
        printf("Le triangle ABC est possible \n");

    }
    else{
        printf("le triangle ABC n'est pas possible \n");


    }
}
*/
/*
int main(){
    int a=0;

    int b=0;

    int c=0;

    float delta=0;

    float s=0;

    printf("rentrez votre équation du type ax²+bx+c \n");

    printf("a ?");

    scanf("%d",&a);


    printf("b ?");

    scanf("%d",&b);


    printf("c ?");

    scanf("%d",&c);

    delta=(b*b)-4*a*c;

    if ( delta >=0){
        s=sqrtf(delta);

        printf("Premiere racine \n");

        printf("%f",(-b+s)/2*a);

        printf("\n deuxieme racine \n");

        printf("%f",(-b-s)/2*a);

        printf("\n")
    }
    else{
        printf("il n'y a pas de solution reel");

    }
    return 0;

}

*/
/*
int main(){
    long long sec ;

    int sexe, age, cle, cle2 ,annee, siecle;
 
    bool valid =true;
 
    time_t t =time(NULL);

    struct tm tm =*localtime(&t);

    int anneeactuel = (int)tm.tm_year;

    printf("veuillez saisir le num secu\n");

    scanf("%lld",&sec);

    printf("clé ? ");

    scanf("%d",&cle);

    
    cle2=97-(int)(sec%97);

    if (cle==cle2){
        valid=true;

        valid=(cle==(97-(int)(sec%97)));

    }
    if(valid){
        sexe=(int)(sec/1000000000000);

        sec-=sexe*1000000000000;

        annee=(int)(sec/10000000000);

        printf("siecle ?");

        scanf("%d",&siecle);

        annee+=siecle;

        age=anneeactuel-annee;

        print("%d",age);

    }


}
*/
/*
int main(){
    int nb=1;

    int nombre=0;

    float moy=0;

    int sum =0;

    printf("cb de val ? ");

    scanf("%d",&nb);

    for (int i =0 ;
 i<nb ;
 i++ ){
        scanf("%d",&nombre);

        sum+=nombre;

    }
    moy=sum/nb;

    printf("%f",moy);

    return moy;

}
*/
/*
int main(){
    int nb=0;

    int nombre=0;

    float moy=0;

    int sum =0;

    while (nombre!=-1){
            printf("val ? \n");

            scanf("%d",&nombre);

            if (nombre!=-1){sum+=nombre;
nb++;
}
        }
        moy=sum/nb;

        printf("\n%f\n",moy);

    return moy;

}
*/

/*
int main(){
    float somme;

    float temp;

    float inte;

    int nb=0;

    printf("rentrer le montant de la somme que vous voulez placer \n");

    scanf("%f",&somme);

    printf("rentrer le taux d'intéret \n");

    scanf("%f",&inte);

    temp=somme;

    printf("Capital: %f taux : %f \n",temp,inte);

    while (temp<=2*somme)
    {
        nb+=1;
      
        temp=temp*(1+(inte/100));

        printf("an %d : %f euros \n",nb,temp);

    }
    printf("votre capital aura doublé au bout de %d ans",nb);

}

*/
/*
int main(){
   int var=0;

   printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F  \n");

   for(int i=0 ;
 i<=7;
 i++){
       printf("%d ",i);

       
       for(int j=0 ;
 j<16 ;
j++){
           var=i*16+j;

           if(var>=32){
           printf(" %c ",var);
}
       }
    printf("\n");

   } 
   return 0;

}
*/
/*
int main(){
    float tab[100]={0.0};

    int nb=0;

    int compt=0;

    int val;

    int ou;

    int ind;

    scanf("%d",&nb);

    while (nb>=0)
    {
        scanf("%d",&nb);

        compt++;


    }
    printf("%d \n",compt);

    
    for(int i =0;
i<100 ;
i++){
        if(i!=0 &&i%10==0){
            printf("\n");

        }
        
        printf("%.2F,",tab[i]);

        
    }

    printf("Ou voulez vous inserer votre valeur ?");

    scanf("%d",&ou);

    printf("Quel est la valeurs que vous voulez inserer ?");

    scanf("%f",&val);

    if(ou>=0 && ou<100){
        tab[ou]=val;
    
    }
    for(int i =0;
i<100 ;
i++){
        if(i!=0 &&i%10==0){
            printf("\n");

        }
        
        printf("%.2F ,",tab[i]);

    }
    printf("\n quel est l'indice de l'élément a supprimer ?");

    scanf("%d",ind);

    if(ind>=0 && ind<100){
        tab[ind]=0.0;

    }
    for(int i =0;
i<100 ;
i++){
        if(i!=0 &&i%10==0){
            printf("\n");

        }
        
        printf("%.2F ,",tab[i]);

    }
    float sum=0;

    for(int i =0;
i<100 ;
i++){
        sum+=tab[i];

    }
    printf("%f",sum/100);


}
*/
/*

int main(){
    int tab[10][10];

    for(int i=0;
 i<10;
i++){
        for(int j=0;
j<10;
 j++){
            tab[i][j]=rand() % 20+1;

        }
    }
    
    for(int i=0;
i<10;
i++){
        printf("[");

        for(int j=0;
j<10;
j++){
            printf("%d, ",tab[i][j]);

        }
        printf("]\n");

    }
    
    int tab2[10][10];

    for(int i=0;
 i<10;
i++){
        for(int j=0;
j<10;
 j++){
            tab2[i][j]=tab[j][i];

        }
    }
    printf("\n\n");

    for(int i=0;
i<10;
i++){
        printf("[");

        for(int j=0;
j<10;
j++){
            printf("%d, ",tab2[i][j]);

        }
        printf("]\n");

    }
}
*/
/*
int somme(int n){
    if(n >= 0){
        return n*(n+1)/2;

    }
    return -1;

}
int main(){
    int a;

    int s;

    printf("donner une valeur de a :\n ");

    scanf("%d",&a);

    s=somme(a);

    printf("%d",s);

    return 0;

}
*/
/*
#define size 100
float tab[size];


int remplirTAB(float tab[], int tabSize, int nbVal, float min, float max){
    stand(time(NULL));

    if(nbVal>=0){
        for(int i=0;
 i<tabSize;
i++){
            tab[i]=min+((float) rand()/(float) RAND_MAX/(max-min));


        }
        return nbVal;

    }
    return -1;

}
*/
/*
int comptercar(char chaine[], int taillemax){
    int compt=0;

    for(int i=0;
 i<taillemax;
i++){
        if(chaine[i]!='\0'){
            compt++;

        }
        else{
            return compt;

        }
    }
    return 0;

}

int main(){
    char chain[12]="Bonjour toi";

    printf("%d\n",comptercar(chain,12));

}
*/

/*
int occur(char chaine[], int taillemax, char car){
    int compt=0;

    for(int i=0;
 i<taillemax;
i++){
        if(chaine[i]!='\0'&& chaine[i]==car){
            compt++;

        }
        else if(chaine[i]=='\0'){
            return compt;

        }
    }
    return 0;

}

int main(){
    char chain[12]="Bonjour toi";

    printf("%d\n",occur(chain,12,'o'));

}
*/
/*
void swap(int *x, int *y)
{
    int tmp = *x;

    *x = *y;

    *y = tmp;

}   

int main(){
    int x=3;

    int y=1;

    printf("%d , %d\n",x,y);

    if(x>y){
        swap(&x,&y);
        
    }
    printf("%d , %d\n",x,y);

    return 0;

}
*/
/*
#include <stdbool.h>
#define sizecarre 3
int carre[sizecarre][sizecarre]={
    {2,7,6},
    {9,5,1},
    {4,3,8}
};

bool isMagic(int carre[sizecarre][sizecarre]){
    int sum=0;

    int temp =0;

    for(int i;
 i<sizecarre ;
 i++){
        sum+=carre[i][i];

        temp+=carre[sizecarre-1-i][sizecarre-1-i];

    }
    int temp1=sum;

    int i=0;


    while (sum==temp && sum==temp1 && i<sizecarre){
        temp=0;

        temp1=0;

        for(int j=0;
 j<sizecarre ;
 j++){
            temp+=carre[i][j];

            temp1+=carre[j][i];

        }
        //printf("ligne numéro %d : %d colone numero %d \n",i, temp,i,temp1);

        i++;

    }

    if(sum==temp && sum==temp1){
        return true;

    }
    return false;

}

int main(){
    bool a =isMagic(carre);

    printf("%zu",a);

}

*/
/*

///TD exercice des grand nombre
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdbool.h>
#define NbChiffresMax 30 
// taille max pour representer un grand entier 
typedef int GrandEntier[NbChiffresMax] ;
*/
//representation des grands entiers à l'aide d'un tableau      
/* les positions qui ne contiennent pas de chiffre significatif */
/* sont initialisées à zero */
/*
void Initialise(GrandEntier N){
    for( int i=0; i<NbChiffresMax;i++){
        N[i]=0;

    }
}
void Affiche(GrandEntier N){
    for(int i=0;i<NbChiffresMax;i++){
        if(i%3==0){
            printf(" ");
        }
        printf("%d",N[i]);

        
    }
}


int AjouteADroite(GrandEntier N, int c){
    if (N[0]!=0){return -1;}
    for(int i=1; i<NbChiffresMax;i++){
        N[i-1]=N[i];
    }
    N[NbChiffresMax]=c;
    return 0;
}

int Addition(GrandEntier A, GrandEntier B, GrandEntier result){
    int retenue=0;
    int temp2;
    for(int i=NbChiffresMax-1; i>=0; i--){
        temp2=A[i]+B[i]+retenue;
        retenue= (int) temp2/10;
        result[i]=temp2%10;
        if(i==0 && retenue!=0){
            return-1;
        }
    }
    return 0;
}



int EntreeClavier( GrandEntier Nombre){
    int NbChiffresLus = 0;
    wchar_t car;        // touche frappée en entrée
    wchar_t chiffre[2]; // variable type chaine de caractère Wide pour conversion // de car en entier avec _wtoi
    bool EstUnChiffre = false;
    Initialise(Nombre); // Nombre prend la valeur zero
    do{while((car = _getch()) == 0) {
        car= _getch(); // touche de fonction ou direction enfoncée 
        }; // lire la touche frappee au clavier 
        if(EstUnChiffre = (bool)isdigit(car))  // s'il s'agit bien d'un chiffre
        {
            printf(L"%c", car); // echo ecrandu chiffre valide 
            chiffre[0]=car; // conversion du caractere en chaine null terminated pour _wtoi()
            chiffre[1]=0;
            AjouteADroite(Nombre, atoi(chiffre)); // conversion du caractere en valeur numerique et
            NbChiffresLus++;      // affectation dans le tableau qui contient le grand entier
            }
            else{  // s'il s'agit d'un caractère de controle CLEAR (touche 'C' )
                if(( car == 'C') || (car == 'c') ) {
                    Initialise(Nombre);  // effacement des caractères saisies
                    printf("\nClear\n");
                    EstUnChiffre = true; // pour continuer la saisie de ce nombre
                }
                }
        }
        while(EstUnChiffre && (NbChiffresLus < NbChiffresMax));{
        printf("\n");
        if(( car == 'X') || (car == 'x') ) return-1;
        return 0;
        }


}



int main() {
    GrandEntier Nb1, Nb2,Nb3;
    int i;
    bool Fin = false ;
    int Code;
    // valeur de retour de la fonction EntreeClavier
    while(!Fin){
        if( (Code = EntreeClavier(Nb1)) < 0) Fin=true;
        if( !Fin && (Code = EntreeClavier(Nb2)<0)) Fin=true;
        if(!Fin){
            printf("\n  ");
            Affiche(Nb1);
            printf("+ ");
            Affiche(Nb2);
            printf("  ");
            for(i=0;i < NbChiffresMax ;i++) {
                if((NbChiffresMax -i )% 3 == 0) printf("-");
                printf("-");
                } 
            printf("\n= ");
            Addition(Nb1, Nb2, Nb3);
            Affiche(Nb3);
            printf("\n");
    }
    else{printf("\n Bye !\n");
    }
    }
    return(EXIT_SUCCESS);
}

*/
/*

#define lgt 500


int find(int vale, int tabz[lgt][2]){
    int diff=-1;
    int vali;
    int find=0;
    for(int i =0 ; i<lgt ;i++){
        if (tabz[i][0]==vale){return tabz[i][1];}
        else if(tabz[i][0]<vale){
            find=1;
            if (diff==-1){
                vali=i;
            }
            else{
                int temp=tabz[i];
                if(vale-temp<diff){
                    vali=i;
                }
            }
        }
    }
    if(find==0){
        return 0;
    }
    else{
        return -tabz[vali][1];
    }

}
int fact(int nbbas, int nbhaut){
    if(nbbas>nbhaut){return -1;}
    if(nbbas==0){nbbas=1;}
    int valeu=1;
    for(int i=nbbas;i<=nbhaut;i++){
        valeu*=i;
    }
    return valeu;
}


int main(){
    int tab[lgt][2]={{0},{1}};
    int val=0;
    int j=0;
    while (val!=-1){
        printf("rentrez votre valeur :\n");
        scanf("%d",&val);
        if (val!=-1){
            int a=find(val,tab);
            if(a>0){
                printf("Votre valeurs est : %d\n",a);
            }
            else {
                 int b = fact(-a,val);
                if(b==-1){printf("y'a bug");}
                else{
                    printf("Votre valeurs est : %d\n",b);
                    tab[j][0]=val;
                    tab[j][1]=b;
                }
            }
        }
    }
}
*/
/*

typedef struct point
{
    int x;
    int y;
    char couleur[10];
}point;

typedef struct rectangle{
    point haut;
    point bas;
    char couleur_trait[10];
    char couleur_fond[10];


}rectangle;

int est_dans_rec(point a, rectangle rec){
    if(a.x>=rec.haut.x && a.x<=rec.bas.x && a.y>=rec.haut.y && a.y<= rec.haut.y){
        return 1;
    }
    return 0;
}


int main(){
    point mon_point={ 3,4,"rouge"};
    rectangle mon_rectangle={{100,200,"rouge"},{300,2,"rouge"},"rouge","blanc"};
}

*/


/*

char* clonestr( char* chaine){
    int nbcase=strlen(chaine);
    char* copie=(char*)malloc(nbcase+1);
    char* positionscopie=copie;
    char* positionschaine=chaine;
    if(copie!=NULL){
        while(*chaine!='\0'){
            *copie=*chaine;
            copie++;
            chaine++;
        }
    }
    *copie='\0';
    copie=positionscopie;
    chaine=positionschaine;
}
int main(){
    char *c1="Salut";
    char *c2;
    c2=clonestr(c1);
    printf("c1 est %s et c2 est %s",c1,c2);
    return 0;
}

*/
/*
void afficher(int tab[],int s){
    for(int i=0; i<s;i++){
        printf("%d,",tab[i]);
    }
}
int main(){
    int *tab;
    tab=(int*)malloc(10*(sizeof(int)));
    for(int i=0; i<10;i++){
        tab[i]=i+1;
    }
    afficher(tab,10);

    tab=(int*)realloc(tab,20*sizeof(int));
    for(int i=10; i<20;i++){
        tab[i]=i+1;
    }
    printf("\n");
    afficher(tab,20);
    free(tab);
    return 0;
}

*/
/*
void affichemog(heure*log, int nblog){

}
*/
/*
int main(){
    int a=10;
    int b=5;
    int tab[3]={1,2,3};
    int *p;
    p=&b;
    *p=tab[2];//<=> b=tab[2]
    tab[0]=a; //tab={10,2,3}
    *(tab +1)=b;//tab[1]=>b
    p=tab+2;//p=>&tab[2]
    *p=*(p-1);//tab[2]=tab[1]
    p=p-1;
    *p=*(p-1);//tab[1]=tab[0]
    printf("a=%d, b=%d, tab[0]=%d, tab[1]=%d, tab[2]=%d",a,b,tab[0],tab[1],tab[2]);
    return EXIT_SUCCESS;
}

*/
/*
int main(){
    int tab[]={1,4,3,4,5,2,3,2,4,1};
    int taille =10;
    int val;
    int compteur=0;
    int* tmp=tab;
    printf("rentrer la valeur a chercher \n");
    scanf("%d",&val);
    for(int i=0; i<taille; i++){
        if(*tmp==val){
            
            compteur++;
            }
        tmp++;

    }
    printf("le nb d'occurences est de : %d \n",compteur);
    return EXIT_SUCCESS;
}
*/
/*
int main(){
    char mot[6]="hello";
    char val;
    bool rentre =false;
    scanf("%c",&val);
    for( int i=0 ; i<5;i++){
        if(*(mot+i)==val){
            rentre=true;
        }
        if(rentre==true){
            *(mot+i)='?';
        }
    }
    printf("%s",mot);
}
*/
/*
void afficher(int tab[6][6]){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%d ",tab[i][j] );
        }
        printf("\n");
    }
}
int addition(int tab[6][6]){
    int temp=0;
    for(int i=0; i<6;i++){
        temp+=tab[i][i];
    }
    return temp;
}


int main(){
    int tab[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            tab[i][j]=rand()%9 +1;
        }
    }
    afficher(tab);

}
*/
/*
#define SECURE_NO_WARNINGS
#include "ConsoleTools.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>


typedef struct chenille
{
    int posx;
    int posy;
    int numero;
    bool alive;

}chenille;

chenille chen[13] = { {0,0,0,0} };

typedef struct pomme
{
    int posx;
    int posy;
    bool alive;

}pomme;

pomme pom[8] = { 0,0,0 };

bool yaquoi(int nb, int pos, chenille tab[13]) {
    if (pos == 1) {

        for (int i = 1; i < 13; i++) {
            if (tab[0].posx + nb == tab[i].posx) {
                return false;
            }
        }
    }
    else {
        for (int i = 1; i < 13; i++) {
            if (tab[0].posy + nb == tab[i].posy) {
                return false;
            }
        }
    }
    return true;
}

bool deplacement(int dep, chenille tab[13]) {
    bool yes = false;
    switch (dep)
    {
    case 0:
        if (yaquoi(1, 1, tab) || tab[0].posx + 1 >= 31) { tab[0].posx += 1; }
        else { yes = true; }
        break;
    case 1:
        if (yaquoi(1, 2, tab) || tab[0].posy + 1 >= 31) { tab[0].posy += 1; }
        else { yes = true; }
        break;
    case 2:
        if (yaquoi(-1, 1, tab) || tab[0].posx - 1 <= 0) { tab[0].posx -= 1; }
        else { yes = true; }
        break;
    case 3:

        if (yaquoi(-1, 2, tab) || tab[0].posy - 1 <= 0) { tab[0].posy -= 1; }
        else { yes = true; }
        break;
    return yes;
    }

}
void init(chenille tab[13],pomme pom[8]) {
    int x = rand() % 30 +1;
    int y = rand() % 26 +1;
    tab[0].posx = x;
    tab[0].posy = y;
    tab[0].alive = true;
    for (int i = 1; i < 13; i++) {
        tab[i].numero = i;
        if (i < 5) {
            tab[i].alive = true;
            y++;
            tab[i].posx = x;
            tab[i].posy = y;
        }
    }
    x = rand() % 30 +1;
    y = rand() % 30 +1;
    for(int i=0;i<8;i++){
        for(int j=0;j<13;j++){
            while(x!=tab[j].posx && y!=tab[j].posy && tab[j].alive){
                x = rand() % 30 +1;
                y = rand() % 30 +1; 
            }
        }
        
    }
    
 
}
void suivit(chenille tab[13]) {
    for (int i = 12; i > 0; i--) {
        if (tab[i].alive) {
            tab[i].posx = tab[i - 1].posx;
            tab[i].posy = tab[i - 1].posy;
        }
    }
}

int main() {
    openConsole();

    
    init(chen);
    bool run = true;
    while (run) {
        for (int i = 0; i <= 32; i++) {
            moveCursor(i, 0);
            plotChar('_');
            moveCursor(i, 32);
            plotChar('_');
            moveCursor(0, i);
            plotChar('|');
            moveCursor(32, i);
            plotChar('|');
        }
        for (int i = 0; i < 13; i++) {
            if (chen[i].alive) {
                if (i == 0) { setWriteColor(1); }
                else { setWriteColor(2); }
                moveCursor(chen[i].posx + 1, chen[i].posy + 1);
                plotChar('*');

            }
        }
        
        suivit(chen);
        int dep = rand() % 4;
        bool a = deplacement(dep, chen);
        while (a) {
            a = deplacement(dep, chen);
        }
       
        Sleep(500);
        clearScreen();
        
    }
    moveCursor(0, 40);
    
}*/