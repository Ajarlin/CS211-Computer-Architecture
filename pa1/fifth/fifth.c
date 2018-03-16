#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifth.h"


//source for matrix addiotion methods
//https://codeforwin.org/2015/07/c-program-to-add-two-matrices.html

int main(int argc, char * argv[]){
    
    if(argc != 2){
        printf("error\n");
        return 0;
    }

    
    FILE *fd;
    char line[BUFSIZE];
    
    int row, col;
    int m, n; //m row and n col
    int number;
    int **sum;
    int i, j;
    int val;
    int num = 0;
    
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
     *\
    */
    
     
    //https://stackoverflow.com/questions/29476556/read-files-separated-by-tab-in-c
    //segment error here*FIXED
    //segmentation error was fd=NULL
    //fgets(user_input, sizeof(user_input), stdin);
    
    fgets(line, sizeof(line),fd);
     
    //strtok seperates inputs by certain things(\n, \t, ...)
    //had an error here, wrong type pointing
    row = atoi(strtok(line,"\t"));
    col = atoi(strtok(NULL,"\t"));
    //printf("Rows: %d  Cols: %d \n", row,col);
    
    //No valid rows and cols input
    if(row == 0 || col == 0){
            printf("error\n");
            return 0;
    }
 
    //create and fill the first matrix
    int **matrix;
    matrix=(int**)malloc(row*sizeof(int*));
    for(i=0; i<row; i++){
        matrix[i]=(int*)malloc(col*sizeof(int));
    }
    //make the sum matrix equal to the 1st matrix
    sum=matrix;
    //printf("blankchec\n");
    //second matrix creation
    //must bypass the line and then take those values
    
    m=0;
    //reading files line by line
    //https://stackoverflow.com/questions/33106505/read-file-line-by-line-in-c-mostly-with-syscalls
    while(fgets(line, sizeof(line),fd)){
        char *val;
         n=0;
        //number=atoi(val);
        
        //bypass the empty line       
        if(strcmp(line,"\n") == 0){
            m=0;
            continue;
        }
        
       
        //now we get the values
        val = strtok(line,"\t");
        while(val != NULL){ 
            //retrieves the value of the 1st matrix and its add it up together with the 2nd val
            //visual
            /*before
             *1   1   1
             *2   2   2  
             *3   3   3
             *
             *1   1   1
             *1   1   1
             *1   1   1
             */
            //ex: sum[0][0]= 1 + 1;
            sum[m][n]+=atoi(val);
            /*after
             * 2  2   2
             * 3  3   3
             * 4  4   4
             */
            val=strtok(NULL,"\t");
            n++;
        }
        m++;
    }//end of while loop
    
    printMatrix(sum, row, col);
return 0;
}


//https://stackoverflow.com/questions/11428526/passing-a-matrix-in-a-function-c
//passing matrices in methods
void printMatrix(int **Matrix, int row, int col){
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d\t",Matrix[i][j]);
        }
        printf("\n");
    }
    return;
}
    /*
    //Code provided by TA in recitation;

    int row, column;
    int *matrix = (int *)malloc(sizeof(row * column * sizeof(int)));
    //or you could allocal a large array before programming
    freopen("in.txt", "r", stdin);
    while (scanf("%d %d", &row, &column) != EOF)
    {
        //getchar();
        printf("get row %d\n", row);
        printf("get column %d\n", column);
        int i, j;
        int temp;
        int num = 0;
        
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                scanf("%d", &temp);
                //printf("%d,", temp);
                *(matrix + num) = temp;
                num++;
            }
        }
        printf("\n");
        for (i = 0; i < num; i++)
        {
            if(i%column==0){
                printf("\n");
            }
            printf("%d,", *(matrix + i));
        }
        
    }
}
*/
    
  //Tutorial used https://www.youtube.com/watch?v=t3HZcNN09KU
  //make custom input double matrices that add up with each other
  
  /*
int main(int argc, char * argv[]){
    
    if(argc != 2){
        printf("error\n");
        return 0;
    }
    
    int row, col;
    int m, n;
    int number;
    int **matrix=(int **)malloc(row*col*sizeof(int));
    //int *matrix2=(int *)malloc(row*col*sizeof(int));
    int *sum=(int *)malloc(row*col*sizeof(int));
        int i, j;
        int val;
        int num = 0;
    freopen(argv[1], "r", stdin);
    scanf("%d %d", &row, &col);
        {
        //getchar();
         printf("get row %d\n", row);
         printf("get column %d\n", col);
       
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                scanf("%d", &val);
                //char * tmp = temp;
                
               // num= atoi(temp);
               
                //printf("%d,", val);
                sum[j]=val;
                //*(matrix + num) = val;
                //num++;
                
            }
            matrix[i]=val;
        }
       /* printf("\n");
        for (i = 0; i < num; i++)
        {
            if(i%col==0){
                printf("\n");
            }
            printf("%d,", *(matrix + i));
        }
        
        //printf("\n");
        for(i = 0; i < row; i++)
        {
            matrix=(int **)malloc(row*col*sizeof(int));
            for(j = 0; j<col; j++)
            {
                scanf("%d", &val);
                //printf("%d,", val);
                //*(matrix2 + num) = val;
                //num++;
                matrix[i][j]=sum[i][j]+val;
            }
        }
        /*
        printf("\n");
        for (i = 0; i < num; i++)
        {
            if(i%col==0){
                printf("\n");
            }
            printf("%d,", *(matrix2 + i));
        }
        
        
    }
    
    
    //Adding the Two matrices
    int a, b;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            sum[i][j]=sum[i][j]+val;
        }
    }
    //Print results
    for(i=0; i<row;i++){
        for(j=0;j<col; j++){
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}

*/