#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[26][230];
bool visited[26][230];
string str;
ll n,ans;
ll solve(int p, int prev) {
    if(p == n) return 1;
    ll &ret = dp[p][prev];
    if(visited[p][prev]) return ret;
    visited[p][prev] = true;
    ret = 0;
    int cur = 0;
    for(int i=p;i<n;i++) {
        cur+=str[i]-'0';
        if(prev <= cur) {
            ret+=solve(i+1,cur);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while(cin>>str) {
        if(str == "bye") break;
        fill(&visited[0][0],&visited[0][0]+26*230,0);
        n = str.size();
        ans = solve(0,0);
        cout<<tc<<". "<<ans<<"\n";
        tc++;
    }
    return 0;
}