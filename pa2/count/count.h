#define BUFSIZE 1024
#define SIZE 1000
//#define COUNT 0
typedef struct{
    unsigned long long int data;
    int length;
    struct node *next;
}node;

node * htable[SIZE];
int count = 0;
int cn = 0;
void insert(unsigned long long int num);
