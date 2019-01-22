#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n;
bool check;
void dfs(int i, map<string, int> sizes, vector<vector<string>> &sz)
{
    if(i==n)
    {
        //for(auto test: sizes) cout<<test.first<<' '<<test.second<<endl;
        check=true;
    }
    if(check) return;
    for(auto x: sz[i])
    {
        map<string, int> temp=sizes;
        temp[x]--;
        //cout<<"tst: "<<temp[x]<<" "<<x<<endl;
        if(temp[x]<0) return;
        else dfs(i+1, temp, sz);
    }
}
int main() {
    int t;
    cin>>t;
    map<string, int> sizes;
    while(t--)
    {
        check = false;
        int x,y;
        cin>>x>>y;
        n=x;
        sizes["XXS"]=y/7;
        sizes["XS"]=y/7;
        sizes["S"]=y/7;
        sizes["M"]=y/7;
        sizes["L"]=y/7; 
        sizes["XL"]=y/7;
        sizes["XXL"]=y/7;
        vector<vector<string>> sz(x);
        for(int i=0;i<x;i++)
        {
            string a,b,c;
            cin>>a>>b>>c;
            sz[i].pb(a);
            sz[i].pb(b);
            sz[i].pb(c);
        }
        dfs(0, sizes, sz);
        if(check) cout<<"YES\n";
        else cout<<"NO\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
