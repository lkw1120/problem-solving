#include<bits/stdc++.h>
using namespace std;
vector<int> v[26];
bool visited[26][26];
int N,M,A,B,ans;
void find(int now, int dist) {
    ans = max(dist,ans);
    for(auto next: v[now]) {
        if(!visited[now][next]) {
            visited[now][next] = visited[next][now] = true;
            find(next,dist+1);
            visited[now][next] = visited[next][now] = false;
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N>>M;
        if(!N && !M) break;
        for(int i=0;i<26;i++) {
            v[i].clear();
        }
        for(int i=0;i<M;i++) {
            cin>>A>>B;
            v[A].push_back(B);
            v[B].push_back(A);
        }
        ans = 0;
        for(int i=1;i<=N;i++) {
            find(i,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}