#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lcs_length(char *x, char *y, int m, int n, int **c, int **b);
void lcs_print(int **b, char *x, int i, int j);

int main()
{
  	int i,j;
    int **c;
    int **b;

    char *x = (char*)malloc(sizeof(char)*1000);
    char *y = (char*)malloc(sizeof(char)*1000);

    scanf("%s",x);
    scanf("%s",y);

    int m = strlen(x);
    int n = strlen(y);

    c = (int **)malloc((m+1) * sizeof(int *));
	for(i=0;i<=m;i++)
	  c[i] = (int *)malloc((n+1) * sizeof(int));

	b = (int **)malloc((m+1) * sizeof(int *));
	for(i=0;i<=m;i++)
	  b[i] = (int *)malloc((n+1) *sizeof(int));

    x = (char*)realloc(x,sizeof(char)*m);
    y = (char*)realloc(y,sizeof(char)*n);
    
    printf("INPUT:\nX: %s, LENG: %d\nY: %s, LENG %d\n",x,m,y,n);
    lcs_length(x,y,m,n,c,b);
    printf("OUTPUT:\nLENGTH: %d\n",c[m][n]);
	lcs_print(b,x,m,n);
	printf("\n");

    

/*	free(y);
	free(x);
	free(b);
	free(c); */
	return 0;    
}


void lcs_length(char *x, char *y, int m, int n, int **c, int **b)
{
    int i;
    int j;

    for(i=1;i<=m;i++)
        c[i][0] = 0;

    for(j=1;j<=n;j++)
        c[0][j] = 0;
    
    
    // 0 = up, 1 = corner, 2 = left
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 0;
            }
			else
			{
			c[i][j] = c[i][j-1];
            b[i][j] = 2;
			}
        }
    }
	
}


void lcs_print(int **b, char *x, int i, int j)
{
  if (i == 0 || j == 0)
  {
	return;
  }

  if (b[i][j] == 1)
  {
	lcs_print(b,x,i-1,j-1);
	printf("%s ",&x[i-1]);
  }
  else if (b[i][j] == 0)
	lcs_print(b,x,i-1,j);
  else
	lcs_print(b,x,i,j-1);
}
