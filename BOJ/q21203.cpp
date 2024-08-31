#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> s,a;
ll N,S,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>S>>A;
        s.push_back(S);
        a.push_back(A);
    }
    sort(s.begin(),s.end());
    sort(a.begin(),a.end());
    ans = 0;
    ll tmp = 0;
    for(int i=1;i<N;i++) {
        tmp+=i*(s[i]-s[i-1]);
        ans+=tmp;
    }
    tmp = 0;
    for(int i=1;i<N;i++) {
        tmp+=i*(a[i]-a[i-1]);
        ans+=tmp;
    }
    cout<<ans<<"\n";
    return 0;
}