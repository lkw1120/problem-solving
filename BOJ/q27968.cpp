#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 3e5+9;
ll arr[MAX];
ll N,M,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    while(N--) {
        cin>>B;
        ans = lower_bound(arr+1,arr+M+1,B)-arr;
        if(M < ans) {
            cout<<"Go away!"<<"\n";
        }
        else {
            cout<<ans<<"\n";
        }
    }
    return 0;
}