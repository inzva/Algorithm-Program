#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 20005
#include <set>
using namespace std;
struct Node
{
    bool visited=0;
    vector<int> adj;
};
void dfs(int &tek, int &cift, int depth, int r, Node *all)
{
    if(all[r].visited) return;
    all[r].visited=true;
    if(depth&1) tek++;
    else cift++;
    for(auto x: all[r].adj) dfs(tek, cift, depth+1, x, all);
    
}
int main() {
    int t;
    cin>>t;
    
    for(int a=1;a<=t;a++)
    {
        set<int> numbers;
        Node all[N];
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            all[x].adj.push_back(y);
            all[y].adj.push_back(x);
            numbers.insert(x);
            numbers.insert(y);
        }
        int result=0;
        for(auto r: numbers)
        {
            int tek=0, cift=0;
            dfs(tek, cift, 0, r, all);
            result+=max(tek, cift);
        }
        printf("Case %d: %d\n", a, result);
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
