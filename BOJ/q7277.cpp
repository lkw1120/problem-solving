#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_T = 100001;
ll arr[MAX_T];
ll prefix[MAX_T];
ll T,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>M;
    for(int i=0;i<T-1;i++) {
        cin>>arr[i];
    }
    ll mn = 0;
    for(int i=2;i<=T;i++) {
        prefix[i] = prefix[i-1]-arr[i-2]+M;
        mn = min(mn,prefix[i]);
    }
    ll tmp = max(0LL,-mn);
    vector<ll> v(T);
    for(int i=1;i<=T;i++) {
        v[i-1] = tmp+prefix[i];
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}