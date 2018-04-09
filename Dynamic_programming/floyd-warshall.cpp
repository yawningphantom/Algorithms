// algorithm to find all pair of shortest path in a graph

#include<iostream>

#define INF 99999
#define V 4

using namespace std;

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<" ";
            else
              cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int floydWarshall(int k[][V]){
  int i,j,n=4;
  for(int v=0 ; v<V ;v++){
    for(i=0 ; i<V ;i++){
      for(j=0;j<V;j++){
        if(k[i][v] + k[v][j] < k[i][j])
          k[i][j] = k[i][v] + k[v][j];
      }
    }
  }
  printSolution(k);
  return 0;

}



int main(){
 int K[V][V];
 // for (int i =0 ;i<V;i++){
 //   for(int j=0;j<V;j++){
 //    cin>>K[i][j];
 //   }
 // }

 int graph[V][V] = { {0,   5,  INF, 10},
                       {INF, 0,   3, INF},
                       {INF, INF, 0,   1},
                       {INF, INF, INF, 0}
                     };

 floydWarshall(graph);

  return 0;
}
