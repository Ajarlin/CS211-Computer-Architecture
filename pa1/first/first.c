#include <stdio.h>
#include <stdlib.h>
#include "first.h"

int main(int argc, char * argv[]){
    
    //printf("number of args %d\n", argc);
    
    if(argc <= 1){
        printf("error\n");
        return 0;
    }
    
    int num;
    //printf("Enter the Value: \n");
    //Error with scanf having to input 
    //scanf("%d", &num);
    num =atoi(argv[1]);
    if(num < 1){
        printf("error\n");
        return 0;
    }
    
    if(num%2==0){
        printf("even\n");
    }
    else{
        printf("odd\n");
    }
    
    return 0;
}