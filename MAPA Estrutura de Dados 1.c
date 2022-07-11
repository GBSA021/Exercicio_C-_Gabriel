#include <stdio.h>
#include <math.h>
#include <locale.h>
#define QTD 9999
#define MAX 5

void dijkstra(float G[MAX][MAX],int n,int inicial);

int main(){
  
  int i,j,u,l,p;
  float G[MAX][MAX];
  
  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      G[l][p] = -1;
    }
  }
  
  G[0][1]=13.192;
  G[0][2]=6.596;
  G[1][3]=0;
  G[1][4]=26.384;
  G[2][1]=32.98;
  G[2][4]=0;
  G[3][4]=39.576;
  
  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      printf("%.3f ",G[l][p]);
    }
    printf("\n");
  }
  
  printf("\nINFORME O NODE INICIAL: ");
  scanf("%d",&u);
  dijkstra(G,MAX,u -1);
  
  return 0;
}

void dijkstra(float G[MAX][MAX],int n,int inicial)
{ 
  setlocale(LC_ALL,"Portuguese");
 
  float custo[n][n],distancia[n],pred[n],distanciamin;
  int visitado[n],cont,proxno,i,j;
  
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==-1)
        custo[i][j]=QTD;
      else
        custo[i][j]=G[i][j];
    
  for(i=0;i<n;i++){
    distancia[i]=custo[inicial][i];
    pred[i]=inicial;
    visitado[i]=0;
  }
  
  distancia[inicial]=0;
  visitado[inicial]=1;
  cont=1;
  
  while(cont<n-1){
    distanciamin=QTD;
    for(i=0;i<n;i++)
      if(distancia[i]<distanciamin&&!visitado[i]){
        distanciamin=distancia[i];
        proxno=i;
      }
      
    visitado[proxno]=1;
    for(i=0;i<n;i++){
      if(!visitado[i])
        if(distanciamin+custo[proxno][i]<distancia[i]){
          distancia[i]=distanciamin+custo[proxno][i];
          pred[i]=proxno;
        }
      }
      cont++;
    }
    
    for(i=0;i<n;i++)
      if(i!=inicial){
        printf("\nDISTÂNCIA DO NÓ %d = %.3f ", i+1,distancia[i]);
        printf("		|Caminho = %d",i+1);
        
        j=i;
        do{
          j=pred[j];
          printf("<-%d",j+1);
        }while(j!=inicial);
      }
}

