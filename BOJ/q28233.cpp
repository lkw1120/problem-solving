#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
bool check[MAX];
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>Y;
    queue<pair<int,int>> q;
    q.push({X,0});
    check[X] = true;
    while(!q.empty()) {
        int n = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(n == Y) {
            ans = cnt;
            break;
        }
        if(n <= N && !check[n*2-1]) {
            check[n*2-1] = true;
            q.push({n*2-1,cnt+1});
        }
        if(N < n && !check[(n-N)*2]) {
            check[(n-N)*2] = true;
            q.push({(n-N)*2,cnt+1});
        }
        if(n%2 == 1 && n+1 <= 2*N && !check[n+1]) {
            check[n+1] = true;
            q.push({n+1,cnt+1});
        }
        if(n%2 == 0 && 0 < n-1 && !check[n-1]) {
            check[n-1] = true;
            q.push({n-1,cnt+1});
        }
    }
    cout<<ans<<"\n";
    return 0;
}