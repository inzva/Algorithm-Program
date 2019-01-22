#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
using namespace std;


int main() 
{
    /*
    vector<int> fibo;
    fibo.pb(0);
    fibo.pb(1);
    while((*(fibo.end()-1))<10000005)
    {
        fibo.pb((*(fibo.end()-1))+(*(fibo.end()-2)));
    }
    vector<bool> isFibo(10000005,false);
    for(auto x:fibo) 
    {
        if(x<10000005)isFibo[x]=true;
        //cout<<x<<endl;
    }
    */
    vector<bool> isFibo(10000005,false);
    int x=0;
    int y=1;
    isFibo[0]=true;
    while(y<10000005)
    {
        isFibo[y]=true;
        int temp=y;
        y=x+y;
        x=temp;
    }
    vector<bool> isPrime(10000005,true);
    vector<bool> isCube(10000005,false);
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<10000005;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<10000005;j+=i)
            {
                isPrime[j]=false;
            }
            //cout<<i<<endl;
        }
    }
     
    for(int i=1;i*i*i<10000005;i++)
    {
        isCube[i*i*i]=true;
    }
    /////////////////////////////////////////////
    /////////////////////////////////////////////
   
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    while(q--)
    {
        
        scanf("%d %d",&x,&y);
        if(x==1)
        {
            if(isFibo[v[y-1]]) printf("Fibonacci\n");
            else printf("Not Fibonacci\n");
        }
        else if(x==2)
        {
            if(isPrime[v[y-1]]) printf("Prime\n");
            else printf("Not Prime\n");   
        }
        else 
        {
            if(isCube[v[y-1]]) printf("Cube\n");
            else printf("Not Cube\n");
        }
    }
    
    return 0;
    
}
