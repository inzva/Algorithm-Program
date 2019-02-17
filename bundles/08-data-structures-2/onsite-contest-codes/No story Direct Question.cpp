#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

const int l = 17;

using namespace std;

int n, m;
vector<pair<int, int> > g[N];
vector<pair<int, pair<int, int> > > edges, edges2,mst;
int w[N];
long long COST;
int timer;
int up[N][l + 1];
int bedge[N][l + 1];
int tin[N];
int tout[N];
int dep[N];

void dfs(int v, int p = 1,int pcost=0)
{
    tin[v] = timer;
    ++timer;
    up[v][0] = p;
    bedge[v][0] = pcost;
    for (int i = 1; i <= l; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
        bedge[v][i] = max(bedge[v][i - 1], bedge[up[v][i-1]][i - 1]);
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i].first;
        int cost = g[v][i].second;
        if (to == p)
            continue;
        dep[to] = dep[v] + 1;
        dfs(to, v, cost);
    }
    tout[v] = timer;
    ++timer;
}

bool upper(int a, int b)
{
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b)
{
    if (upper(a, b))
        return a;
    if (upper(b, a))
        return b;
    for (int i = l; i >= 0; --i)
    {
        if (!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

int get(int x)
{
    if (x == w[x])
        return x;
    return w[x] = get(w[x]);
}

void merge(int a, int b)
{
    if (rand() % 2)
        swap(a, b);
    a = get(a);
    b = get(b);
    w[a] = b;
}

int get_best(int v, int span)
{
    int ret = 0;
    for (int i = l; i >= 0; --i)
    {
        if (span&(1 << i))
        {
            ret = max(ret, bedge[v][i]);
            v = up[v][i];
        }
    }
    return ret;
}

int main(){
    //freopen("beavers.in","r",stdin);
    //freopen("beavers.out","w",stdout);
    //freopen("F:/in.txt","r",stdin);
    //freopen("F:/output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(c, make_pair(a, b)));
        edges2.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
    {
        w[i] = i;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int a, b, c;
        a = edges[i].second.first;
        b = edges[i].second.second;
        int ta, tb;
        c = edges[i].first;
        ta = get(a);
        tb = get(b);
        if (ta == tb)
            continue;
        merge(ta, tb);
        mst.push_back(make_pair(c, make_pair(a, b)));
        COST += c;
    }

    for (int i = 0; i < mst.size(); i++)
    {
        int v1 = mst[i].second.first;
        int v2 = mst[i].second.second;
        int cost = mst[i].first;
        g[v1].push_back(make_pair(v2, cost));
        g[v2].push_back(make_pair(v1, cost));
    }
    
    dfs(1);

    for (int i = 0; i < edges2.size(); i++)
    {
        int v1 = edges2[i].second.first;
        int v2 = edges2[i].second.second;
        int L = lca(v1, v2);
        int bst = 0;
        bst = max(bst, get_best(v1, dep[v1] - dep[L]));
        bst = max(bst, get_best(v2, dep[v2] - dep[L]));
        cout << COST + edges2[i].first - bst << "\n";
    }

    cin.get();cin.get();

    return 0;
}