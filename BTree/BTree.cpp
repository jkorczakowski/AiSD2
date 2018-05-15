//If you have problem understanding this,Refer CLRS a.k.a. "Introduction to algorithms" (chapter-BTREE) to understand the pseudocode for Insertion & diff. cases of Deletion.  

#include<iostream>
#include<stdlib.h>
#define t 2                                    //It's a order 2 BTREE, if want 3, just write 3 inplace of 2 like:-  #defint t 3 . Similary for other order,only update this line    
using namespace std;

typedef struct arr1{
	int key;
	struct arr2* child;
}node;

typedef struct arr2{
	int n;
	bool leaf;
	struct arr1* arr;
}btree;

typedef struct arr3{
	int index;
	struct arr2* spy;
}bond;

void fix_case3(bond* &x,btree* &root);          //These functions will be used mainly for delete operatoin from BTREE.
void fix_case2(bond* &x,btree* &root);
void fix_case1(bond* &x);
bond* find_max(btree* &x);
bond* find_min(btree* &x);
void delete_key(btree* &root,int k);            //This will be the main delete function,which will use all these functions. 
void merge(btree* &x , int i);
bond* search(btree* &x,int k);
bond* temp_search(btree* &x,int k,bond* &temp);


void split_child(btree* &x,int i){
	btree* z=new btree;
	z->arr=new node[2*t];
	btree* y=new btree;
	y->arr=new node[2*t];
	
	y=x->arr[i].child;
	z->leaf=y->leaf;                                           
	z->n=t-1;
	
	for(int j=0;j<(t-1);j++)
	     z->arr[j].key=y->arr[j+t].key;
	if(!y->leaf){
		for(int j=0;j<t;j++)
		    z->arr[j].child=y->arr[j+t].child;
	}
	y->n=t-1;
	for(int j=(x->n + 1);j>=(i+1);j--)
	      x->arr[j+1].child=x->arr[j].child;
	x->arr[i+1].child=z;
	for(int j=x->n;j>=i;j--)
	     x->arr[j+1].key=x->arr[j].key;
	x->arr[i].key=y->arr[t-1].key;
	x->n=x->n + 1;	 	       
}

void insert_nonfull(btree* &x,int k){
	int i=x->n;
	if(x->leaf){
		while(i>=1 && k<x->arr[i-1].key){
			x->arr[i].key=x->arr[i-1].key;
			i=i-1;
		}
		x->arr[i].key=k;
		x->n=x->n +1;
	}
	else{
		while(i>=1 && k<x->arr[i-1].key)
		     i=i-1;
		i=i+1;
		if(x->arr[i-1].child->n==(2*t -1)){
			split_child(x,i-1);			
			if(k>x->arr[i-1].key)
			    i=i+1;
		}		
		insert_nonfull(x->arr[i-1].child,k);     
	}
}

void insert(btree* &root,int k){
	btree* r=new btree;
	r=root;
	if(r->n==(2*t -1)){
		
		btree* s=new btree;
		s->arr=new node[2*t];
		s->leaf=false;
		s->n=0;
		s->arr[0].child=r;
		
		root=s;
		split_child(s,0);
		insert_nonfull(s,k);		
	}
	else
	  insert_nonfull(r,k);
}

void traverse(btree* &x){           
	for(int i=0;i<=x->n;i++){
		if(x->leaf==false){
			traverse(x->arr[i].child);
			if(i < x->n)
			   cout<<x->arr[i].key<<"  ";
		}
		else{
			if(i < x->n)
		       cout<<x->arr[i].key<<"  ";   	
		}
	}
}

bond* search(btree* &x,int k){                                       //for finding the node containg key
	int i=0;
	while(i<x->n && k>x->arr[i].key)
	       i=i+1;
	if(i<x->n && k==x->arr[i].key){
		bond* temp=new bond;
		temp->spy=x;
		temp->index=i;
	   return temp;
	}
	else if(x->leaf==true)
		return NULL;
	else
	   return search(x->arr[i].child,k);   	            
}

bond* temp_search(btree* &x,int k,bond* &temp){                    //for finding the parent node of a node containg key
	int i=0;
	bond* temp2=new bond;
	temp2=temp;                         
	while(i<x->n && k>x->arr[i].key)
	       i=i+1;
	if(i<x->n && k==x->arr[i].key)
		return temp2;
	else if(x->leaf==true)
		return NULL;
	else{
		temp2->spy=x;
		temp2->index=i;
		return temp_search(temp2->spy->arr[temp2->index].child,k,temp2); 	
	}	            
}

