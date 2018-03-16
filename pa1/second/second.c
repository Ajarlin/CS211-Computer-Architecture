#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    
    //objective: input a number tell if its prime or composite
    //A prime number is only divisble by itself and 1
    
    /*Code to read arguements provided by TA
    printf("number of args %d\n", argc);
    int j=0;
    for (j = 0; j < argc; j++)
    {
        printf("the %dth parameter is %s\n", j,argv[j]);
        //if parameter is a integer
        int temp=atoi(argv[j]);
        printf("change into integer %d\n",temp);
    }
    */
    
    if(argc < 2){
        printf("error\n");
        return 0;
    }
    
    int num;
    //Had an issue with scanf where i had to input values twice
    //scanf("%d", &num);
    num =atoi(argv[1]);
    
    //1 is not a prime
    //test case for negatives as well
    if(num <= 1){
        printf("error\n");
        return 0;
    }
    
    int i, count=0;
    
    for(i=1; i<num; i++){
        if(num/i == num){
            count++;
        }
        if(num%i == 0){
            //printf("test: \n");
            count++;
        }
    }
    
    //2(the # and itself) counts means its a prime
    if(count == 2){
        printf("yes\n");
        return 0;
    }
    
    //not prime
    if(count != 2){
        //printf("count: %d\n", count);
        printf("no\n");
        return 0;
    }
    
    return 0;
}