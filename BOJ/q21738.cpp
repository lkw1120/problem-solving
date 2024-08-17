#include<bits/stdc++.h>
using namespace std;
const int MAX = 328001;
vector<int> v[MAX];
vector<int> vv;
bool visited[MAX];
int N,S,P,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>S>>P;
    for(int i=1;i<N;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    queue<pair<int,int>> q;
    q.push({P,0});
    visited[P] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        if(now <= S) {
            vv.push_back(d);
        }
        for(auto next: v[now]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push({next,d+1});
            }
        }
    }
    sort(vv.begin(),vv.end(),less<int>());
    ans = N-(vv[0]+vv[1]+1);
    cout<<ans<<"\n";
    return 0;
}