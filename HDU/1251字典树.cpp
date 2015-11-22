#include<cstring>
#include<cstdio>
using namespace std;
const int N=26;
struct node{
    int ncount;
    struct node *nex[N];
};
struct node mem[1000005];
int alloc=0;
node* creatTrienode(){
    node*p;
    p=&mem[alloc++];
    p->ncount=1;
    for(int i=0;i<N;++i) p->nex[i]=NULL;
    return p;
}
void insertTrie(node **root,char s[]){
    node *p;
    if(!(p=*root)) p=*root=creatTrienode();
    int i=0;
    while(s[i]){
        int k=s[i++]-'a';
        if(p->nex[k]) p->nex[k]->ncount+=1;
        else p->nex[k]=creatTrienode();
        p=p->nex[k];
    }
}
int searchTrie(node **root,char s[]){
    node *p;
    if(!(p=*root)) return 0;
    int i=0;
    while(s[i]){
        int k=s[i++]-'a';
        if(!p->nex[k]) return 0;
        p=p->nex[k];
    }
    return p->ncount;
}
int main(){
    char tmp[20];
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
    	gets(tmp);
        insertTrie(&root,tmp);
    }
    while(gets(tmp)){
        printf("%d\n",searchTrie(&root,tmp));
    }
}
