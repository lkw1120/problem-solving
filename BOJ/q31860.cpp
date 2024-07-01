#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
vector<int> v;
int N,M,K,D;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++) {
        cin>>D;
        pq.push(D);
    }
    int prev = 0;
    while(!pq.empty()) {
        D = pq.top();
        pq.pop();
        v.push_back((prev/2)+D);
        prev = v.back();
        if(K < D-M) {
            pq.push(D-M);
        }
    }
    cout<<v.size()<<"\n";
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}