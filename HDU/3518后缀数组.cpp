#include<stdio.h>
#include<algorithm>
#include<string.h>
const int maxn = 1005*6; //空间开6倍
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];  
int rak[maxn],height[maxn];  
int sa[maxn],r[maxn];  
char str[maxn];  
// sa[i] 排第i的是哪个串 rak[i] 第i个串排第几
// sa[1~n]有效 rak[0~n-1]有效
// 定义 height[i]为suffix(sa[i-1])和 suffix(sa[i])，即排名相邻的后缀的最长公共前缀
// height[2~n]有效
int cmp(int *r,int a,int b,int l)  
{  
    return r[a]==r[b]&&r[a+l]==r[b+l];  
}  
  
void da(int *r,int *sa,int n,int m)  
{  
    int i,j,p,*x=wa,*y=wb,*t;  
    for(i=0; i<m; i++) ws[i]=0;  
    for(i=0; i<n; i++) ws[x[i]=r[i]]++;  
    for(i=1; i<m; i++) ws[i]+=ws[i-1];  
    for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;  
    for(p=1,j=1; p<n; j*=2,m=p)  
    {  
        for(p=0,i=n-j; i<n; i++) y[p++]=i;  
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;  
        for(i=0; i<n; i++) wv[i]=x[y[i]];  
        for(i=0; i<m; i++) ws[i]=0;  
        for(i=0; i<n; i++) ws[wv[i]]++;  
        for(i=1; i<m; i++) ws[i]+=ws[i-1];  
        for(i=n-1; i>=0; i--)  
            sa[--ws[wv[i]]]=y[i];  
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++ )  
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  
    }  
}  
  
void calheight(int *r,int *sa,int n)  
{  
    int i,j,k=0;  
    for(i=1; i<=n; i++)  
        rak[sa[i]]=i;  
    for(i=0; i<n; height[rak[i++]]=k)  
        for(k?k--:0,j=sa[rak[i]-1]; r[i+k]==r[j+k]; k++);  
}
int main(){
    while(scanf("%s", str) != EOF && str[0] != '#'){
        int len = strlen(str);
        for(int i = 0; i < len; ++i) r[i] = str[i];
        r[len] = 0;
        da(r, sa, len+1, 129);
        calheight(r, sa, len);
        int l, r, ans = 0;
        for(int i = 1; i <= (len+1)>>1; ++i){
            l = 1005, r = -1;
            for(int j = 2; j <= len; ++j){
                if(height[j] >= i){
                    l = std::min(l, std::min(sa[j], sa[j-1]));
                    r = std::max(r, std::max(sa[j], sa[j-1]));
                }
                else{
                    if(l+i <= r) ans += 1;
                    l = 1005, r = -1;
                }
            }
            if(l+i <= r) ans+= 1;
        }
        printf("%d\n", ans);
    }
}
