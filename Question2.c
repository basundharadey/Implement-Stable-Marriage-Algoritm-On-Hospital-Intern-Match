/* Basundhara Dey ****************/
/** NID #: ba407257*************/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void)
{
int n,a,b,i,j,y;
float p;
int m;
FILE *f;

/*Implementing the rank function.*/

srand(time(NULL));
n = (rand()%6 + 5);

printf("\nNumber of Vertices = %d\n",n); //randomly generated

printf("Enter a  value between .3 and .7 for the density of graph:");
scanf("%f",&p);
/* to store denisty*/
if(p>=0.3 && p<= 0.7)  

{
int adj[n][n];

/*Initializing n*n  matrix */
for(i=0;i<n;i++) 
{
	for(j=0;j<n;j++) 
	{
      adj[i][j]=0;
    }
}

/*No. of edge in the undirected graph*/

m = n*p*(n-1)/2.0;
printf("\nNumber of edge = %d\n",m);

/* Adjecency Matrix for n*n */

for(i=1;i<=m;i++)
{
a = rand() %n;
b = rand() %n;
if(a == b)
i--;
else if(adj[a][b] == 1)
i--;
else
{
/*alterig the any random Zero to One*/
adj[a][b] = 1;
adj[b][a] = 1;
}
}

printf("\nThe Adjacency Matrix is:\n\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\t%d",adj[i][j]);
}
printf("\n");
}
/* Initiate degree sequence with all zeros */

int DS[n];
for(i=0;i<n;i++)
{
DS[i]=0;
}
/*degree sequence returning */

for(i=0;i<n;i++)
{
for (j=0;j<n;j++)
{
DS[i]=DS[i]+adj[i][j];
}
}
for (i = 1 ; i < n; i++)
 {
while ( i > 0 && DS[i] > DS[i-1]) 
{
  y = DS[i];
  DS[i]   = DS[i-1];
  DS[i-1] = y;
  i--;
}
  }

  printf("The Degree Sequence\n");

  for (i = 0; i < n; i++) 
  {
printf("%d \t", DS[i]);
  }
  
  f = fopen("degree sequence.txt", "w");

fprintf(f, "******Basundhara Dey******\n");
fprintf(f, "******NID ba407257******\n");

fprintf(f, "edges:%d\n",m);
fprintf(f, "vertices:%d\n",n);


for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
fprintf(f,"\t%d",adj[i][j]);
}
fprintf(f,"\n");
}
fprintf(f,"\n\n\n");
fprintf(f, "degree sequence: %d \t");	
for (i = 0; i < n; i++) 
{
fprintf(f, "%d \t", DS[i]);
}
fclose(f);

return 0;
}
}
