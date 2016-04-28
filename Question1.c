/* Basundhara Dey ****************/
/** NID #: ba407257*************/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
 
int main(void)
{
int n,x,y,i,j,s;
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

//Initiating n*n  matrix */

for(i=0;i<n;i++) 
{
for(j=0;j<n;j++)
 {
    adj[i][j]=0;
 }
}

//Number of edges in the undirected graph

m = n*p*(n-1)/2.0;
printf("\nNumber of edge = %d\n",m);

/* Adjecency Matrix for n*n */

for(i=1;i<=m;i++)
{
x = rand() %n;
y = rand() %n;
if(x == y)
i--;
else if(adj[x][y] == 1)
i--;
else
{
/*to change the any random Zero to One*/
adj[x][y] = 1;
adj[y][x] = 1;
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

f = fopen("adjacency.txt", "w");

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
fclose(f);

return 0;
}

 else
printf("Hard Luck!! Try again");
}

