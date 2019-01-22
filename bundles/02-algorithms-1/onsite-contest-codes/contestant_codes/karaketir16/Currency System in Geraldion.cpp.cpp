#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    bool one= false;
    int n ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1) one = true;
    }
    if(one) cout<<-1;
    else cout<<1;
    return 0;
}
