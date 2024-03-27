#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define FILELINE 2324
char *getItem(void);
char *getItems(int);
int main(void)
{   
    char item[50] = "start https://search.bilibili.com/all?keyword=";
    strcat(item,getItem());
    puts(item);
    system(item);
    return 0;
}
char *getItems(int num){
    static char *temp;
    char (*a)[21] = (char(*)[21]) malloc(sizeof(char)*21*3000);
    char *buff = (char *)malloc(sizeof(char)*21);
    int i = 0;
    // char **temp;
    FILE *fp = fopen("dataANSI.txt","r");
    while(fgets(buff,20,fp)){
        // printf("%s",buff);
        strcpy(a[i++],buff);
    }
    temp = a[num];
    free(a);
    free(buff);
    return temp;
}
char *getItem(void){
    time_t t;
    static char *temp;
    char (*a)[21] = (char(*)[21]) malloc(sizeof(char)*21*(FILELINE+1));
    char *buff = (char *)malloc(sizeof(char)*21);
    int i = 0,num;
    // char **temp;
    FILE *fp = fopen("dataANSI.txt","r");
    srand((unsigned) time(&t));
    num = rand()%FILELINE;
    while(fgets(buff,20,fp)){
        // printf("%s",buff);
        strcpy(a[i++],buff);
    }
    temp = a[num];
    while(strlen(temp)<=1)
    {
        num = rand()%FILELINE;
        temp = a[num];
    }
    free(a);
    free(buff);
    return temp;
}
