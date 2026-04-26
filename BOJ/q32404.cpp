#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N == 1) {
        v.push_back(1);
    }
    else {
        M = N%2 == 0? N: N-1;
        int m = M/2;
        v.push_back(m);
        v.push_back(m+1);
        for(int i=1;i<m;i++) {
            v.push_back(m+1+i);
            v.push_back(m-i);
        }
        if(N%2 == 1) {
            v.push_back(N);
        }
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}