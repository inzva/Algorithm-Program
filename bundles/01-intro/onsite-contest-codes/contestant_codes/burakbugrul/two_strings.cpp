#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 15;
const int MAXA = 26; // Alphabet size

int main(){

    int T;

    scanf("%d", &T);

    while(T--){

        char first[MAXN];
        char second[MAXN];

        int first_len;
        int second_len;

        vector<bool> first_occurences(MAXA, false);
        vector<bool> second_occurences(MAXA, false);

        bool result = false;

        scanf("%s%s", first, second);

        first_len = strlen(first);
        second_len = strlen(second);

        for( int i=0 ; i<first_len ; i++ )
            first_occurences[first[i] - 'a'] = true;
        
        for( int i=0 ; i<second_len ; i++ )
            second_occurences[second[i] - 'a'] = true;
        
        for( int i=0 ; i<MAXA ; i++ )
            result |= first_occurences[i] & second_occurences[i]; // Bitwise and operation to check whether i. letter occured in both of the strings
        
        printf("%s\n", result ? "YES" : "NO");
    }


    return 0;
}
