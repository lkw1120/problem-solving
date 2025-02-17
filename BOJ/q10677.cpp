#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,pair<ll,ll>>> v;
ll K,X,Y,A,B;
ll basis(ll a, ll b) {
    ll c,res;
    res = 0;
    c = 1;
    while(a) {
        res+=(a%10)*c;
        a/=10;
        c*=b;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    while(K--) {
        v.clear();
        cin>>X>>Y;
        for(int i=10;i<=15000;i++) {
            v.push_back({basis(X,i),{i,-1}});
            v.push_back({basis(Y,i),{i,1}});
        }
        sort(v.begin(),v.end());
        int size = v.size();
        for(int i=1;i<size;i++) {
            auto a = v[i-1];
            auto b = v[i];
            if(a.first == b.first) {
                if(a.second.second == -1) {
                    A = a.second.first;
                }
                else {
                    A = b.second.first;
                }
                if(b.second.second == 1) {
                    B = b.second.first;
                }
                else {
                    B = a.second.first;
                }
                break;
            }
        }
        cout<<A<<" "<<B<<"\n";
    }
    return 0;
}