#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;

struct Node {
    int x,y,z;
}node;
vector< Node > inputList;
int tCount[10];

bool found;
int n,m;
void dfs(int currentIndex){
    if(currentIndex >= n) found = true;
    
    if(found) return;
    
    int firstSize = inputList[currentIndex].x;
    if(tCount[firstSize]){
        tCount[firstSize]--;
        dfs(currentIndex+1);
        tCount[firstSize]++;
    }
    
    int secondSize = inputList[currentIndex].y;
    if(tCount[secondSize]){
        tCount[secondSize]--;
        dfs(currentIndex+1);
        tCount[secondSize]++;
    }
    
    int thirdSize = inputList[currentIndex].z;
    if(tCount[thirdSize]){
        tCount[thirdSize]--;
        dfs(currentIndex+1);
        tCount[thirdSize]++;
    }
    
    
}

int returnTVal(const string &s){
    if(s == "XXS") return 0;
    else if(s == "XS") return 1;
    else if(s == "S") return 2;
    else if(s == "M") return 3;
    else if(s == "L") return 4;
    else if(s == "XL") return 5;
    else return 6;
}

int main(){
    int t, tempM;
    scanf("%d", &t);
    
    string a,b, c;
    while(t--){
        inputList.clear();
        
        scanf("%d %d", &n, &m);
        
        tCount[0] = m / 7, tCount[1] = m / 7, tCount[2] = m / 7, tCount[3] = m / 7, tCount[4] = m / 7, tCount[5] = m / 7, tCount[6] = m / 7;
        
        tempM = n;
        while(tempM--){
            cin >> a >> b >> c;
            node.x = returnTVal(a), node.y = returnTVal(b), node.z = returnTVal(c);
            inputList.emplace_back(node);
        }
        
        found = false;
        dfs(0);
        
        printf(found ? "YES\n" : "NO\n");
    }
    
    
    
    return 0;
}







