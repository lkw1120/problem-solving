#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=1;i*i<=N;i++) {
        if(N%i==0) {
            v.push_back(i);
            if(i!=N/i) {
                v.push_back(N/i);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}