#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100009];
ll N,M,ans;
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int l,r;
    l = 0,r = 1;
    ans = 0;
    for(;r<=N;r++) {
        while(M < arr[r]-arr[l]) {
            l++;
        }
        ans = max(ans,(r-l)*1LL);
    }
    cout<<ans<<"\n";
    return 0;
}