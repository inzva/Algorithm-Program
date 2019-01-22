#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
struct Node
{
    bool visited=false;
    set<int> adj;
    bool bagli=false;
    bool kilitli=false;
};
lint total=0;
lint m;
Node nodes[5000005];
void dfs(lint way,lint node)
{
    if(nodes[node].visited) return;
    else nodes[node].visited=true;
    for(auto x:nodes[node].adj)//dfs
    {
        dfs(way+1,x);
    }
    lint bagli_sayisi=0;
    lint kilitli_sayisi=0;
    for(auto x:nodes[node].adj)//childlarda kac tane bagli ve kilitli var say
    {

        if(nodes[x].bagli) bagli_sayisi++;
        if(nodes[x].kilitli) kilitli_sayisi++;
    }
    if((way>1&&bagli_sayisi>0)&&bagli_sayisi>kilitli_sayisi)//ise kendine bagla kitle
    {
        total-=(bagli_sayisi*m);
        total+=(kilitli_sayisi*m);
        total+=m;
        nodes[node].bagli=true;
        nodes[node].kilitli=true;
    }
    else if(way>2&&bagli_sayisi==0)//ise kendine bagla
    {
        nodes[node].bagli=true;
        total+=m;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lint n;
    cin>>n>>m;
    
    for(lint i=0;i<n-1;i++)
    {
        lint x,y;
        cin>>x>>y;
        nodes[x].adj.insert(y);
        nodes[y].adj.insert(x);
    }
    dfs(0,1);
    cout<<total;
    return 0;
}
