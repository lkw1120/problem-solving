#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<N;i++) {
        cin>>A>>B;
        arr[A]++;
        arr[B]++;
    }
    for(int i=1;i<=N;i++) {
        ans = max(ans,arr[i]);
    }
    ans++;
    cout<<ans<<"\n";
    return 0;
}