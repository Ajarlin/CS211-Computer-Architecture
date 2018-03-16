#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fourth.h"

/*int hashcode(int key){
    return (key % SIZE);
}*/
//You can assume the hash table will store at most 1000 numbers.
/*
void create(){
    int i;
    for(int i=0; i<1000; i++){
        hash[i]=NULL;
    }
}
*/
int main(int argc, char * argv[]){
    
    if(argc != 2){
        printf("error\n");
        return 0;
    }
    
    FILE *fd;
    //printf("SegCheckre\n");
    char line[BUFSIZE];
    //Not enough inputs such as no I and just a #
    // printf("SegCheckre2\n");
   //r is for reading the file
   //https://www.programiz.com/c-programming/c-file-input-output
     fd = fopen(argv[1],"r");
    
  //  printf("SegCheckre3\n");
        
    //if no values in the file
    if(fd == NULL){
        printf("error\n");
        return 0;
    }

    int i;
    
    for(i=0;i<SIZE; i++){
        htable[i]=NULL;
    }
    
    //fgets(string,size,stdin);
    /*
     *For this assignment the 'letter' and 'num' are seperated by tab("\t")
     *I must store both into their own variables one a char and the other an int
     *
    */
    
    //https://stackoverflow.com/questions/29476556/read-files-separated-by-tab-in-c
    //segment error here
    while(fgets(line, sizeof(line),fd)){
   
    int num;
    //strtok seperates inputs by certain things(\n, \t, ...)
    const char *letter = strtok(line,"\t");
    char *number = strtok(NULL, "\t");
    
    if(number == NULL){
        printf("error\n");
        return 0;
    }
    
    //atoi converts strings into an integer
    num = atoi(number);
   
    //strcmp: compares two strings, if its true it will return 0
    if(strcmp(letter, "i") == 0){
        insert(num);
        //printf("the i phase\n");
    }
    else if(strcmp(letter, "s") == 0){
        search(num);
        //printf("the s phase\n");
    }
    else{
        //print error b/c the file is in the wrong input
        printf("error\n");
    }
}// end of while loop
}

//Insert values into the hashtable
//prints 'inserted' if new or 'duplicate' if already there
void insert(int num){
    //search(int key);
    // case 1: if number is negative
    int index=abs(num%1000);
    table *hash;
      
    hash=htable[index];
  
    while(hash!=NULL){
        
        if(hash->data == num){
            printf("duplicate\n");
            return;
        }
        hash=hash->next;
    }
    
    create(num, index);
    
    return;
}

void create(int num, int index){
    //printf("check\n");
    table * node;
    node =(table*)malloc(sizeof(table*));
    
    node->data = num;
    node->next = htable[index];
    htable[index] = node;
    
    printf("inserted\n");
    return;
}
//Obj: searches for a value
// results 'present' if found and 'absent' if not found
// printed in its own lines
void search(int num){
    int index = abs(num%1000);
    
    table *hash;
    hash=htable[index];
    while(hash != NULL){
        if(hash->data == num){
            printf("present\n");
            return;
        }
        hash= hash->next;
    }
    printf("absent\n");
  return;
}
