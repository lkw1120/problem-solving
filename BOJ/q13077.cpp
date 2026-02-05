#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        string str;
        cin>>str;
        auto pos = str.find('/');
        ll p = stoll(str.substr(0, pos));
        ll q = stoll(str.substr(pos+1));
        vector<pair<char,ll>> v;
        while(p != 1 || q != 1) {
            if(p < q) {
                ll k = (q-1)/p;
                v.push_back({'L',k});
                q-=k*p;
            } 
            else {
                ll k = (p-1)/q;
                v.push_back({'R',k});
                p-=k*q;
            }
        }
        ans = 1;
        for(int i=v.size()-1;i>=0;i--) {
            char ch = v[i].first;
            ll k = v[i].second;
            if(ch == 'L') {
                ans<<=k;
            }
            else {
               ll tmp = (1LL<<k)-1;
               ans = (ans<<k)+tmp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}