#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int tmp = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        tmp = max(arr[i],tmp);
    }
    ans = 0;
    if(1 < N) {
        int sum = 0;
        for(int i=1;i<=N;i++) {
            if(arr[i] < tmp) {
                sum+=(tmp-arr[i]);
            }
            else {
                ans+=sum;
                tmp = sum = 0;
                for(int j=i+1;j<=N;j++) {
                    tmp = max(arr[j],tmp);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}