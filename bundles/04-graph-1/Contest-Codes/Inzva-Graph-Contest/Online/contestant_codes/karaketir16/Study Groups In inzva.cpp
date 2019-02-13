#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
//#define pb insert
#define pb push_back
#define ALL(c) (c).begin(),(c).end()
#define MP make_pair
typedef long long int lint;
#define N 3003

bool visited[N][N];
int a,b;

int main() {
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {   
            visited[i][j]=false;
        }
    }
    lint n, p;
    cin>>n>>p;
    vector<int> groups;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        groups.push_back(x);
    }

    cin>>a>>b;

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {   
            char c;
            cin>>c;
            if(c=='0') visited[i][j]=true;
        }
    }
    /*
    for(int i=0;i<a*b;i++)
    {
        cout<<i<<':';
        for(auto x:matr[i].adj) cout<<x<<' ';
        cout<<endl;
    }
    */  
    vector<int> size_list;
    for(int ii=0;ii<a;ii++)
    {
        for(int jj=0;jj<b;jj++)
        {
            if(visited[ii][jj]) continue;
            int size=0;
            queue<pair<int, int>> q;
            q.push(MP(ii,jj));
            while(!q.empty())
            {
                pair<int, int> p=q.front();
                q.pop();
                int i = p.fi;
                int j = p.sc;
                
                if(i>3001||j>3001||i<0||j<0)
                {
                    cout<<"hata";
                    return 0;
                }
                
                if(visited[i][j]) continue;
                visited[i][j]=true;
                size++;
                if(j!=b-1) // en sag degilse: sag
                {
                    //if(!visited[i+1]) q.push(i+1);
                    if(!visited[i][j+1]) q.push(MP(i, j+1));
                }
                
                if(j!=0) // en sol degilse: sol
                {
                    //if(!visited[i-1]) q.push(i-1);
                    if(!visited[i][j-1]) q.push(MP(i, j-1));
                }

                if(i!=a-1) // en alt degilse : alt
                {
                    //if(!visited[i+b]) q.push(i+b);
                    if(!visited[i+1][j]) q.push(MP(i+1, j));
                }

                if(i!=0) // en ust degilse : ust
                {
                    //if(!visited[i-b]) q.push(i-b);
                    if(!visited[i-1][j]) q.push(MP(i-1, j));
                }
                
                if(i!=0&&j!=0) // en ust ve sol degilse : sol ust
                {
                    //if(!visited[i-b-1]) q.push(i-b-1);
                    if(!visited[i-1][j-1]) q.push(MP(i-1, j-1));
                }
                
                if(j!=b-1&&i!=0)// sag ve ust degil ise: sag ust
                {
                    //if(!visited[i+1-b]) q.push(i+1-b);
                    if(!visited[i-1][j+1]) q.push(MP(i-1, j+1));
                }
                if(j!=b-1&&i!=a-1)//sag ve alt degilse  : sag alt
                {
                    //if(!visited[i+b+1]) q.push(i+b+1);
                    if(!visited[i+1][j+1]) q.push(MP(i+1, j+1));
                }
                if(j!=0&&i!=a-1)//sol ve alt degilse : sol alt
                {
                    //if(!visited[i+b-1]) q.push(i+b-1);
                    if(!visited[i+1][j-1]) q.push(MP(i+1, j-1));
                }
                
                
            }
            if(size!=0) size_list.push_back(size);
        }
    }
    //cout<<"test";
    
    //for(auto x: size_list) cout<<x<<" ";
    //cout<<endl;
    sort(ALL(size_list));
    reverse(ALL(size_list));
    sort(ALL(groups));
    reverse(ALL(groups));

    int i=0, j=0;
    for(;i<n;i++)
    {
        if(j==size_list.size())
        {
            //cout<<"size list "<<j<<" "<<size_list[0]<<endl;
            cout<<-1;
            return 0;
        }
        if(size_list[j]>=groups[i]) j++;
        else 
        {
            //cout<<"tset";
            cout<<-1;
            return 0;
        }
    }
    //cout<<size_list.size()<<endl;

    cout<<p*n;
    
    return 0;
}
