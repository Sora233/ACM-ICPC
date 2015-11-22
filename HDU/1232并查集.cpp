#include<iostream>
using namespace std;
int a[1005];
void ints(){
	for(int i=0;i<1005;i++)
	a[i]=-1;
}
int find(int x){
	if(a[x]>=0) a[x]=find(a[x]);
	else return x;
	return a[x];
}
/*
int find(int x){
	return seed[x]<0?x:seed[x]=find(seed[x]);
}
*/
void join(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(a[x]>a[y]){
		a[y]+=a[x];
		a[x]=y;
	}
	else {
		a[x]+=a[y];
		a[y]=x;
	}
}
int main(){
	int city,road;
	while(cin>>city&&city){
		cin>>road;
		ints();
		int x1,x2;
		for(int i=1;i<=road;i++)
		{
			cin>>x1>>x2;
			join(x1,x2);
		}
		int ans=-1;
		for(int i=1;i<=city;i++)
		if(a[i]<0) ans++;
		cout<<ans<<endl;
	}
}
