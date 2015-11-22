#include<map>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		map<int,queue<int> >mp;
		int tmp;
		for(int i=1;i<=n;++i){
			scanf("%d",&tmp);
			mp[tmp].push(i);
		}
		while(m--){
			scanf("%d",&tmp);
			queue<int> &p = mp[tmp];
			if(p.empty()) puts("-1");
			else {
				printf("%d\n",p.front());
				p.pop();
			}
		}
	}
}
