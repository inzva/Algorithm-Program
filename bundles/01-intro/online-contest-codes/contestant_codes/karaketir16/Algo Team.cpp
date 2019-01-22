#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>

typedef long long int lint;

int main()
{
    int arr[26];
    for(int i=0;i<26;i++) arr[i]=0;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        arr[s[0]-'a']++;
    }
    bool en_az_bir=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>=5)
        {
            printf("%c",i+'a');
            en_az_bir=true;
        }
    }
    if(!en_az_bir) cout<<"inzva";
    return 0;
}