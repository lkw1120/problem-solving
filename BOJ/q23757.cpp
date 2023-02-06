#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int>> pq;
vector<int> v;
int N,M,C,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>C;
        pq.push(C);
    }
    ans = 1;
    for(int i=0;i<M;i++) {
        cin>>W;
        if(pq.top() < W) {
            ans = 0;
            break;
        }
        else {
            C = pq.top();
            pq.pop();
            pq.push(C-W);
        }
    }
    cout<<ans<<"\n";
    return 0;
}