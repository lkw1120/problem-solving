#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(2*N+2);
    for(int i=1;i<=N;i++) {
        cin>>A;
        v[2*i] = v[A]+1;
        v[2*i+1] = v[A]+1;
    }
    for(int i=1;i<=2*N+1;i++) {
        cout<<v[i]<<"\n";
    }
    return 0;
}