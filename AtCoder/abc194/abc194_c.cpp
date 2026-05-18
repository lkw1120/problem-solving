#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[401];
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        cnt[A+200]++;
    }
    ans = 0;
    for(int i=0;i<=400;i++) {
        for(int j=i+1;j<=400;j++) {
            int tmp = j-i;
            ans+=(tmp*tmp*cnt[i]*cnt[j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}