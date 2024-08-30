#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N,H,T,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>H>>T;
    for(int i=0;i<N;i++) {
        cin>>A;
        pq.push(A);
    }
    int cnt = 0;
    while(T--) {
        A = pq.top();
        if(1 < A && H <= A) {
            cnt++;
            pq.pop();
            pq.push(A/2);
        }
        else {
            break;
        }
    }
    if(pq.top() < H) {
        cout<<"YES"<<"\n";
        cout<<cnt<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
        cout<<pq.top()<<"\n";
    }
    return 0;
}