#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
ll modpow(ll a, ll n, ll p) {
    if(n == 0) return 1;
    ll half = modpow(a,n/2,p);
    half = (half*half)% p;
    if(n%2 == 1) half = (half*a)%p;
    return half;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int cnt = 0;
    for(int k=1;;k+=2) {
        ll sum = 0;
        if(k == 1) {
            cnt++;
            if(cnt == N) {
                ans = 1;
                break;
            }
        }
        else {
            for(int i=1;i<=6;i++) {
                sum+=modpow(i,k,k);
                sum%=k;
            }
            if(sum%k == 0) {
                cnt++;
                if(cnt == N) {
                    ans = k;
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}