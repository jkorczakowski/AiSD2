#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

void lcs_length(char *x, char *y, int m, int n, int *c, int *b);

int main()
{
    int *c = NULL;
    int *b = NULL;
    char *x = (char*)malloc(sizeof(char)*1000);
    char *y = (char*)malloc(sizeof(char)*1000);
    scanf("%s",x);
    scanf("%s",y);
    int m = strlen(x);
    int n = strlen(y);
    x = (char*)realloc(x,sizeof(char)*m);
    y = (char*)realloc(y,sizeof(char)*n);
    
    lcs_length(x,y,m,n,c,b);
    
    printf("INPUT:\nX: %s\nY: %s",x,y);
    printf("OUTPUT:\nLENGTH: %d\n",c[m,n]);
    
    
}


void lcs_length(char *x, char *y, int m, int n, int *c, int *b)
{
    
    c = (int*)malloc(m*n*sizeof(int));
    b = (int*)malloc(m*n*sizeof(int));
    int i;
    int j;
    
    for(i=1;i<m;i++)
    {
        c[i,0] = 0;
        for(j=0;j<n;j++)
            c[0,j] = 0;
    }
    
    
    // 0 = north, 1 = north-west, 2 = west
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(x[i]==y[i])
            {
                c[i,j] = c[i-1,j-1] + 1;
                b[i,j] = 1;
            }
            else if (c[i-1,j]>=c[i,j-1])
            {
                c[i,j] = c[i-1,j];
                b[i,j] = 0;
            }
            else
            b[i,j] = 1;
        }
    }
}
