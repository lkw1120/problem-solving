#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int T,N,ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(arr,arr+1001,0);
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        int idx = 1;
        ans = 0;
        for(int i=1;i<=N;i++) {
            for(int j=i;j<=N;j++) {
                if(arr[j] == i) {
                    idx = j;
                }
            }
            while(arr[i] != i) {
                swap(arr[idx],arr[idx-1]);
                idx--;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}