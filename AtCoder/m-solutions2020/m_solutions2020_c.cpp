#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=K;i<N;i++) {
        if(v[i] > v[i-K]) {
            cout<<"Yes"<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}