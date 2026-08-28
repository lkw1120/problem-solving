#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200];
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        int r = A%200;
        ans+=arr[r];
        arr[r]++;
    }
    cout<<ans<<"\n";
    return 0;
}