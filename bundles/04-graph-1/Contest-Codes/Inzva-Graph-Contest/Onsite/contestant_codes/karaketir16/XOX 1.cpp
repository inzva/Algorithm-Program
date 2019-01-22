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
map<char, int> winCount;
char winCheck(vector<vector<char>> mp)
{
    /*
    for(auto r:mp)
    {
        for(auto n:r)
        {
            cout<<n;
        }
        cout<<endl;
    }
    */
    //cout<<endl;
    //cout<<"test"<<endl;
    vector<char> t;
    t.pb('X');
    t.pb('O');
    
    for(auto c:t)
    {
        if((mp[0][0]==c&&mp[0][1]==c&&mp[0][2]==c)
         ||(mp[1][0]==c&&mp[1][1]==c&&mp[1][2]==c)
         ||(mp[2][0]==c&&mp[2][1]==c&&mp[2][2]==c)
         ||(mp[0][0]==c&&mp[1][0]==c&&mp[2][0]==c)
         ||(mp[0][1]==c&&mp[1][1]==c&&mp[2][1]==c)
         ||(mp[0][2]==c&&mp[1][2]==c&&mp[2][2]==c)
         ||(mp[0][0]==c&&mp[1][1]==c&&mp[2][2]==c)
         ||(mp[0][2]==c&&mp[1][1]==c&&mp[2][0]==c))
            
        {
            winCount[c]++;
            return c;
        }
    }
    bool is_draw=1;
    for(auto r:mp)
    {
        for(auto n:r)
        {
            if(n=='.')
            {
                is_draw=0;
            }
        }
    }
    if(is_draw)
    {
        winCount['D']++;
        return 'D';
    }
    return 'm';
}
void dfs(int dept, vector<vector<char>> mp)
{
    if(winCheck(mp)!='m') return;
    char c='O';
    if(dept&1) c='X';
    for(int i = 0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mp[i][j]=='.')
            {
                vector<vector<char>> temp = mp;
                temp[i][j]=c;
                dfs(dept+1, temp);
            }
        }
    }
}
int main() {
    vector<char> r(3);
    vector<vector<char>> mp(3,r);
    for(int i = 0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>mp[i][j];
        }
    }
    dfs(0, mp);
    printf("X wins: %d\nO wins: %d\nDraw: %d\n", winCount['X'],winCount['O'],winCount['D']);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
