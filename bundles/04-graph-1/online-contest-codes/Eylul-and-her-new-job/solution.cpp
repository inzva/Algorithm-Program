#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <iostream>
#include <climits>
#include <limits>
#include <algorithm>
#include <iostream>
#include <set>
#include <fstream>
#include <queue>
#include <bitset>
#include <map>
#include <ctype.h>

#define ll long long
using namespace std;

struct Node {
    ll totalVal;
    int index;
    
    bool operator<(const Node &o) const  {
        return (totalVal == o.totalVal) ?  (index > o.index) : (totalVal > o.totalVal);
    }
}node,currentNode;

void pushNode(priority_queue <Node> &pq, int i, ll totalVal){
    node.totalVal = totalVal;
    node.index = i;
    pq.push(node);
}

void popSmallest(priority_queue <Node> &pq, ll &counterSecs){
    currentNode = pq.top();
    pq.pop();
    counterSecs = currentNode.totalVal;
}

int main(){
    int n,m;
    
    scanf("%d%d",&n,&m);
    
    vector<ll> cashier(n), customer(m);
    
    for(auto &c : cashier) scanf("%lld", &c);
    for(auto &c : customer) scanf("%lld", &c);
    
    
    priority_queue <Node> pq;
    
    int mCounter = 0;
    
    
    for(int i=0;i<n;i++){
        pushNode(pq, i, cashier[i]*customer[mCounter]);
        mCounter++;
    }
    
    ll counterSecs = 0;
    
    while(mCounter < m){
        popSmallest(pq, counterSecs);
        
        node.totalVal = ( cashier[currentNode.index]*customer[mCounter] ) + counterSecs;
        node.index = currentNode.index;
        pq.push(node);
        
        mCounter++;
    }
    
    while(!pq.empty()) popSmallest(pq, counterSecs);
    
    
    
    
    printf("%lld\n", counterSecs);
    
    return 0;
}

