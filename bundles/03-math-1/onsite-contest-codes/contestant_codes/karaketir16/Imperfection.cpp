#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lint;
lint numbers[10000005];
int main() {
    for(lint i=0;i<10000005;i++)
    {
        numbers[i]=i;
    }
    for(lint i=1;i<10000005;i++)
    {
        for(lint j=i+i;j<10000005;j+=i)
        {
            numbers[j]-=i;
        }
    }
    
    for(int i=1;i<10000005;i++)
    {
        numbers[i]=abs(numbers[i])+numbers[i-1];
    }
    
    lint x,y;
    cin>>x>>y;
    cout<<numbers[y]-numbers[x-1];
    return 0;
}
