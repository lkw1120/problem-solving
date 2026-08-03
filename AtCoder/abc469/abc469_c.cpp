#include<bits/stdc++.h>
using namespace std;
vector<int> v;
string S;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;
    for(int i=0;i<N;i++) {
        if(S[i] == 'x') {
            v.push_back(i+1);
        }
    }
    for(int i=1;i<=N;i++) {
        if(i <= v.size()) {
            cout<<v[i-1]<<"\n";
        }
        else {
            cout<<N<<"\n";
        }
    }
    return 0;
}