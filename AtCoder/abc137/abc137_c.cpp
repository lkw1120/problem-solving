#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
        sort(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    ll cnt = 0;
    ans = 0;
    for(int i=1;i<N;i++) {
        if(v[i] == v[i-1]) {
            cnt++;	
        }
        else {
            ans+=(cnt*(cnt+1)/2);
            cnt = 0;
        }
    }
    ans+=(cnt*(cnt+1)/2);
    cout<<ans<<"\n";
    return 0;
}