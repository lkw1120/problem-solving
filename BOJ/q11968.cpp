#include<bits/stdc++.h>
using namespace std;
bool card[100001];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>M;
        card[M] = true;
    }
    int n,m;
    n = m = 1;
    N*=2;
    ans = 0;
    while(true) {
        while(n <= N && !card[n]) n++;
        while(m < n || m <= N && card[m]) m++;
        if(N < n || N < m) break;
        ans++;
        n++,m++;
    }
    cout<<ans<<"\n";
    return 0;
}