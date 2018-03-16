#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "count.h"


/*Lessons learned in this assignment,
 *how to read hexademicals based 16
 *Learned of unsigned and long long use
 *Error insert method, forgot to use return methods when subtracting count
 *Use of Hashtables with linked lists
 ***take the the num and divide by ht-size to get index
 ***At every index of a hashtable check if its empty or not
 ***if empty add a LL add the val, after null, and size at that index
 ***check if the value exists, if it does count--
 ***
 */
int main(int argc, char * argv[]){
    
    if(argc != 2){
        printf("error\n");
        return 0;
    }
    int i;
    for(i=0;i<SIZE; i++){
        htable[i]=(node*)malloc(sizeof(node));
        htable[i]->length = 0;
    }
    
    FILE *fd;
    char line[BUFSIZE];
    fd = fopen(argv[1],"r");
    
    if(fd == NULL){
        printf("error\n");
        return 0;
    }
    
    //https://stackoverflow.com/questions/38416706/read-an-hexadecimal-number-and-validate-its-number-of-digits-in-c
    while(fgets(line, sizeof(line),fd)){
     char * num;
     unsigned long long int number = strtoul(line, &num, 16);
        //printf("%llu\n", number);
        insert(number);
        //everytime i insert a number i increase the counter 
        count++;
        //search(number);
        cn++;
        //printf("%d count: \n", count);
    }
    //void unique();
    printf("%d\n",count);
    //printf("total inputs:%d \n", cn);
    return 0;

}
void insert(unsigned long long int num){
    //printf("test\n");
    unsigned long long int index;
    index=num%1000;
    
    //at this index the htable has no linked list and its empty
    if(htable[index]->length == 0){
        htable[index]->data=num;
        htable[index]->next=NULL;
        htable[index]->length++;
        //printf("test1\n");
    //Item inserted already in the list and and equals the value inserted
    }else if(htable[index]->length>=1 && htable[index]->data==num){
        //duplicate found so substract
        count--;
        //void unique();
        return;
    }
    //value is inserted but not found yet in the list
    else if(htable[index]->length>=1 && htable[index]->data!=num){
        
        node *tmp = (node*)malloc(sizeof(node));
        tmp->data=num;
        tmp->next=NULL;
        node * ptr = htable[index];
        node * prv= NULL;
      //printf("test2\n");
      
        while(ptr!=NULL){
            if(ptr->data == num){
                //duplicate found so subtract
                //void unique();
                count--;
                return;
            }
            prv=ptr;
            ptr=ptr->next;
        }
        prv->next=tmp;
    }
    return;
}
