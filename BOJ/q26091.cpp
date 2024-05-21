#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int N,M,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    sort(arr+1,arr+N+1);
    int l,r;
    l=1,r=N;
    ans = 0;
    while(l < r) {
        if(arr[l]+arr[r] < M) {
            l++;
        }
        else {
            ans++;
            l++;
            r--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}