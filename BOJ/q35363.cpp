#include<bits/stdc++.h>
using namespace std;
int arr[10];
int n,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr[x]++;
    }
    if(arr[1] > 0 || arr[3] > 0 || arr[7] > 0 ||
       (arr[5] > 0 && (arr[2] > 0 || arr[4] > 0 || arr[6] > 0 || arr[8] > 0))) {
        ans = 1;
    }
    else {
        ans = n;
    }
    cout<<ans<<"\n";
    return 0;
}