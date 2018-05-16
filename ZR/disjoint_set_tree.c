#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//const int N = 15;
typedef struct node_t
{
   struct node_t *parent;
   int data;
   int *rank;
} Node;

void make_set(Node *x)
{
    x->parent = x;
    x->rank = 0;
}

Node* find_set(Node *x)
{
    Node *p;
    p=x;
    if (p != p->parent)
        p->parent = find_set(p->parent);
    return p->parent;

}

void link(Node *x, Node *y)
{
   // Node *p, *q;

    if (x->rank > y->rank)
        y->parent = x;
    else
        x->parent = y;
        
    if(x->rank == y->rank)
        y->rank++;

}

void union_sets(Node *x, Node *y)
{
    link(find_set(x),find_set(y));
}






int main(int argc, char* argv[])
{
    if(argc != 2)
    {
	 printf("Enter number of nodes as an argument\n");
	    exit(0);
    }
	int N = atol(argv[1]);
    Node z[N], *p;
    int i,j,x,y,c;
    srand(time(NULL));

    for(i=0; i<N; i++)
    {
        z[i].data = i;
        make_set(&z[i]);
    }

     for(i = 0; i < N; i++)
  {
    x = find_set(&z[i])->data;
    if(x == i) c++;
    printf("%d is in set %d\n",i,x);
  }



    printf("\n\n");

    for(i=0; i<N; i++)
    {
        x = rand()%N;
        y = rand()%N;
        union_sets(&z[x],&z[y]);
    }

    c = 0;


    for(i = 0; i < N; i++)
  {
    x = find_set(&z[i])->data;
    if(x == i) c++;
    printf("%d is in set %d\n",i,x);
  }



  printf("Number of sets: %d\n",c);

   for(i = 0; i < N; i++)
  {
    p = find_set(&z[i]);
    if(p->data == i)
    {
        printf("Set %d: ",i);
        for(j = 0; j < N; j++)
            if(p == find_set(&z[j])) printf("%d ",j);
            printf("\n");
    }
  }
  
  return 0;
} 

