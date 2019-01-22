#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int total=0,n;
lint v[18];
int group_size[3];
void fonk(int i, vector<lint> &groups)
{
    if(i==n)
    {

        if(groups[1]==groups[2]&&groups[2]==groups[0]&&group_size[0]!=0&&group_size[1]!=0&&group_size[2]!=0)
        {
            total++;
        }
        
        
        return;
        
    }
    for(int a=0;a<3;a++)
    {
        groups[a]+=v[i];
        group_size[a]++;
        fonk(i+1,groups);
        group_size[a]--;
        groups[a]-=v[i];
    }
    
}
int main() {
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%lld",v+i);
        //v[i]+=1000000000000000;
    }
    vector<lint> groups(3,0);
    group_size[0]=group_size[1]=group_size[2]=0;
    fonk(0,groups);
    cout<<total;
    return 0;
}
