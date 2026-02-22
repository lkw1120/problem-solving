#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
vector<ll> v;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int n = str.size();
    v.resize(n);
    int p = 0;
    v[p]++;
    for(auto ch: str) {
        if(ch == '(') {
            p++;
        }
        else {
            p--;
        }
        v[p]++;
    }
    for(auto a: v) {
        ans+=a*(a-1)/2;
    }
    ans--;
    cout<<ans<<"\n";
    return 0;
}