#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll sum,tmp,p;
    sum = tmp = p = 0;
    for(int i=0;i<N;i++) {
        cin>>A;
        sum+=A;
        tmp = max(tmp,sum);
        ans = max(ans,tmp+p);
        p+=sum;
    }
    cout<<ans<<"\n";
    return 0;
}