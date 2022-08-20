#include <stdio.h>
#include <stdlib.h>
#define NB 20
unsigned int_to_int(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;                       /* optional */
    return (k % 2) + 10 * int_to_int(k / 2);
}
int main(){
    int tmp;
    FILE* fd = fopen("data1.bin", "w+b");
    /*for(int i=1;i<=1000;++i) {
        char j[5];
        sprintf(j,"%d\n",i);
        fputs(j,fd);
    }
    */ 
    for(int i=1; i <= NB; i++) {
        char j[32];
        tmp=int_to_int(i);
        sprintf(j,"%d",tmp);
        fprintf(fd, "%s\n",j);
    }
    fseek(fd,0,SEEK_SET);
    int test;
    for (int i=0; !feof(fd); i++) {
        test = fgetc(fd);
        if (test != '\n') {
            printf("%c", test);
        } else printf("\n");
    }
    fclose(fd);

}