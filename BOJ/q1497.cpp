#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
string s1,s2;
ll N,M,sum,ans;
void check(ll n, ll t, ll cnt) {
    if(n == N) {
        ll a,b,c,d;
        a = sum;
        b = t;
        c = d = 0;
        while(a) {
            c+=(a%2);
            a/=2;
        }
        while(b) {
            d+=(b%2);
            b/=2;
        }
        if(c <= d) {
            sum = t;
            ans = min(cnt,ans);
        }
        return ;
    }
    check(n+1,t|v[n],cnt+1);
    check(n+1,t,cnt);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    bool flag = false;
    for(int i=0;i<N;i++) {
        cin>>s1>>s2;
        ll tmp = 0;
        for(int j=0;j<M;j++) {
            tmp<<=1;
            if(s2[j] == 'Y') tmp++;
        }
        v.push_back(tmp);
        if(tmp) flag = true;
    }
    if(flag) {
        ans = INT_MAX;
        sum = 0;
        check(0,0,0);
    }
    else {
        ans = -1;
    }
    cout<<ans<<"\n";
    return 0;
}