bond* find_min(btree* &x){
	if(x->leaf==false)
	   return find_min(x->arr[0].child);
	else{
		bond* temp=new bond;
		temp->index=0;
		temp->spy=x;
		return temp;
	}
}

bond* find_max(btree* &x){
	if(x->leaf==false)
	    return find_max(x->arr[x->n].child);
	else{
		bond* temp=new bond;
		temp->index=x->n -1;
		temp->spy=x;
	    return temp;   	
	} 
}

void merge(btree* &x , int i){                                                          //Assumes that node x->n >=t
	
	btree* y=new btree;
	y->arr=new node[2*t];
	btree* z=new btree;
	z->arr=new node[2*t];
	
	y = x->arr[i].child;
	z = x->arr[i+1].child;
	
	for(int j=0;j<z->n;j++)
	   y->arr[j+t].key=z->arr[j].key;
	for(int j=0;j<t;j++)
	   y->arr[j+t].child=z->arr[j].child;
	   
	y->n = (2*t -1);
	y->arr[t-1].key = x->arr[i].key; 
    
	for(int j=i;j<x->n -1;j++)
	    x->arr[j].key=x->arr[j+1].key;
	for(int j=i+1;j<x->n;j++)                        
	    x->arr[j].child=x->arr[j+1].child;		

	x->n = x->n -1;	   
}

void fix_case3(bond* &x,btree* &root){                                                    //it means m->n <= t-1.     This function assumed that x->spy->leaf ==false or a!=NULL  
	
		    	   bond* a=new bond;
		    	   a=temp_search(root,x->spy->arr[x->index].key,a); 
		    	   
		    if(a->spy->n >= t || a->spy==root){

		        if(a->index!=a->spy->n && a->spy->arr[a->index +1].child->n >= t){         //case 3a -right sibling       
		    		btree* b=new btree;                 
			        b=a->spy->arr[a->index +1].child;       
		
			        x->spy->n = x->spy->n +1;                                              //increment size(n) of node which have key k
			        x->spy->arr[x->spy->n -1].key=a->spy->arr[a->index].key;               //insert parent's key to child node of (t-1) size having key k
			        a->spy->arr[a->index].key=b->arr[0].key;                               //copy sibling's key to parent node
			        if(!b->leaf)
				       x->spy->arr[x->spy->n].child=b->arr[0].child;                          // child pointer of right sibling will transfer to last node having key k
				
			    	for(int j=0;j < b->n -1;j++)
				        b->arr[j].key=b->arr[j+1].key;
				    if(!b->leaf)    
				       for(int j=0;j < b->n;j++)
				           b->arr[j].child=b->arr[j+1].child;
				
				    b->n = b->n -1;
				}
				else if(a->index!=0 && a->spy->arr[a->index -1].child->n >=t){        //case 3a -left sibling                      
					btree* b=new btree;
			        b=a->spy->arr[a->index -1].child;
		
		            x->spy->n = x->spy->n +1;                                         //increment size(n) of node which have key k 
					    
			        for(int j = x->spy->n -1;j>0;j--)
			             x->spy->arr[j].key=x->spy->arr[j-1].key;
			        for(int j=x->spy->n;j>0;j--)
					     x->spy->arr[j].child=x->spy->arr[j-1].child;     
						 			            
			        x->spy->arr[0].key=a->spy->arr[a->index -1].key;                  //insert parent's key to child node of (t-1) size having key k   
			        a->spy->arr[a->index -1].key=b->arr[b->n -1].key;                 //copy sibling's key to parent node
				    x->spy->arr[0].child=b->arr[b->n].child;                          // child pointer of left sibling will transfer to last node having key k  
				
				    b->n = b->n -1;
				}
				
				else if(a->spy==root && a->spy->n ==1 && a->spy->arr[0].child->n ==t-1 && a->spy->arr[1].child->n ==t-1){
					
					if(a->index < a->spy->n){
						merge(a->spy,a->index);
						root=a->spy->arr[a->index].child;
					}
					else if(a->index == a->spy->n){
						a->index = a->index -1;
						merge(a->spy,a->index);
						root=a->spy->arr[a->index].child;
					}						
			    }
				
				else{                                                                 //case 3b -both siblings have t-1 keys only                          
					if(a->index==a->spy->n)                                           //delete key is in the right most node                
						merge(a->spy,a->index -1);
					else                                                              //both siblings have t-1 keys
						merge(a->spy,a->index);
				}		        
		     }
			  
		     else if(a->spy->n <= t-1 && a->spy!=root){		     	
	            	
	            	if(a->index < a->spy->n)
	                    fix_case3(a,root);
	                    
	                else if(a->index == a->spy->n){
	                	a->index = a->index -1;
	                	fix_case3(a,root);
					}    
			 }   
}

