#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lint;
int n;
vector<int> arr;
lint f( lint b)
{
    lint result =0;
    for(int i=0;i<n;i++)
    {
        lint x=arr[i]-b;

        result += abs(x);
        
    }
    return result;
}
double ternarySearch(lint left, lint right, double eps=0)
{
    while (right - left > eps)
    {
        //cout<<"test "<<left<<" "<<right<<endl;
        lint mid1 = left + (right - left) / 3;
        lint mid2 = right - (right - left) / 3;
        if(f(mid1) > f(mid2)) left = mid1;
        else right = mid2;
        if(right-left==2)
        {
            int min_i=0;
            for(int i=0;i<3;i++)
            {
                if(f(left+i)<f(left+min_i)) min_i=i;
            }
            return left+min_i;
        }
    }
    //cout<<left<<endl;
    return left;
}
int main() {

    cin >> n;
    for(int i=1;i<n+1;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x-i);
    }

    //cout<<"deneme: "<<f(0)<<endl;

    cout<<f(ternarySearch(-1000000000,1000000000));
    return 0;
}
