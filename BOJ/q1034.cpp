#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
vector<string> v;
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    cin>>K;
    for(auto item: v) {
        mp[item]++;
    }
    ans = 0;
    for(auto [a,b]: mp) {
        int cnt = count(a.begin(),a.end(),'0');
        if(cnt <= K && ((K-cnt)%2 == 0)) {
            ans = max(ans,b);
        }
    }
    cout<<ans<<"\n";
    return 0;
}