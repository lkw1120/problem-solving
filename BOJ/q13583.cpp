#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>C>>D;
    ans = -1;
    if(C%A == 0) {
        for(ll i=1; i*i<=C;i++){
            if(C%i == 0){
                v.push_back(i);
                if(i != C/i) {
                    v.push_back(C/i);
                }
            }
        }
        sort(v.begin(), v.end());
        for(auto N: v){
            if(N%A != 0) continue;
            if(N%B == 0) continue;
            if(D%N == 0) continue;
            ans = N;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}