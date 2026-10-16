#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        if(mp[A]) {
            mp[A] = false;
        }
        else {
            mp[A] = true;
        }
    }
    ans = 0;
    for(auto [a,b]: mp) {
        if(b) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}