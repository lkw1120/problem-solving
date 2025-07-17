#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 300001;
vector<ll> v,vv;
ll arr[MAX_N];
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<N;i++) {
        cin>>arr[i];
    }
    v.resize(N+1);
    v[1] = 0;
    ll mx,mn;
    mx = mn = 0;
    for (int i = 2; i <= N; i++) {
        v[i] = v[i-1] + arr[i-1];
        mn = min(v[i],mn);
        mx = max(v[i],mx);
    }
    ll L,R;
    L = 1-mn;
    R = N-mx;
    bool flag = true;
    if(L != R) {
        flag = false;
    }
    else {
        ll tmp = L;
        vv.resize(N+1);
        for(int i=1;i<=N;i++) {
            vv[i] = tmp+v[i];
            if(vv[i] < 1 || N < vv[i]) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        for (int i=1;i<=N;i++) {
            cout<<vv[i]<<" ";
        }
        cout<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }
    return 0;
}