void fix_case2(bond* &x ,btree* &root){                                               //Assumes that (x->spy->n >=t && x->spy->leaf==false)  or  (x->spy==root && x->spy->leaf==false) 

          btree* var=new btree;

		  if(x->spy->arr[x->index].child->n >=t){                                      //case 2a    
			    var=x->spy->arr[x->index].child;
			    bond* jarvis=new bond;
			    jarvis=find_max(var);
			    
			    if(jarvis->spy->n <= t-1)
			       fix_case3(jarvis,root);
			    jarvis=find_max(var);   
			    
			    x->spy->arr[x->index].key = jarvis->spy->arr[jarvis->index].key; 
				fix_case1(jarvis);                  
		     }
		  else if(x->spy->arr[x->index +1].child->n >=t){                               //case 2b
			    var=x->spy->arr[x->index +1].child;
			    bond* jarvis=new bond;
			    jarvis=find_min(var);
			    
			    if(jarvis->spy->n <= t-1)
			       fix_case3(jarvis,root);
			    jarvis=find_min(var);
			    
			    x->spy->arr[x->index].key = jarvis->spy->arr[jarvis->index].key; 			    
				fix_case1(jarvis);                     
		     }
		  else{		  	                                                                //case 2c  
		  	    merge(x->spy,x->index);
		  }
}

void fix_case1(bond* &x){                                                               //Assumes  x->spy->leaf==true && x->spy->n > t-1	

	int temp=x->index;
	for(int i=temp;i<x->spy->n -1;i++)
		x->spy->arr[i].key = x->spy->arr[i+1].key;
	x->spy->n = x->spy->n -1; 
}

void delete_key(btree* &root,int k){                                       
   
    btree* r=new btree;
    r=root;
	bond* x=new bond;	
	x=search(r,k);   
	
 if(x!=NULL){
 	
	if(x->spy->leaf==true && x->spy->n >= t)
	       fix_case1(x);     
	 
	else{
		  if(x->spy->n <= t-1 && x->spy!=root)
                fix_case3(x,r);
		  
	      else if(x->spy->n >=t || x->spy==root)
			    fix_case2(x,r);
			    
		  delete_key(root,k);	     
	   }
    }
}

int main(){
	btree* root=new btree;
	bond* finder=new bond;	

	root->leaf=true;
	root->n=0;
	root->arr=new node[2*t];
	
//   for(int i=13;i>2;i--)                 //Figure(1)
//       insert(root,i);
       
    for(int i=1;i<=15;i++)             //Figure(2)
	   insert(root,i);   
	   
	cout<<"\nBefore deletion\n";   
	traverse(root);
	cout<<"\n";
	
	delete_key(root,8);

    cout<<"\nAfter deletion\n";
	traverse(root);
}

/* 
     Illustration for (1):- (t=2)
 ----------------------------------
 
             10  ,  _
            /        \
        6 , 8 , _     12 , _
       /    |   \     |    \
    3,4,5,_ 7,_  9,_  11,_  13,_
    
                                              (a) where  _ have a undefined key but a defined child pointer in both cases.
                                              (b) each node can have maximum of (2*t) child pointers and (2*t -1) keys.
                                              (c) each node can have minimum of  t child poniters and t-1 keys.
    
    Illustration for (2):- (t=2)
 --------------------------------
 
               4   ,   8   ,   _
			  /        |       \
			 2 , _     6 , _    10 , 12 , _
			/    \     |   \     |   |     \
		   1,_    3,_  5,_  7,_  9,_ 11,_  13,14,15,_

		   
*/		   
		     