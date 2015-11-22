#include<stdio.h>
#include<stdlib.h>
typedef struct chain{
int num;
struct chain *next;
}chain;
int size=sizeof(chain);
chain *Set(int a){
chain *p,*head=NULL,*tail=NULL;
int x;
while(a--){
scanf("%d",&x);
p=(chain*)malloc(size);
p->num=x;
p->next=NULL;
if(head==NULL)
head=p;
else
tail->next=p;
tail=p;
}
return head;
}
chain *Dele_chain(chain 
*head,int n){
chain *p1=head,*p2;
while(p1!=NULL&&p1->num!=n){
p2=p1;
p1=p1->next;
}
if(p1==NULL) return head;
else{
if(p1==head){
head=head->next;
free(p1);
}
else {
p2->next=p1->next;
free(p1);
}
}
return head;
}
void Prin_chain(chain *head){
chain *p=head;
if(p==NULL) printf("NULL\n");
else{
printf("%d",p->num);
head=head->next;
free(p);
while(head!=NULL){
printf(" %d",head->num);
p=head;
head=head->next;
free(p);
}
printf("\n");
}
}
int Count(chain *head){
int i=0;
chain *p=head;
while(p!=NULL){
p=p->next;
i++;
}
return i;
}
void Sort_chain(chain *head) //从小到大排序 
{
int len=Count(head),temp;
chain *q1,*q2;
for(q1=head;q1!=NULL;q1=q1->next)
for(q2=q1->next;q2!=NULL;q2=q2->next)
if(q1->num>q2->num) temp=q1->num,q1->num=q2->num,q2->num=temp;
}
main(){
int a,b;
chain *head_a;
while(scanf("%d%d",&a,&b)!=EOF){
int x,n,i=0;
head_a=Set(a);
for(i=0;i<b;i++){
scanf("%d",&n);
head_a=Dele_chain(head_a,n);
}
Sort_chain(head_a);
Prin_chain(head_a);
}
}
