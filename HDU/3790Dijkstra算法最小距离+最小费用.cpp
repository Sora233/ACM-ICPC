#include<iostream>
const int inf=0xfffffff;
using namespace std;
struct graph{
	int vernum,edgnum;//定点数 边数 
	int edg[1005][1005]; //包含长度 
	int val[1005][1005]; //花费 
}G;
int dis[1005],val[1005];
void ints(){
	for(int i=0;i<1005;++i)
	for(int j=0;j<1005;++j){
	G.edg[i][j]=inf;
	G.val[i][j]=inf;
    }
}
void Dijkstra(int start){
	bool vis[1005]={0};
	for(int i=1;i<=G.vernum;++i)
		dis[i]=G.edg[start][i],val[i]=G.val[start][i];  //dis保存start点到其他点的距离 不直接相连为inf 
		
	dis[start]=val[start]=0;
	vis[start]=1;
	for(int i=1;i<=G.vernum;++i){
		int mindis=inf,minval=inf,k=start,j;
		for(j=1;j<=G.vernum;++j){
			if(!vis[j]&&(dis[j]<mindis||(dis[j]==mindis&&val[j]<minval))){
				k=j;
				mindis=dis[j];
				minval=val[j];
			}
		}
		vis[k]=1;
		for(j=1;j<=G.vernum;++j){
			int nowdis=G.edg[k][j]+dis[k],nowval=G.val[k][j]+val[k];
			if(!vis[j]&&(nowdis<dis[j]||(nowdis==dis[j]&&nowval<val[j]))){
				dis[j]=nowdis;
				val[j]=nowval;
			}
		}
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){
		int a,b,d,p,s,e;
		ints();
		G.vernum=n,G.edgnum=m;
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(G.edg[a][b]==inf&&G.val[a][b]==inf){
				G.edg[a][b]=G.edg[b][a]=d;
				G.val[a][b]=G.val[b][a]=p;
			}
			else if(d<G.edg[a][b]||(d==G.edg[a][b]&&p<G.val[a][b])) G.edg[a][b]=G.edg[b][a]=d,G.val[a][b]=G.val[b][a]=p;
		}
		scanf("%d%d",&s,&e);
		Dijkstra(s);
		printf("%d %d\n",dis[e],val[e]);
	}
}
