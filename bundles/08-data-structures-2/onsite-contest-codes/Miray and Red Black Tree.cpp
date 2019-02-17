#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int rev=0;
    while(n--)
    {
        string s;
        cin >> s;
        if(s=="Qi") rev^=1;
        else {
            int a,b;
            cin >> a >> b;
            int ln=1;
            int ya=a;
            int yb=b;
            while(a!=b)
            {
                if(a>b)
                    a/=2;
                else
                    b/=2;
                ln++;
            }// ln aradaki path uzunlugu
            int cl=0;
            while(ya)
            {
                ya/=2;
                cl^=1;
            } // cl se y siyah demektir
            cl= cl^rev;
            if(ln%2==0)
            {
                cout << ln/2 << endl;
            }
            else
            {
                if(s=="Qb")
                {
                   cout << ln/2+cl << endl ;         
                }
                else
                {
                   cout << ln/2+(1-cl) << endl;
                }
            }
        }
    }
    return 0;
}
