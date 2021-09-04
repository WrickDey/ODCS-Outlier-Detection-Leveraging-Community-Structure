/*-------------------------------------------------------------
Program description: API to read the graph in Compressed Sparse Row(CSR) 
--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// graph structure

typedef struct 
{
	int v_count;
	int e_count;
	int* vptr;
	int* eptr;
		
}Graph;

// printing array 



void print_permanence(double* a,int vcount)
{
	printf("\n");
	for(int i = 0;i < vcount;i++)
	printf(" %lf ",a[i]);

	return;
}

void print_array(int* arr, int size){
	int i;
	printf("\n");
	for(i = 0;i < size;i++)
	printf(" %d ",arr[i]);

	return;
}

void print1_array(int* arr, int size){
	int i;
	printf("\n");
	printf("Community membership :");
	for(i = 0;i < size;i++)
	printf(" %d ",arr[i]);

	return;
}

Graph* CSR(char* file_name){


	Graph* csr;
	FILE * fp;
	int i=0,j=0;
	int left_v,right_v,prev_v;
	
	csr = (Graph*) malloc(sizeof(Graph));/* Allocate memory for Graph structure */
	if(csr == NULL){
		printf("\nDynamic memory allocation failed.\n");
		return NULL;
	}
	
	/* open input file */
	
	fp = fopen(file_name,"r");
	fscanf(fp,"%d\n%d\n",&csr->v_count,&csr->e_count);/* read no of vertices and edges from the file */
		
	/* Allocate memory for edge pointer array for vertices */
	csr->vptr = (int*) malloc(csr->v_count * sizeof(int));
	
	if(csr->vptr == NULL){
		printf("\nDynamic memory allocation failed.\n");
		return NULL;
	}
	
	/* Allocate memory for edges of the vertices */
	csr->eptr = (int*) malloc(2*csr->e_count * sizeof(int));
	if(csr->eptr == NULL){
		printf("\nDynamic memory allocation failed.\n");
		return NULL;
	}
	
	
	// Reading the first edge of the graph from file 
	fscanf(fp,"%d,%d\n",&left_v,&right_v);
        while(!feof(fp)){
		prev_v = left_v;
		csr->vptr[i] = j;
		// Condition check for multiple edges originating from same vertex
		while(prev_v == left_v && !feof(fp)){
			csr->eptr[j] = right_v;	
			// Reading each edge from file 
			fscanf(fp,"%d,%d\n",&left_v,&right_v);	
			j++;
			// handling the last edge of the graph
			if(feof(fp)){
				if(prev_v != left_v)
					csr->vptr[++i] = j;
				csr->eptr[j] = right_v;
			}
		}
		i++;
	}
	
	fclose(fp); /* close the file */
	return csr;
	
}

int* readcomm(char* file_name,int vcount)
{
	int* community;
	community=(int*)malloc(vcount*sizeof(int));
	if(community==NULL)
	{
		printf("\nDynamic memory allocation failed.\n");
		return NULL;
	}
	int v=0,c=0;
	FILE* fp=fopen(file_name,"r");
	if(fp==NULL)
	{
		printf("\nFile opening failed.\n");
		return NULL;
	}

	while(!feof(fp))
	{
	fscanf(fp,"%d %d\n",&v,&c);
	community[v]=c;
	
    }
	
	return community;
}

int countcommunity(int* community,int vcount) 
{
	int max=-999999;
	for(int i=0;i<vcount;i++)
	{
		if(community[i]>max)
		max=community[i];
	}
	return max;
}



int* degree(Graph* g)
{
	int* degree=(int*)calloc(g->v_count,sizeof(int));
	for(int i=0;i<g->v_count;i++)
	{
		if(i<g->v_count-1)
		degree[i]=g->vptr[i+1]-g->vptr[i];   //for those vertices are not last.
		else{
			degree[i]=(2*g->e_count)-(g->vptr[i]); // for the last vertex.
		}
	}
	return degree;
	}



int* flagarray(int* degreearray,Graph* g,int* community)
{
	int* flagarr=(int*)calloc(g->v_count,sizeof(int));

	for(int i=0;i<g->v_count;i++)
	{
		if(degreearray[i]==1)
		{
			flagarr[i]=1;
		}
	}
		
		for(int j=0;j<g->v_count;j++)
		{
			if(flagarr[j]==0)
			{
				for(int k=g->vptr[j];k<g->vptr[j+1];k++)
				{
					int adjvertex=g->eptr[k];
					if(community[j]!=community[adjvertex])
						flagarr[j]=2;
						break;
				}
			}
		}
		return flagarr;
} 


Graph* createGraph(char* file_name){
	
	return CSR(file_name);
	
}


double* permanence(Graph* g,int* degreearray,int* community,int countcommunity1)
{
  double* permanence1=(double*)calloc(g->v_count,sizeof(double));
  int *In,*En;
  int i,j;
  double p=0.0;
  In=(int*)calloc(g->v_count,sizeof(int));
  En=(int*)calloc(g->v_count,sizeof(int));
  for( i=0;i<g->v_count;i++)
  {
               int* max_array=(int*)calloc(countcommunity1,sizeof(int));
               int k,s=0.0;
                for(k=0;k<=countcommunity1;k++)
                {   int count=0;
                    for(j=g->vptr[i];j<g->vptr[i+1];j++)
                        {
                            int adj=g->eptr[j];
                            if(k==community[adj])
                                count++;
                        }
                    max_array[k]=count;
                    if(community[i]==k)
                    In[i]=max_array[k];
                    else
                    s=s+1/max_array[k];
                }
          En[i]=degreearray[i]-In[i];
          permanence1[i]=(s/degreearray[i])*(In[i]/En[i]);
          free(max_array);
}
  print_array(In,g->v_count);
  print_array(En,g->v_count);

// // int k,count;

// // for(int i=0;i<g->v_count;i++)
// // {
// // k=0,count=0;
// // while(k<countcommunity1){
// // for(int j=g->vptr[i];j<g->vptr[i+1];j++)
// // {
// // int adj=g->eptr[j];
// // if(community[adj]!=community[i] && community[adj]==k)
// // {
// // count++;
// // }
// // }
// // p+=1/count;
// // k++;
// // }
// // }

// // for(int i=0;i<g->v_count;i++)
// // {
// // permanence1[i]=(p/degreearray[i])*(In[i]/En[i]);
// // }

        return permanence1;

       
}



int main(int argc,char* argv[])
{
	Graph* g=createGraph(argv[1]);
	print_array(g->vptr,g->v_count);
	printf("\n\n");
	print_array(g->eptr,2*g->e_count);
	printf("\n\n");
	int* community=readcomm(argv[2],g->v_count);
	print1_array(community,g->v_count);
	printf("\nThe maximum number of communities is %d",countcommunity(community,g->v_count)+1);
	int* degreearray=degree(g);	
	
	printf("\n\nThe degree of the vertices are : ");
	print_array(degreearray,g->v_count);

	// int* fl=flagarray(degreearray,g,community);
	// printf("\n\nThe flag array is as follows : ");
	// print_array(fl,g->v_count);

	int x=countcommunity(community,g->v_count);
	double* per=permanence(g,degreearray,community,x+1);
	print_permanence(per,g->v_count);
return 0;
}