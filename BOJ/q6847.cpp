#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
bool check[10001];
int N,X,Y,ans;
int find(int x, int y) {
    fill(check,check+10001,false);
    queue<pair<int,int>> q;
    q.push({x,0});
    check[x] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        if(now == y) {
            return d-1;
        }
        for(auto next: v[now]) {
            if(!check[next]) {
                check[next] = true;
                q.push({next,d+1});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v[X].push_back(Y);
    }
    while(1) {
        cin>>X>>Y;
        if(!X && !Y) break;
        ans = find(X,Y);
        if(0 <= ans) {
            cout<<"Yes"<<" "<<ans<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}