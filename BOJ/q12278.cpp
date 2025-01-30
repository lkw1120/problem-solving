#include<bits/stdc++.h>
using namespace std;
int T,N,M,P,Q;
pair<int,int> findNumber(int n) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    int cnt = 1;
    while(cnt < n) {
        auto [a,b] = q.front();
        q.pop();
        q.push({a,a+b});
        q.push({a+b,b});
        cnt++;
    }
    return q.front();
}
int findIndex(int a, int b) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    int index = 1;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (x == a && y == b) {
            return index;
        }
        q.push({x,x+y});
        q.push({x+y,y});
        index++;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N;
        if(N == 1) {
            cin>>M;
            auto [a,b] = findNumber(M);
            cout<<"Case #"<<t<<": "<<a<<" "<<b<<"\n";
        }
        if(N == 2) {
            cin>>P>>Q;
            int res = findIndex(P,Q);
            cout<<"Case #"<<t<<": "<<res<<"\n";
        }
        
    }
    return 0;
}