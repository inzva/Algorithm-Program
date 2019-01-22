#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
//#define pb insert
#define pb push_back
#define ALL(c) (c).begin(),(c).end()
#define MP make_pair
#define int2(a,b) scanf("%d %d",&a,&b)
#define int1(a) scanf("%d", &a)
typedef long long int lint;
#define N 2003

bool visited[N][N];
bool homes[N][N];
int main() {
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {   
            visited[i][j]=false;
            homes[i][j]=false;
        }
    }
    int n, g, h, t;
    cin>>n>>g>>h>>t;
    for(int i=0;i<g;i++)
    {
        int x, y;
        int2(x,y);
        visited[x][y] = true;
    }
    for(int i=0;i<h;i++)
    {
        int x, y;
        int2(x,y);
        homes[x][y] = true;
    }

    /*
    for(int i=0;i<a*b;i++)
    {
        cout<<i<<':';
        for(auto x:matr[i].adj) cout<<x<<' ';
        cout<<endl;
    }
    */  
    int dist=0;
    vector<int> ways;
    queue<pair<int, pair<int, int>>> q;
    int ii=0;
    int jj=0;
    q.push(MP(dist, MP(ii,jj)));
    while(!q.empty())
    {
        pair<int, pair<int, int>> p=q.front();
        q.pop();
        int dst=p.fi;
        int i = p.sc.fi;
        int j = p.sc.sc;                
        if(visited[i][j]) continue;
        visited[i][j]=true;
        if(homes[i][j]) ways.pb(dst);
        dst++;
        if(j!=n-1) // en sag degilse: sag
        {
            //if(!visited[i+1]) q.push(i+1);
            if(!visited[i][j+1]) q.push(MP(dst, MP(i, j+1)));
        }

        if(j!=0) // en sol degilse: sol
        {
            //if(!visited[i-1]) q.push(i-1);
            if(!visited[i][j-1]) q.push(MP(dst, MP(i, j-1)));
        }

        if(i!=n-1) // en alt degilse : alt
        {
            //if(!visited[i+b]) q.push(i+b);
            if(!visited[i+1][j]) q.push(MP(dst, MP(i+1, j)));
        }

        if(i!=0) // en ust degilse : ust
        {
            //if(!visited[i-b]) q.push(i-b);
            if(!visited[i-1][j]) q.push(MP(dst, MP(i-1, j)));
        }

    }
    sort(ALL(ways));
    for(int i=0;i<t;i++)
    {
        int x;
        int1(x);
        cout<<upper_bound(ALL(ways),x)-ways.begin()<<'\n';
    }

    
    return 0;
}
