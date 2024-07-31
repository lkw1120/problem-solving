#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
vector<int> v[MAX];
int color[MAX][2];
bool check[MAX];
int N,P,C;
ll ans;
ll find(int n) {
    fill(check,check+MAX,false);
    queue<pair<int,int>> q;
    q.push({0,n});
    check[0] = true;
    ll sum = 0;
    while(!q.empty()) {
        int now = q.front().first;
        int t = q.front().second;
        q.pop();
        sum+=color[now][t];
        for(auto next: v[now]) {
            if(!check[next]) {
                check[next] = true;
                q.push({next,1-t});
            }
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++) {
        cin>>P>>C;
        v[P].push_back(C);
    }
    for(int i=0;i<N;i++) {
        cin>>color[i][0]>>color[i][1];
    }
    ans = min(find(0),find(1));
    cout<<ans<<"\n";
    return 0;
}