#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
const int MN=100505;
struct node{ //记录炸弹
    int x,y,d;
}bom[MN];
struct st{ //多重集的元素
    int y,x;
    st(){}
    st(int a,int b){y=a,x=b;}
    bool operator<(st a)const{
        return y<a.y;
    }
};
int mak[MN]; //离散
multiset<st>:: iterator L,R;
multiset<st> mst[MN];
bool boom[100015]; //标记是否炸了
int main()
{
    int n,m,ca=1;
    while( scanf("%d", &n) != EOF && n )
    {
        printf("Case #%d:\n", ca++);

        memset( mak, 0, sizeof(mak) );
        memset( boom, 0, sizeof(boom) );
        for(int i = 0; i <= n +10; ++i) mst[i].clear();

        for(int i = 0; i < n; ++i){
                scanf("%d %d %d", &bom[i].x, &bom[i].y, &bom[i].d);
                //bom[i].nb=i;
                mak[i]=bom[i].x;
        }
        sort(mak, mak + n);
        int cnt = unique(mak, mak + n) - mak;
        for(int i=0;i<n;++i)
		{
        	int p=lower_bound(mak, mak + cnt, bom[i].x) - mak;
        	mst[p].insert( st(bom[i].y, i) );
        }
        /*sort(bom, bom + n);
        int cnt = 1;
        mak[0] = bom[0].x;
        mst[0].insert( st(bom[0].y,bom[0].nb) );
        for(int i=1;i<n;++i)
        {
        	if(bom[i].x!=mak[cnt-1])
			{
				mak[cnt]=bom[i].x;
				mst[cnt++].insert( st(bom[i].y,bom[i].nb) );
        	}
        	else mst[cnt-1].insert( st(bom[i].y,bom[i].nb) );
        }
        sort(bom, bom + n, cmp);
        */
        scanf("%d", &m);
        while( m-- )
        {
            int num, ans = 0;
            scanf( "%d", &num);
            num -= 1;
            if( boom[ num] ) { puts("0"); continue; }
            boom[ num] = 1;
            queue< int >q;
            q.push(num);
            while( !q.empty() )
            {
                int now = q.front(); q.pop(); ans += 1;
                int l = lower_bound( mak, mak + cnt, bom[ now].x - bom[now].d ) - mak;
                int r = upper_bound( mak, mak + cnt, bom[now].x + bom[now].d ) - mak;
                for(int i = l; i < r; ++i)
                {
                    int ef = bom[ now].d - abs( bom[ now].x - mak[i] );
                    L = mst[i].lower_bound( st(bom[ now].y - ef, 0) );
                    R = mst[i].upper_bound( st(bom[ now].y + ef, 0) );
                    for(multiset<st>:: iterator it = L; it != R; ++it)
                    {
                        if( !boom[it -> x])
                        {
                            boom[it -> x] = 1;
                            q.push(it -> x);
                        }
                    }
                    mst[i].erase(L, R);
                }
            }
            printf("%d\n", ans);
        }
    }
}
