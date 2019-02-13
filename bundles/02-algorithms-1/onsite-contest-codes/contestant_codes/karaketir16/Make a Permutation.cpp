#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lint;
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    lint total=0;
    for(int i=1;i<=n;i++)
    {
        int x=v[i-1];
        total+=abs(x-i);
    }
    cout<<total;
    return 0;
}
