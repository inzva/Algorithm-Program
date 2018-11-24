#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<string> state;
int winCounts[3];

bool checkForDraw() {
    bool isEnd = true;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(state[i][j] == '.') isEnd = false;
        }
    }
    return isEnd;
}

bool checkWinner() {
    for(int i=0;i<3;i++){
        if(state[i][0] == state[i][1] && state[i][1] == state[i][2]){ // Row
            if(state[i][0] == 'X'){
                winCounts[0]++;
                return true;
            }
            if(state[i][0] == 'O') {
                winCounts[1]++;
                return true;
            }
        }
        
        if(state[0][i] == state[1][i] && state[1][i] == state[2][i] ){ // Column
            if(state[0][i] == 'X'){
                winCounts[0]++;
                return true;
            }
            if(state[0][i] == 'O') {
                winCounts[1]++;
                return true;
            }
        }
    }
    
    // Cross - 1
    if(state[0][0] == state[1][1] && state[0][0] == state[2][2]){
        if(state[0][0] == 'X'){
            winCounts[0]++;
            return true;
        }
        if(state[0][0] == 'O') {
            winCounts[1]++;
            return true;
        }
    }
    
    // Cross - 2
    if(state[0][2] == state[1][1] && state[0][2] == state[2][0]){
        if(state[0][2] == 'X'){
            winCounts[0]++;
            return true;
        }
        if(state[0][2] == 'O') {
            winCounts[1]++;
            return true;
        }
    }
    
    if(checkForDraw()){
        winCounts[2]++;
        return true;
    }
    
    return false;
    
}

void dfs(char currentPlayer){
    if(checkWinner()) return;
    // Check
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(state[i][j] == '.'){
                state[i][j] = currentPlayer;
                dfs(currentPlayer == 'O' ? 'X' : 'O');
                state[i][j] = '.';
            }
        }
    }
}

int main() {
    
    state.resize(3);
    for(int i=0;i<3;i++){
        cin >> state[i];
    }
    
    dfs('O');
    
    printf("X wins: %d\n", winCounts[0]);
    printf("O wins: %d\n", winCounts[1]);
    printf("Draw: %d\n", winCounts[2]);
    return 0;
}

