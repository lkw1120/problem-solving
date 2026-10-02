#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int arr[MAX] = {0};
int cache[MAX] = {0};
int N,ans;
void solve(int n) {
    if(0 < cache[arr[n]]) {
        return ;
    }
    else {
        cache[arr[n]] = cache[n]+1;
        solve(arr[n]);
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];	
    }
    fill(cache,cache+MAX,-1);
    cache[1] = 0;
    solve(1);
    ans = cache[2];
    cout<<ans<<"\n";
    return 0; 
}