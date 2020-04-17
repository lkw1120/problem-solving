#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool visit[MAX] = {false};
int cnt,ans;
void find(int n, int k) {
    int t = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            n = q.front();
            q.pop();
            visit[n] = true;
            if(n == k) {
                if(ans > t || ans == 0) {
                    ans = t;
                    cnt = 1;
                }
                else if(ans == t) {
                    cnt++;
                }
            }
            if(n > 0 && !visit[n-1]) {
                q.push(n-1);
            }
            if(n < MAX-1 && !visit[n+1]) {
                q.push(n+1);
            }
            if(n*2 < MAX && !visit[n*2]) {
                q.push(n*2);
            }
        }
        t++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int N,K;
    cin>>N>>K;
    ans = 0;
    find(N,K);
    cout<<ans<<"\n";
    cout<<cnt<<"\n";
    return 0;
}