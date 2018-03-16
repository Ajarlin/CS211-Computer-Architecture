//hashtable
typedef struct{
    int data;
    struct table *next;
}table;


#define BUFSIZE 1000
#define SIZE 1000
table *htable[SIZE];

void insert(int num);
void create(int num, int index);
void search(int num);
