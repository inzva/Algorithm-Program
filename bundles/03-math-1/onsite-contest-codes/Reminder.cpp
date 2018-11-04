#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector<int> findDivisors(int z){
    vector<int> output;
    
    for(int i=2;i*i<=z;i++){
        if(z%i == 0){
            output.push_back(i);
            
            if(i != z/i) output.push_back(z/i);
        }
    }
    
    output.push_back(z);
    
    return output;
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> inp(n);
    
    for(int i=0;i<n;i++) scanf("%d", &inp[i]);
    
    sort(inp.begin(), inp.end());
    
    int small = inp[0], big = inp[n-1];
    
    vector<int> divisors = findDivisors(big-small);
    
    vector<int> finalArr;
    for(int i=0;i<divisors.size();i++){
        int currentVal = divisors[i];
        
        int rem = inp[0] % currentVal;
        bool flag = true;
        for(int j=1;j<inp.size();j++){
            if(rem != inp[j]%currentVal){
                flag = false;
                break;
            }
        }
        
        if(flag) finalArr.push_back(currentVal);
    }
    
    sort(finalArr.begin(), finalArr.end());
    
    for(int i=0;i<finalArr.size();i++) printf("%d ", finalArr[i]);
    
    printf("\n");
    
    return 0;
}

