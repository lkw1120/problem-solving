#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
vector<int> v;
int table[MAX] = {0};
bool visit[MAX] = {false};
int N,ans;
void dfs(int start, int now) {
    if(visit[now]) {    
        if(now == start) {
            v.push_back(start);
        }
    }
    else {
        visit[now] = true;
        dfs(start,table[now]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>table[i];
    }
    for(int i=1;i<=N;i++) {
        fill(visit,visit+MAX,false);
        dfs(i,i);
    }
    ans = v.size();
    cout<<ans<<"\n";
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}