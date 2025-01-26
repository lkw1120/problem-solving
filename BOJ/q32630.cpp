#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=0;i<N;i++) {
        cin>>A;
        v.push_back(A);
        sum+=A;
    }
    sort(v.begin(),v.end());
    ll low,high;
    low = v[0]*v[1];
    high = v[N-1]*v[N-2];
    ans = max(sum,max(sum-v[0]-v[1]+low*2,sum-v[N-1]-v[N-2]+high*2));
    cout<<ans<<"\n";
    return 0;
}