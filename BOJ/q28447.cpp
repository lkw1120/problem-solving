#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int selected[11];
int N,K,ans;
void find(int n, int cnt) {
    if(n == N+1) {
        if(cnt == K) {
            int sum = 0;
            for(int i=0;i<cnt;i++) {
                for(int j=i+1;j<cnt;j++) {
                    sum+=arr[selected[i]][selected[j]]; 
                }
            }
            ans = max(sum,ans);
        }
    }
    else {
        selected[cnt] = n;
        find(n+1,cnt+1);
        find(n+1,cnt);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    ans = INT_MIN;
    find(1,0);
    cout<<ans<<"\n";
    return 0;
}