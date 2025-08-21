#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100003;
int arr[MAX_N];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int high = 0;
    for(int i=0;i<N;i++) {
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
        high = max(high,b);
    }
    ans = 0;
    int cnt = 0;
    for(int i=1;i<=high;i++) {
        cnt+=arr[i];
        if(i-1 <= cnt) {
            ans = max(ans,i-1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}