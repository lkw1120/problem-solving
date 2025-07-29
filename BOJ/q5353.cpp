#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N;
        if(N == 0) break;
        vector<pair<int,int>> v;
        for(int i=0;i<N;i++) {
            int a,b;
            cin>>a>>b;
            v.push_back({b,a});
        }
        sort(v.begin(),v.end());
        ans = 0;
        int end = INT_MIN;
        for(auto [b,a]: v) {
            if(end <= a) {
                ans++;
                end = b;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}