#include <bits/stdc++.h>
using namespace std;
int arr[201];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int k = max(0,N-M);
    if(k == 0) {
        ans = arr[N-1];
    }
    else {
        int low,high;
        low = arr[N-1];
        high = arr[N-1]+arr[N-2];
        ans = high;
        while(low <= high) {
            int mid = low+(high-low)/2;
            int cnt,l,r;
            cnt = 0;
            l = 0,r = N-1;
            while(l < r) {
                if(arr[l]+arr[r] <= mid) {
                    cnt++;
                    l++;
                    r--;
                }
                else {
                    r--;
                }
            }
            if(k <= cnt) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

    }
    cout<<ans<<"\n";
    return 0;
}