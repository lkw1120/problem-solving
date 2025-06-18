#include<bits/stdc++.h>
using namespace std;
const int IDENTITY = 0;
const int MAX_N = 300001;
int arr[MAX_N];
int comp[MAX_N];
int dp[MAX_N][2];
int bit[MAX_N];
int N,Q,A,ans;
int combine(int a, int b) {
    return max(a, b);
}
int bit_query(int i) {
    int r = IDENTITY;
    while(0 < i) {
        r = combine(r,bit[i]);
        i-=(i&-i);
    }
    return r;
}
void bit_update(int i, int a, int size) {
    while(i <= size) {
        bit[i] = combine(bit[i],a);
        i+=(i&-i);
    }
}
int compress() {
    vector<int> xs(arr+1,arr+N+1);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    for(int i=1;i<=N;i++) {
        comp[i] = int(lower_bound(xs.begin(),xs.end(),arr[i])-xs.begin())+1;
    };
    return xs.size();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    int size = compress();
    fill(bit,bit+size+1,IDENTITY);
    for(int i=1;i<=N;i++) {
        int x = comp[i];
        dp[i][0] = bit_query(x-1)+1;
        bit_update(x,dp[i][0],size);
    }
    fill(bit,bit+size+1,IDENTITY);
    for(int i=N;i>=1;i--) {
        int x = comp[i];
        int rx = size-x+1;
        dp[i][1] = bit_query(rx-1)+1;
        bit_update(rx,dp[i][1],size);
    }
    while(Q--) {
        cin>>A;
        ans = dp[A][0]+dp[A][1]-1;
        cout<<ans<<"\n";
    }
    return 0;
}