#include<bits/stdc++.h>
using namespace std;
vector<int> p,q,v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    p.resize(N);
    q.resize(N);
    for(int i=0;i<N;i++) {
        cin>>p[i];
    }
    for(int i=0;i<N;i++) {
        cin>>q[i];
    }
    v.resize(N);
    iota(v.begin(),v.end(),1);
    int pIdx = -1;
    int qIdx = -1;
    int cnt = 0;
    do {
        if(v == p) {
            pIdx = cnt;
        }
        if(v == q) {
            qIdx = cnt;
        }
        cnt++;
    } while(next_permutation(v.begin(),v.end()));
    ans = max(0,qIdx-pIdx-1);
    cout<<ans<<"\n";
    return 0;
}