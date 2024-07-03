#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int,vector<int>,greater<int>> pq;
vector<int> v;
ll N,K,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>T;
        v.push_back(T);
    }
    for(int i=0;i<K;i++) {
        pq.push(v[i]);
    }
    ll sum = 0;
    ans = 0;
    for(int i=K;i<N;i++) {
        sum+=pq.top();
        ans+=sum;
        pq.pop();
        pq.push(v[i]);
    }
    while(!pq.empty()) {
        sum+=pq.top();
        ans+=sum;
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}