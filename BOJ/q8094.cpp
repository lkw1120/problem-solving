#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int W,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>W;
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int n = N-1;
    ans = 0;
    for(int i=0;i<N;i++) {
        if(n < i) break;
        while(W < v[i]+v[n]) {
            ans++;
            n--;
        }
        if(0 <= n && v[i]+v[n] <= W) {
            ans++;
            n--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}