#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define filename1 "sample.txt"
#define filename2 "sample1.txt"
int N;
//function declaration
int row_check(int sudoku[][10]);
int col_check(int sudoku[][10]);
int cube_check(int sudoku[][10]);
void display_9(int sudoku[][10]);
void display_4(int sudoku[][10]);
void su_display();


int main()
{
    su_display();
    do{
       printf("\n\t\t\tEnter Choice :");
       scanf("%d",&N);
    }while (N != 2 && N !=1 );
    printf("\n");
    if (N==1)
     N=9;
    else
     N=4;

        int sudoku[10][10];
        FILE *fp;
         if(N==9)
          fp=fopen(filename1,"r");
         else if(N==4)
          fp=fopen(filename2,"r");

        if(fp==NULL)
        {
            printf("\n\t\t\t  Invalid File\n");
            exit(1);
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                fscanf(fp,"%d",&sudoku[i][j]);
            }
        }
        if (N==9)
            display_9(sudoku);
        else
            display_4(sudoku);
        printf("\n");
        bool br = row_check(sudoku);
        bool bc = col_check(sudoku);
        bool bs= cube_check(sudoku);

        if (br && bc && bs)
            printf("\n\t\t\t     VALID\n");

}

void su_display()
{

    printf("\n  *******   *      *   *****            *****       *    *   *      *");
    printf("\n  *         *      *   *     *        *       *     *   *    *      *");
    printf("\n  *         *      *   *       *     *         *    *  *     *      *");
    printf("\n  *         *      *   *        *   *           *   * *      *      *");
    printf("\n  *******   *      *   *        *   *           *   **       *      *");
    printf("\n        *   *      *   *        *   *           *   * *      *      *");
    printf("\n        *   *      *   *       *     *         *    *  *     *      *");
    printf("\n        *   *      *   *     *        *       *     *   *    *      *");
    printf("\n  *******   ********   *****            *****       *    *   ********");

    printf("\n\n");
    printf("\n\t\t\t\tMENU");
    printf("\n\t\t\t   1.9x9 Sudoku");
    printf("\n\t\t\t   2.4x4 Sudoku");
    printf("\n");

}

void display_4(int sudoku[][10])
{
    int n=4;
    for(int i=0; i<n; i++)
    {
        printf("\t\t      ");
        for(int j=1; j<n; j++)
        {
            if(i%2==0)
            printf("  __ ");
        }
        printf("\n");
        printf("\t\t      |");
        for(int j=0; j<n; j++)
        {
            printf(" %d  ",sudoku[i][j]);
            if((j+1)%2==0)
            printf("|");
        }
        printf("\n");
    }

    printf("\t\t       ");
    for(int j=1; j<n; j++)
      printf("  __ ");
}

void display_9(int sudoku[][10])
{
     int div=3;
    for(int i=0; i<N; i++)
    {
        printf("\t  ");
        for(int j=1; j<N; j++)
        {
            if(i%div==0)
            printf("  __ ");
        }
        printf("\n");
        printf("\t  |");
        for(int j=0; j<N; j++)
        {
            printf(" %d  ",sudoku[i][j]);
            if((j+1)%div==0)
            printf("|");
        }
        printf("\n");
    }

    printf("\t  ");
    for(int j=1; j<N; j++)
     printf("  __ ");
}


int row_check(int sudoku[][10])
{

  int c[10] = {0};
  bool berror=true;
  for (int i=0; i<N; i++)
  {
      for (int j=0; j<N; j++)
      {
          c[ sudoku[i][j] ] ++;
      }
      for (int k=1; k<=N; k++)
      {
       if(c[k] != 1 && c[k]!= 0)
       {
           printf("\n\t\t\t    INVALID");
           printf("\n\t\tThe Value %d came %d times in row %d\n",k,c[k],i+1);
           berror = false;
       }
      }
      for(int k=1;k<=N; k++)
      c[k] = 0;
  }
 return berror;
}


int col_check(int sudoku[][10])
{

  int c[10] = {0};
  bool berror=true;
  for (int i=0; i<N; i++)
  {
      for (int j=0; j<N; j++)
      {
          c[ sudoku[j][i] ] ++;
      }
      for (int k=1; k<=N; k++)
      {
       if(c[k] != 1 && c[k]!= 0)
       {
           printf("\n\t\t\t    INVALID");
           printf("\n\t\tThe Value %d came %d times in coloumn %d\n",k,c[k],i+1);
           berror=false;
       }
      }
      for(int k=1;k<=N; k++)
        c[k] = 0;
  }
 return berror;
}


int cube_check(int sudoku[][10])
{
    int inc=3;
    if (N == 4)
        inc=2;
    int c[10]={0}, count = 0;
    bool berror=true;
     for(int m=0; m<N; m+=inc)
     {
         for(int b=0;b<N; b+=inc)
         {
             for(int i=m; i<m+inc; i++)
             {
                 for(int j=b; j<b+inc; j++ )
                 {
                     c[sudoku[i][j] ]++;
                 }
             }
                count++;
                for(int k=1; k<=N; k++)
                {
                    if( c[k] != 1 && c[k] != 0)
                    {
                        printf("\n\t\t\t    INVALID");
                        printf("\n\t\tThe value %d come %d times in cube %d\n",k,c[k],count);
                        berror=false;
                    }
                }
                for(int k=1; k<=N; k++ )
                  c[k]=0;

             }
         }
   return berror;
}
