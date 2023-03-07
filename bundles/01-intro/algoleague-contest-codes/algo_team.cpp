#include "bits/stdc++.h"

int letters[26];

int main() {
    int N;
    scanf("%d", &N);
    
    char word[35];
    for (int i=0; i < N; i++){
        scanf("%s", word);
        letters[word[0] - 'a']++;
    }
    
    bool flag = false;
    for (int i=0; i < 26; i++)
        if (letters[i] >= 5){
            printf("%c", i + 'a');
            flag = true;
        }
    
    if (!flag)
        printf("inzva\n");
    
    return 0;
}
