#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> mp;
ll N,D,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>D;
    for(int i=0;i<N;i++) {
        cin>>A;
        mp[A/D]++;
    }
    ans = 0;
    for(auto item: mp) {
        ll cnt = item.second;
        if(item.second) {
            ans+=cnt*(cnt-1)/2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}