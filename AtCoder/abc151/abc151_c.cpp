#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    vector<bool> ac(N+1,false);
    vector<int> wa(N+1,0);
    int penalty = 0;
    ans = 0;
    for(int i=0;i<M;i++) {
        int p;
        string S;
        cin>>p>>S;
        if(ac[p]) continue;
        if(S == "WA") {
            wa[p]++;
        }
        else {
            ac[p] = true;
            ans++;
            penalty+=wa[p];
        }
    }
    cout<<ans<<" "<<penalty<<"\n";
    return 0;
}