#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
struct node{
	string name;
	int sco;
	struct node *next;
	node(){
		next=NULL;
		sco=0;
	}
};
node *Head=NULL,*Tail;
bool update(node *p){
	node *q=Head;
	while(q&&q->name!=p->name) q=q->next;
	if(!q) return 0;
	q->sco=p->sco;
	cout<<"update succeed"<<endl;
	return 1;
}
void creat(){
	node *p=new node;
	cin>>p->name;
	cin>>p->sco;
	if(update(p)) return;
	if(!Head) Head=p;
	else Tail->next=p;
	Tail=p;
	cout<<"A new record"<<endl;
}
void average(){
	node *p=Head;
	int count=0;
	double sum=0;
	while(p){
		sum+=p->sco;
		count++;
		p=p->next;
	}
	if(count) printf("%.2f\n",sum/count);
	else cout<<"0.00"<<endl;
}
bool cmp(node *a,node *b){
	return b->name>a->name;
}
void max(){
	int max=0,count=0;
	node *p=Head;
	node *a[100];
	if(!Head) {
		cout<<"0 0"<<endl;
		return;
	}
	while(p){
		if(p->sco>max) max=p->sco,count=2,a[1]=p;
		else if(p->sco==max) a[count++]=p;
		p=p->next;
	}
	cout<<max<<' '<<count-1<<endl;
	sort(a+1,a+count,cmp);
	for(int i=1;i<count;i++)
	cout<<a[i]->name<<endl;
}
void Delete(){
	string name;
	cin>>name;
	node *p=Head,*q=Head;
	while(p&&p->name!=name) p=p->next;
	if(!p){
		cout<<"no such record"<<endl;
		return;
	}
	if(p==Head){
		if(Tail==Head) Tail=NULL;
		Head=Head->next;
	}
	else {
     	while(q->next!=p) q=q->next;
	    q->next=p->next;
	    if(p==Tail) Tail=q;
    }
     delete p;
    cout<<"delete succeed"<<endl;
}
int main(){
	string intro;
	while(cin>>intro&&intro!="QUIT"){
		if(intro=="NEW") creat();
		if(intro=="AVERAGE") average();
		if(intro=="MAX") max();
		if(intro=="DELETE") Delete();
	}
}
