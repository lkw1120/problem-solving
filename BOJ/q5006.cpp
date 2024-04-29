#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
vector<int> v[1001];
queue<int> q;
int arr[1001];
int N,H,L,X,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(arr,arr+1001,INF);
    cin>>N>>H>>L;
    for(int i=0;i<H;i++) {
        cin>>X;
        q.push(X);
        arr[X] = 0;
    }
    for(int i=0;i<L;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto next: v[now]) {
            if(arr[now] < arr[next]) {
                arr[next] = arr[now]+1;
                q.push(next);
            }
        }
    }
    int hi = 0;
    for(int i=0;i<N;i++) {
        if(hi < arr[i]) {
            hi = arr[i];
            ans = i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}