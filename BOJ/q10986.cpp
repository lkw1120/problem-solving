#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1001;
ll arr[MAX];
ll N,M,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    ll sum = 0;
    for(int i=0;i<N;i++) {
        cin>>A;
        sum+=A;
        arr[sum%M]++;
    }
    for(int i=0;i<MAX;i++) {
        ans+=(arr[i]*(arr[i]-1)/2);
    }
    ans+=arr[0];
    cout<<ans<<"\n";
    return 0;
}