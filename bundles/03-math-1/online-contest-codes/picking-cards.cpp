#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> c) {
    int maxn = 50005;
    vector<int> counter(maxn);
    
    for(int i=0;i<c.size();i++) counter[c[i]]++;
    
    long long ans = 1;
    long long countIt = 0;
    
    for(int i=0;i<c.size();i++){
        countIt += counter[i];
        ans = (ans * countIt) % 1000000007LL;
        
        
        countIt--;
        if(countIt < 0) return 0;
    }
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int c_count;
        cin >> c_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string c_temp_temp;
        getline(cin, c_temp_temp);
        
        vector<string> c_temp = split_string(c_temp_temp);
        
        vector<int> c(c_count);
        
        for (int i = 0; i < c_count; i++) {
            int c_item = stoi(c_temp[i]);
            
            c[i] = c_item;
        }
        
        int result = solve(c);
        
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}
