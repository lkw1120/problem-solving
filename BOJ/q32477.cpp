#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
vector<int> v[MAX];
bool check[MAX];
int N,M,A,B,ans;
int find(int n) {
    queue<int> q;
    q.push(n);
    check[n] = true;
    int cnt = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for(auto next: v[now]) {
            if(!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    ans = 1;
    for(int i=1;i<=N;i++) {
        if(!check[i]) {
            ans = max(find(i),ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}