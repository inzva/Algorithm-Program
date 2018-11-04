#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    ll n,k;
    scanf("%lld %lld", &n, &k);
    
    vector<ll> ns(n);
    for(auto &i:ns) scanf("%lld",&i);
    
    ll g = ns[0];
    for(int i=1;i<n;i++) g = gcd(g, ns[i]);
    
    
    ll res = max(res, k - (k%g));
    for(ll i=2;i*i<=g && i < k;i++){
        if(g%i == 0){
            res = max(res, k - (k%i));
            res = max(res, k - (k%(g/i)));
        }
    }
    
    printf("%lld\n", res);
    
    return 0;
}


