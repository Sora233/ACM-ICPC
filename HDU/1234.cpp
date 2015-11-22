#include<iostream>
#include<cstring>
using namespace std;
struct me{
	char name[20];
	char in[100];
	char out[100];
}rec[200];
istream& operator>> (istream &in, me &rec){
  in>>rec.name>>rec.in>>rec.out;
  return in;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(rec,0,sizeof(rec));
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>rec[i];
		int in=0,out=0;
		for(int i=1;i<n;i++){
		if(strcmp(rec[in].in,rec[i].in)>0) in=i;
		if(strcmp(rec[out].out,rec[i].out)<0) out=i;
	}
		cout<<rec[in].name<<' '<<rec[out].name<<endl;
	}
}
