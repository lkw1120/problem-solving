#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>M;
        pq.push(-M);
    }
    ans = 0;
    while(pq.size() > 1) {
        M = pq.top();
        pq.pop();
        M+=pq.top();
        pq.pop();
        pq.push(M);
        ans-=M;
    }
    cout<<ans<<"\n";
    return 0;
}