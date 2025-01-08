#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int N,ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    sort(arr+1,arr+N+1);
    vector<int> v;
    for(int i=2;i<=N;i++) {
        v.push_back(arr[i]-arr[i-1]);
    }
    ans = v[0];
    for(int i=1;i<N;i++) {
        ans = gcd(ans,v[i]);
    }
    cout<<ans<<"\n";
    return 0;
}