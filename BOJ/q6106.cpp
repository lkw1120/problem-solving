#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int p = 0;
    for(int i=1;i<=N;i++) {
        if(arr[i-1] < 0 && 0 <= arr[i]) {
            ans+=(i-p)*2;
        }
        if(0 <= arr[i-1] && arr[i] < 0) {
            p = i;
        }
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}