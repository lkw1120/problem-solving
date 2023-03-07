#include<bits/stdc++.h>
using namespace std;
bool arr[100001] = {false};
bool visited[100001] = {false};
int N,S,D,F,B,K,L,ans;
void solve() {
    queue<pair<int,int>> q;
    q.push({S,0});
    arr[S] = 0;
    visited[S] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now == D) {
            ans = cnt;
            break;
        }
        if(now+F <= N && !arr[now+F] && !visited[now+F]) {
            visited[now+F] = true;
            q.push({now+F,cnt+1});
        }
        if(0 < now-B && !arr[now-B] && !visited[now-B]) {
            visited[now-B] = true;
            q.push({now-B,cnt+1});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>S>>D>>F>>B>>K;
    for(int i=0;i<K;i++) {
        cin>>L;
        arr[L] = true;
    }
    ans = INT_MAX;
    solve();
    if(ans == INT_MAX) {
        cout<<"BUG FOUND"<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
    return 0;
}