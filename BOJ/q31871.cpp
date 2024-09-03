#include<bits/stdc++.h>
using namespace std;
int arr[10][10];
bool visited[10];
int N,M,U,V,D,ans;
void find(int now, int cost, int cnt) {
    if(now == 0 && cnt == N+1) {
        ans = max(cost,ans);
        return ;
    }
    else {
        for(int j=0;j<=N;j++) {
            if(arr[now][j] && !visited[j]) {
                visited[j] = true;
                find(j,cost+arr[now][j],cnt+1);
                visited[j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>U>>V>>D;
        arr[U][V] = max(arr[U][V],D);
    }
    ans = -1;
    find(0,0,0);
    cout<<ans<<"\n";
    return 0;
}