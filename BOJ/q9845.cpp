#include<bits/stdc++.h>
using namespace std;
int N,ans;
void find(int n, int low) {
    if(n == 0) {
        ans++;
        return ;
    }
    for(int i=low;i<=N;i++) {
        if(0 <= n-i) {
            find(n-i,i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    find(N,5);
    cout<<ans<<"\n";
    return 0;
}