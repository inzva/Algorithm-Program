#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
    int n , l , r;
    string s;
    cin >> n >> l >> r;
    l--;
    r--;
    cin >> s;
    deque <char> s1,s2,s3;
    for(int i=0;i<l;i++)
        s1.push_back(s[i]);
    for(int i=l;i<=r;i++)
        s2.push_back(s[i]);
    for(int i=r+1;i<n;i++)
        s3.push_back(s[i]);
    int q;
    cin >> q;
    int rev=0;
    for(int i=0;i<=q;i++)
    {
        cin >> s;
        if(s=="R")
        {
            rev^=1;
        }
        if(s=="Q")
        {
            cin >> s;
            if(s=="L")
                if(!rev)
                    cout << s2.front() ;
                else
                     cout << s2.back() ;
            if(s=="R")
                if(rev)
                    cout << s2.front() ;
                else
                    cout << s2.back() ;
        }
        if(s=="S")
        {
            string o1,o2;
            cin >> o1 >> o2;
            if(o1=="L" && o2=="L")
            {
                if(rev==0)
                {
                    s2.push_front(s1.back());
                    s1.pop_back();
                }
                else
                {
                    s2.push_back(s1.back());
                    s1.pop_back();
                }
            }
            if(o1=="L" && o2=="R")
            {
                if(rev==0)
                {
                    s1.push_back(s2.front());
                    s2.pop_front();
                }
                else
                {
                    s1.push_back(s2.back());
                    s2.pop_back();
                }
            }
            if(o1=="R" && o2=="L")
            {
                if(rev==0)
                {
                    s3.push_front(s2.back());
                    s2.pop_back();
                }
                else
                {
                    s3.push_front(s2.front());
                    s2.pop_front();
                }
            }
            if(o1=="R" && o2=="R")
            {
                if(rev==0)
                {
                    s2.push_back(s3.front());
                    s3.pop_front();
                }
                else
                {
                    s2.push_front(s3.front());
                    s3.pop_front();
                }
            }
        }
    }
}
