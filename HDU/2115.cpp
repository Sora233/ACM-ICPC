#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct men{
	string name;
	string time;
	int rank;
	men (){
		name.clear();
		time.clear();
	}
}per[15];
int cmp(men a,men b){
	if(a.time!=b.time) return b.time>a.time;
	return a.name<b.name;
}
int main(){
	int n=0,ca=1;
	while(cin>>n&&n){
		int count=1,i=0;
		if(ca!=1) cout<<'\n';
		string t="0";
		cout<<"Case #"<<ca++<<'\n';
		for(i=0;i<n;++i)
			cin>>per[i].name>>per[i].time;
		sort(per,per+n,cmp);
		for(int i=0;i<n;++i){
			per[i].rank=i+1;
		}
		for(int i=0;i<n-1;++i){
			if(per[i].time==per[i+1].time) per[i+1].rank=per[i].rank;
		}
		for(int i=0;i<n;++i)
			cout<<per[i].name<<' '<<per[i].rank<<'\n';
	}
}

