#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        ans^=arr[i];
        arr[0]+=arr[i];
    }
    if(ans) {
        cout<<0<<"\n";
    }
    else {
        sort(arr+1,arr+N+1);
        ans = arr[0]-arr[1];
        cout<<ans<<"\n";
    }
    return 0;
}