#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,ans;
int find(int m) {
    int cnt = 0;
    for(auto item: v) {
        cnt+=item/m;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    long long l,r;
    l = 0, r = INT_MAX;
    while(l <= r) {
        int mid = (l+r)/2;
        int cnt = find(mid);
        if(cnt < K) {
            r = mid-1;
        }
        else {
            ans = mid;
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}