#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
vector<pair<int,int>> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<N;i++) {
        pq.push(i);
    }
    while(1 < pq.size()) {
        int a,b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        v.push_back({a,b});
        pq.push(a-b);
    }
    if(pq.top() == 1) {
        v.push_back({N,1});
        ans = N-1;
    }
    else {
        v.push_back({N,0});
        ans = N;
    }
    cout<<ans<<"\n";
    for(auto [a,b]: v) {
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}