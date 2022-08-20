#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*recursif*/
/*
int fact(int n){
    if(n==1){
        return 1;
    }
    else{n*fact(n-1)}
}
fact(4)
4*fact(3)=> 4*3*Facgt(2)

void recurcomptdecrement(int compt){
    printf("%d",compt);
    if (compt<=0){return;}
    else {return recurcomptdecrement(compt-1);}    
}
*/



/*

int recursrtlen(char *chaine){
    if(*chaine=='\0'){return 0;}
    return 1+recursrtlen(chaine+1);
}

int recurmult(int p,int n){
    if (n==0){return 0;}
    return p+recurmult(p,n-1);
}

int puissance(int a,int b){
    if(b==0){return 1;}
    return a*puissance(a,b-1);
}
int fibo(int n){
    if(n<=1){return n;}
    return fibo(n-1)+fibo(n-2);
}

int pgcd(int a,int b){
    if (a%b==0)return b;
    pgcd(b,a%b);
}

int _fact(int n,int accu){
    if(n==1)return accu;
    return(_fact(n-1,accu*n));
}

bool _palindrome(char * mot,int i,int j){
    if (*(mot+i)!=*(mot+j)){return false;}
    if (i>=j) return true;
    return _palindrome(mot,++i,--j);
}
bool palindrome(char *mot){
    return _palindrome(mot,0,strlen(mot)-1);
}
*/

int _dicho(int * tab,int val, int d,int f){
    int milieu=(int)(d+f)/2;

    if (*(tab+milieu)<val){
        return _dicho(tab,val,milieu,f);}

    if (*(tab+milieu)>val){
        return _dicho(tab,val,d,milieu);}
    if (*(tab+milieu)==val) return milieu;
    else return -1;


}

int dicho(int * tab,int val, int nbvalue){
    return _dicho(tab,val,0,nbvalue);
}

int main(){
    int tab[] = { 1, 5, 8, 10, 21, 22, 25, 33, 37, 40, 90 };
    printf("%d",dicho(tab,22,11));
    return 0;
}

