#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, B, F[250], S[250], D[250], best = 9999;
bool beenthere[250][250];  // set of (location, boot) states we can reach

// recursively search through all reachable states
void visit(int i, int b)
{
    // don't re-visit already-visited states
    if (beenthere[i][b]) return;
    beenthere[i][b] = true;
    
    // reached the end?  keep track of smallest boot # we can achieve
    if (i==N-1) { best = min(best, b); return; }
    
    // try all possible steps forward
    for (int i2=i+1; i2<N && i2-i<=D[b]; i2++)
        if (F[i2]<=S[b]) visit(i2,b);
    
    // try all possible changes of boots
    for (int b2=b+1; b2<B; b2++)
        if (F[i]<=S[b2]) visit(i,b2);
}

int main(void)
{
    ifstream fin ("snowboots.in");
    ofstream fout ("snowboots.out");
    
    fin >> N >> B;
    for (int i=0; i<N; i++) fin >> F[i];
    for (int i=0; i<B; i++) fin >> S[i] >> D[i];
    
    visit(0, 0);
    fout << best << "\n";
    
    return 0;
}
