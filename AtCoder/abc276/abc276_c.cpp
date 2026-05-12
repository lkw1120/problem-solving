#include<bits/stdc++.h>
using namespace std;
vector<int> P;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    P.resize(N);
    for(int i=0;i<N;i++) {
        cin>>P[i];
    }
    prev_permutation(P.begin(),P.end());
    for(int i=0;i<N;i++) {
        cout<<P[i]<<" ";
    }
    cout<<"\n";
    return 0;
}