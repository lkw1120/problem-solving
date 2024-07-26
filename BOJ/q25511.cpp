#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int parent[100001];
int N,K,P,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N-1;i++) {
        cin>>P>>C;
        parent[C] = P;
    }
    int k = 0;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        if(arr[i] == K) {
            k = i;
        }
    }
    queue<pair<int,int>> q;
    q.push({k,0});
    while(!q.empty()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(now == 0) {
            ans = depth;
            break;
        }
        q.push({parent[now],depth+1});
    }
    cout<<ans<<"\n";
    return 0;
}