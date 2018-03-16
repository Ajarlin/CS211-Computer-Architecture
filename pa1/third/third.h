//For linked lists

typedef struct{
    int data;
    struct node* next;
}node;

#define BUFSIZE 1024
node * head = NULL;

void insert(int num);
void delete(int num);
void printlist();
