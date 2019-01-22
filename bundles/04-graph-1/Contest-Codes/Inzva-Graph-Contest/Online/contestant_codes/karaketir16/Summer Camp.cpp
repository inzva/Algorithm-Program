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
#define N 8

bool visited[N][N];
int main() {
    int n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {   
                visited[i][j]=false;
            }
        }
        //cout<<"deneme";
        char c1, c2;
        int i1,i2,j1,j2;
        cin>>c1>>j1>>c2>>j2;
        i1=c1-'a';
        i2=c2-'a';
        j1--;
        j2--;
        
        //cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
        int dist=0;
        queue<pair<int, pair<int, int>>> q;        
        q.push(MP(dist, MP(i1,j1)));
        while(!q.empty())
        {
            pair<int, pair<int, int>> p=q.front();
            q.pop();
            int dst=p.fi;
            int i = p.sc.fi;
            int j = p.sc.sc;               
            //cout<<i<<" "<<j<<endl;

            if(i==i2&&j==j2)
            {
                printf("To get from %c%d to %c%d takes %d knight moves.\n", c1, j1+1, c2, j2+1, dst);
                break;
            }
            if(visited[i][j]) continue;
            visited[i][j]=true;
            dst++;
            if(j<6) // en sag degilse: sag
            {
                //if(!visited[i+1]) q.push(i+1);
                if(i>0&&!visited[i-1][j+2]) q.push(MP(dst, MP(i-1, j+2)));
                if(i<7&&!visited[i+1][j+2]) q.push(MP(dst, MP(i+1, j+2)));
            }

            if(j>1) // en sol degilse: sol
            {
                //if(!visited[i-1]) q.push(i-1);
                if(i>0&&!visited[i-1][j-2]) q.push(MP(dst, MP(i-1, j-2)));
                if(i<7&&!visited[i+1][j-2]) q.push(MP(dst, MP(i+1, j-2)));
            }

            if(i<6) // en alt degilse : alt
            {
                //if(!visited[i+b]) q.push(i+b);
                if(j>0&&!visited[i+2][j-1]) q.push(MP(dst, MP(i+2, j-1)));
                if(j<7&&!visited[i+2][j+1]) q.push(MP(dst, MP(i+2, j+1)));
            }

            if(i>1) // en ust degilse : ust
            {
                //if(!visited[i-b]) q.push(i-b);
                if(j>0&&!visited[i-2][j-1]) q.push(MP(dst, MP(i-2, j-1)));
                if(j<7&&!visited[i-2][j+1]) q.push(MP(dst, MP(i-2, j+1)));
            }

        }
    }

    
    return 0;
}
