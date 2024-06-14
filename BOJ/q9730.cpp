#include<bits/stdc++.h>
using namespace std;
int arr[5001];
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        int mx = arr[1];
        ans = 0;
        for(int i=2;i<=N;i++) {
            if(mx < arr[i]) {
                ans+=arr[i];
                mx = arr[i];
            }
            else {
                ans+=max(arr[i],arr[i-1]);
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}