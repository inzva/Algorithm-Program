#include <bits/stdc++.h>
using namespace std;
void fs(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int main()
{
    int t,n;
    fs(t);
    for(int o=1;o<=t;o++)
    {
        fs(n);
        //Operation - 1
        set<int> node[20001];
        bool visit[20001]={true};
        int isthere[20001]={0};
        
        //Operation - 2
        for(int i=0;i<n;i++)
        {
            int a,b;
            fs(a);fs(b);
            
            node[a].insert(b);
            node[b].insert(a);
            
            visit[a]=false;
            visit[b]=false;
            isthere[a]=1;
            isthere[b]=1;
        }
        
        //Operation - 3
        int lv[2]={0};
        int a=1;
        int sum=0;
        for(int i=1;i<20001;i++)
            if(isthere[i]==1 && visit[i]==false)
            {
                queue<pair<int,int>> buffer;
                buffer.push(make_pair(i,0));
                visit[i]=true;
                lv[0]++;
                
                while(!buffer.empty())
                {
                    int x=buffer.front().first;
                    int ch=buffer.front().second;
                    buffer.pop();
                    for(set <int>::iterator it = node[x].begin();it != node[x].end();++it)
                        if(visit[*it]==0)
                        {
                            buffer.push(make_pair(*it,(ch+1)%2));
                            visit[*it]=true;
                            lv[(ch+1)%2]++;
                        }
                }
                sum=sum+max(lv[0],lv[1]);
                lv[0]=0;
                lv[1]=0;
            }
        
        
        cout<<"Case "<<o<<": "<<sum<<endl;
        for(int i=0;i<20001;i++)
            node[i].clear();
    }
}
