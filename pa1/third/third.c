#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "third.h"

int main(int argc, char * argv[]){
    
    if(argc != 2){
        printf("error\n");
        return 0;
    }
    
    //Code to read arguements provided by
    /*
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
    
    FILE *fd;
    
    //node *ptr;
    //node *head = NULL;

    char line[BUFSIZE];
    //Not enough inputs such as no I and just a #

   //r is for reading the file
   //https://www.programiz.com/c-programming/c-file-input-output
    fd = fopen(argv[1],"r");
    
    //printf("SegCheckre3\n");
        
    //if no values in the file
    if(fd == NULL){
        printf("error\n");
        return 0;
    }
    
    //fgets(string,size,stdin);
    /*
     *For this assignment the 'letter' and 'num' are seperated by tab("\t")
     *I must store both into their own variables one a char and the other an int
     *
    */
    
    //https://stackoverflow.com/questions/29476556/read-files-separated-by-tab-in-c
    //segment error here*FIXED
    //segmentation error was fd=NULL
    //fgets(user_input, sizeof(user_input), stdin);
    while(fgets(line, sizeof(line),fd)){
   
    int num;
    //strtok seperates inputs by certain things(\n, \t, ...)
    const char *letter = strtok(line,"\t");
    char *number = strtok(NULL,"\t");
    
    if(number == NULL){
        printf("error\n");
        return 0;
    }
    
    //atoi converts strings into an integer
 
    num = atoi(number);
   
    //strcmp: compares two strings, if its true it will return 0
    //if i add to LL and if d delete from LL
    
    if(strcmp(letter, "i") == 0){
        insert(num);
       // printf("the i phase\n");
    }
    else if(strcmp(letter, "d") == 0){
        delete(num);
        //printf("the d phase\n");
    }
    else{
        printf("error\n");
        return 0;
    }
}// end of while loop
    printlist();
  
}


/*
node * createLinkedList(int data){
    node *ptr = (node*)malloc(sizeof(node));
    node *cur = NULL;
    if(ptr == NULL){
        printf("error\n");
    }
    
    ptr->data = data;
    ptr->next = NULL;
    
    head = cur = ptr;
    return ptr;
}

*/
//Insert Sort
void insert(int num){
    node *cur=head;
    node *prev=NULL;
    node *ptr;
    
    ptr=(node*)malloc(sizeof(node));
    ptr->data=num;
    ptr->next=NULL;
    
    //Test Case 1: If list is empty
    if(cur==NULL){
        ptr->next=NULL;
        head=ptr;
        return;
    }
    //Test Case 2: If the value of the inserted num val is less thant the 1st
    if(num < cur->data){
        ptr->next=head;
        head=ptr;
        return;
    }
    //Traverse throughout the list
    else{
        while(cur!=NULL){
            if(num > cur->data){
                prev = cur;
                cur=cur->next;
                continue;
            }
            else{
                prev->next=ptr;
                ptr->next=cur;
                return;
            }
        }
        prev->next=ptr;
        
    }
    
}

//Tutorials used
//https://www.youtube.com/watch?v=Y0n86K43GO4 instead of Nth item, find item and then delete
//https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
void delete(int num){

    if(head != NULL){
        //if the num is 1st
        if(head-> data == num){
            head = head->next;
        }
        else{
            node *front;
            node *prev = head;
            for(front=head; front!=NULL; front= front->next){
                //if the number we're deleting is less than the current value
                if(front->data > num){
                    break;
                }
                else{
                    if(front->data == num){
                        prev->next =front->next;
                        break;
                    }
                }
                if(prev->data != front->data){
                    prev=prev->next;
                }
            }
        }
    }
    return;
}


//https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
//for printlist
void printlist(){
    
    node *list;
    for(list=head; list!=NULL; list=list->next){
            printf("%d\t",list->data);
    }
    printf("\n");
    return;

    //errors with printing
    /*node *list = head;
    if(list->next != NULL){
    while(list->next != NULL){
        printf("%d\t", list->data);
        list = list->next;
    }
}
    else{
        printf("\n");
    }
return;
    
   /* ptr = head;
	while (ptr != NULL) {
		printf("%d",ptr->data);
		if (ptr->next != NULL){
            printf("\t");
        }
		ptr = ptr->next;
	}
	printf("\n");
    return 0;
}