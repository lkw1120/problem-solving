#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e5+1;
map<int,bool> mp;
int arr[MAX];
int N,M,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A;
        mp[A] = true;
    }
    arr[0] = 1;
    arr[1] = mp[1]? 0: 1;
    for(int i=2;i<=N;i++) {
        if(mp[i]) continue;
        arr[i]=(arr[i]+arr[i-1])%MOD;
        arr[i]=(arr[i]+arr[i-2])%MOD;
    }
    ans = arr[N];
    cout<<ans<<"\n";
    return 0;
}