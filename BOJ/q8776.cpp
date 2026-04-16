#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Z,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>Z;
    while(Z--) {
        cin>>N;
        ll x;
        cin>>x;
        ll total = x;
        ll maxEnd,maxAns;
        ll minEnd,minAns;
        maxEnd = maxAns = x;
        minEnd = minAns = x;
        for(int i=1;i<N;i++) {
            cin>>x;
            total+=x;
            maxEnd = max(x,maxEnd+x);
            maxAns = max(maxAns,maxEnd);
            minEnd = min(x,minEnd+x);
            minAns = min(minAns,minEnd);
        }
        ans = maxAns < 0? maxAns: max(maxAns,total-minAns);
        cout<<ans<<"\n";
    }
    return 0;
}