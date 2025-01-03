#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+1;
int arr[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int sum,tmp;
    sum = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    tmp = sum/N;
    int low,high;
    low = high = 0;
    for(int i=1;i<=N;i++) {
        if(arr[i] < tmp) {
            low+=tmp-arr[i];
        }
        if(tmp+1 < arr[i]) {
            high+=arr[i]-(tmp+1);
        }
    }
    ans = max(low,high);
    cout<<ans<<"\n";
    return 0;
}