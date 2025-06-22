#include<bits/stdc++.h>
using namespace std;
const int MAX_P = 30;
const int MOD = (1<<MAX_P)-1;
vector<pair<int,int>> v;
vector<int> fib;
int Z,S,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>Z;
    int mx = 0;
    for(int i=0;i<Z;i++) {
        cin>>S>>P;
        v.push_back({S,P});
        mx = max(mx,S);
    }
    fib.resize(mx+2);
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2;i<=mx+1;i++) {
        fib[i] = (fib[i-1]+fib[i-2])&MOD;
    }
    for(auto [s,p]: v) {
        int mask = (1<<p)-1;
        ans = fib[s+1]&mask;
        cout<<ans<<"\n";
    }
    return 0;
}