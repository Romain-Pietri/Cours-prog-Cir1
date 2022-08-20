#include "pile.h"
#include "string.h"
#include <stdbool.h>
#include <stdio.h>
#include "pile.c"
#include <math.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

bool ispalin(char * c){
    int j=0;
    Stack * pil1;
    Stack * pil2;
    NewStack(&pil1, strlen(c));
    NewStack(&pil2, strlen(c));
    
    do{
        push(pil1,*(c+j));
        j++;
        
    }while(*(c+j)!='\0');

    
    retourne(pil1,pil2);

    int value1;
    int value2;
    int tours=pil1->stackNbElemts;

    for(int i=0;i<tours;++i){
        pull(pil1,&value1 );
        pull(pil2, &value2);
        if(value1!=value2) return false;
    }
    return true;
}
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
int lequel(char c){
    switch(c){
        case '+': return 10;
        case '-': return 11;
        case '*':return 12;
        case '/':return 13;
    }
    return -1;
}
int main(){
    char c[1000]="2 4 + 6 * 9 3 / +";
    Stack * pil1;
    NewStack(&pil1, 100);
    Stack * file1;
    NewStack(&file1, 100);
    //scanf("%s",&c);
    int ln=strlen(c)-1;
    
    int a=0;
    for(int i=0; i<=ln;++i){
        if(*(c+ln-i)!=' '){
            if(*(c+ln-i)>='0'&&*(c+ln-i)<='9'){
                a= a*10+ (*(c+ln-i)-48);
                if(*(c+ln-i-1)==' '|| i==ln){push(pil1, a);}
            }
            else{push(file1,lequel(*(c+ln-i)));            
            }
            
        }        
        else{a=0;}
    }

    int value1=0;
    int value2=0;
    int op;
    int result;
    int tours=pil1->stackNbElemts;
    for(int i=0;i<tours-1;++i){
        pull(pil1, &value1);
        pull(pil1,&value2);
        pull(file1,&op);
        switch(op){
            case 10: result=value1+value2;break;
            case 11: result=value1-value2;break;
            case 12:result=value1*value2;break;
            case 13: result=value1/value2;break;
        }
        printf("%d | %d | %d | %d\n",result, op, value1, value2);
        push(pil1, result);
        
    }
    pull(pil1, &result);
    printf("%d",result);
    
}
