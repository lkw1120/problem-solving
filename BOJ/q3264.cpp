#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<pair<int,int>> v[MAX];
bool visited[MAX];
int N,S,A,B,C,ans;
void find(int now, int sum) {
    ans = max(sum,ans);
    for(auto item: v[now]) {
        int next = item.first;
        int cost = item.second;
        if(!visited[next]) {
            visited[next] = true;
            find(next,sum+cost);
            visited[next] = false;
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>S;
    int sum = 0;
    for(int i=1;i<N;i++) {
        cin>>A>>B>>C;
        v[A].push_back({B,C});
        v[B].push_back({A,C});
        sum+=C;
    }
    visited[S] = true;
    find(S,0);
    ans = sum*2-ans;
    cout<<ans<<"\n";
    return 0;
}