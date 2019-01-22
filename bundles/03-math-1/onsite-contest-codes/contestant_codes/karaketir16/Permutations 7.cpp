#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long int lint;
lint fac(lint x, lint y)
{
    lint result=1;
    for(int i=0;i<y;i++)
    {
        result*=(x-i);
        result=result%mod;
    }
    return result;
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<fac(x,y);
    return 0;
}
