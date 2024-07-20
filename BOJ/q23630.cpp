#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
int arr[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ll tmp,cnt;
    for(int i=0;i<30;i++) {
        tmp = 1<<i;
        cnt = 0;
        for(int j=1;j<=N;j++) {
            if(tmp&arr[j]) {
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}