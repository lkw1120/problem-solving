#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int parent[MAX];
bool visited[MAX];
int T,N,A,B,ans;
void preload() {
    for(int i=0;i<MAX;i++) {
        parent[i] = 0;
        visited[i] = false;
    }
}
void solve(int a, int b) {
    while(true) {
        visited[a] = true;
        if(!parent[a]) break;
        a = parent[a];
    }
    while(!visited[b]) {
        b = parent[b];
    }
    ans = b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        preload();
        cin>>N;
        for(int i=0;i<N-1;i++) {
            cin>>A>>B;
            parent[B] = A;
        }
        cin>>A>>B;
        solve(A,B);
        cout<<ans<<"\n";
    }
    return 0;
}