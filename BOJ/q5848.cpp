#include<bits/stdc++.h>
using namespace std;
int cow[1001];
bool visited[1001];
int N,ans;
int find(int n) {
    if(visited[n]) {
        return cow[n];
    }
    if(cow[n] == 0) {
        return 0;
    }
    visited[n] = true;
    return cow[n] = find(cow[n]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>cow[i];
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(find(i) == 0) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}