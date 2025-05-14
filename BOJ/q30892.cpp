#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,less<ll>> lower;
priority_queue<ll,vector<ll>,greater<ll>> upper;
ll K,N,T,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>T;
    for(int i=0;i<N;i++) {
        cin>>A;
        if(T <= A) {
            upper.push(A);
        }
        else {
            lower.push(A);
        }
    }
    int cnt = 0;
    while(cnt < K) {
        bool flag = true;
        while(!upper.empty() && upper.top() < T) {
            lower.push(upper.top());
            upper.pop();
        }
        if(!lower.empty()) {
            T+=lower.top();
            lower.pop();
            cnt++;
            flag = false;
        }
        if(flag) break;
    }
    cout<<T<<"\n";
    return 0;
}