#include<bits/stdc++.h>
using namespace std;
int arr[100001][2];
int N,M,A,B,C,cnt,ans;
int find(int now) {
    if(arr[now][1] == -1) {
        return now;
    }
    else {
        return find(arr[now][1]);
    }
}
void dfs(int now) {
    if(arr[now][0] != -1) {
        cnt++;
        dfs(arr[now][0]);
        cnt++;
    }
    if(arr[now][1] != -1) {
        cnt++;
        dfs(arr[now][1]);
        cnt++;
    }
    if(now == M) {
        ans = cnt;
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A>>B>>C;
        arr[A][0] = B;
        arr[A][1] = C;
    }
    M = find(1);
    ans = cnt = 0;
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}