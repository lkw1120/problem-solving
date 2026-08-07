#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v,vv;
int N,D,K,L,R,S,T;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>D>>K;
    for(int i=0;i<D;i++) {
        cin>>L>>R;
        v.push_back({L,R});
    }
    for(int i=0;i<K;i++) {
        cin>>S>>T;
        vv.push_back({S,T});
    }
    for(int i=0;i<K;i++) {
        auto [s,t] = vv[i];
        int left,right;
        left = right = s;
        for(int j=0;j<D;j++) {
            auto [l,r] = v[j];
            if(l <= right && left <= r) {
                left = min(left,l);
                right = max(right,r);
            }
            if(left <= t && t <= right) {
                cout<<j+1<<"\n";
                break;
            }
        }
    }
    return 0;
}