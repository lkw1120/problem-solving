#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> pq;
vector<int> v;
int N,K,P;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>P;
        pq.push({P,N-i-1});
    }
    while(K--) {
        P = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(0 < P-100) {
            pq.push({P-100,idx});
        }
        else {
            cout<<"impossible"<<"\n";
            return 0;
        }
    }
    v.resize(N);
    while(!pq.empty()) {
        P = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        v[N-idx-1] = P;
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    return 0;
}