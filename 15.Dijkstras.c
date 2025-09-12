#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define INF 999


int count;

void dijkstras(int n,int cost[n][n],int source)
{
    int visit[15]={0};
    int dist[15],u;

    for(int i=1;i<=n;i++)
    {
        dist[i]=cost[source][i];

    }

    visit[source]=1;
    dist[source]=0;

    for(int num=2;num<=n;num++)
    {
        int min=INF;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visit[u]=1;
        for(int j=1;j<=n;j++)
        {
            count++;
            if(!visit[j] && dist[j]>(dist[u]+cost[u][j]))
            {
                dist[j]=dist[u]+cost[u][j];
            }
        }


    }
    printf("\nSourec\tDestination\tCost\n");


    for(int i=1;i<=n;i++)
    {
        printf("%c\t %c\t %d\n",source+64,i+64,dist[i]);
    }

}


void tester()
{
    int n,source;
    printf("\nEnter no of verstices:\n");
    scanf("%d",&n);
    int cost[n][n];
    printf("\nEnter cost matrix:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(i==j)
            {
                cost[i][j]=0;
            }
            if(cost[i][j]==0 && i!=j)
            {
                cost[i][j]=INF;
            }
        }
    }
     printf("\nEnter source");
     scanf("%d",&source);


    dijkstras(n,cost,source);
}


void plotter()
{
    FILE *f=fopen("di","a");
    for(int k=2;k<=10;k++)
    {
        int n=k;
        int cost[n][n];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    cost[i][j]=0;
                }
                else
                {
                    cost[i][j]=rand();
                }
            }
          
        }
        count=0;
            dijkstras(n,cost,1);
            fprintf(f,"%d\t %d\n",n,count);

    
    }
    fclose(f);
}
void main()
{
    int ch;
    printf("\nEnter:\n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid Choice!!");
    }
}
