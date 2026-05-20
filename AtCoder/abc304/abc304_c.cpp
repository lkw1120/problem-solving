#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> x,y;
vector<bool> infected;
ll N,X,Y,D;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>D;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        x.push_back(X);
        y.push_back(Y);
    }
    infected.resize(N);
    queue<int> q;
    infected[0] = true;
    q.push(0);
    ll dist = D*D;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0;i<N;i++) {
            if(infected[i]) continue;
            ll dx = x[cur]-x[i];
            ll dy = y[cur]-y[i];
            if(dx*dx+dy*dy <= dist) {
                infected[i] = true;
                q.push(i);
            }
        }
    }
    for(int i=0;i<N;i++) {
        cout<<(infected[i]? "Yes": "No")<<"\n";
    }
    return 0;
}