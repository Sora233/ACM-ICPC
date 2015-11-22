#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int colo,ans,va,vb,vc,a,b,c,flag; 
struct bo{
	int a,b,c;
	int count;
}start;
bool visit[105][105][105];
void pour(int va,int vb,int &a,int &b){ //把a倒给b 
    int t=vb-b; //b装满的量 
	if(a>=t) a-=t,b=vb;
	else b+=a,a=0;
}
int main(){
	while(scanf("%d%d%d",&va,&vb,&vc)!=EOF&&(va||vb||vc)){
		memset(visit,0,sizeof(visit));
		ans=0xfffffff,colo=va,flag=0;
		start.a=colo,start.b=start.c=start.count=0;
		queue<bo>line;
		visit[start.a][start.b][start.c]=1;
		line.push(start);
		while(!line.empty()){
			bo now=line.front();
			bo next=now;
			++next.count;
			if((!now.a&&now.b==now.c)||(!now.b&&now.a==now.c)||(!now.c&&now.a==now.b)) flag=1,ans=ans>now.count?now.count:ans;
			line.pop();
			pour(va,vb,next.a,next.b);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
			next=now;
			++next.count;
			pour(va,vc,next.a,next.c);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
			next=now;
			++next.count;
			pour(vb,va,next.b,next.a);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
			next=now;
			++next.count;
			pour(vb,vc,next.b,next.c);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
			next=now;
			++next.count;
			pour(vc,va,next.c,next.a);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
			next=now;
			++next.count;
			pour(vc,vb,next.c,next.b);
			if(!visit[next.a][next.b][next.c]){
				visit[next.a][next.b][next.c]=1;
				line.push(next);
			}
		}
		if(flag) printf("%d\n",ans);
		else printf("NO\n");
	}
}

