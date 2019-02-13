#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    double n,l;
    cin>>n>>l;
    vector<double> points;
    
    for(int i=0;i<n;i++)
    {
        double x;
        cin>>x;
        points.push_back(x);
    }
    sort(points.begin(),points.end());
    double maxx=0;
    maxx=max(maxx,points[0]);
    maxx=max(maxx,l-points[n-1]);
    double maxx_bosluk =0;
    for(int i=1;i<n;i++)
    {
        
        maxx_bosluk=max(maxx_bosluk,(points[i]-points[i-1]));
    }
    maxx_bosluk/=2;
    cout<<setprecision(10)<<max(maxx,maxx_bosluk);
    return 0;
}
