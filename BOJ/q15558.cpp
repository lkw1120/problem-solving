#include<bits/stdc++.h>
using namespace std;
string str[2];
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    cin>>str[0];
    cin>>str[1];
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    str[0][0] = '0';
    ans = 0;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if(N-1 <= y) {
            ans = 1;
            break;
        }
        if(y+1 < N && str[x][y+1] == '1') {
            str[x][y+1] = '0';
            q.push({{x,y+1},t+1});
        }
        if(0 <= y-1 && t < y-1 && str[x][y-1] == '1') {
            str[x][y-1] = '0';
            q.push({{x,y-1},t+1});
        }
        if((y+K < N && str[(x+1)%2][y+K] == '1') || N <= y+K) {
            if(y+K < N) str[(x+1)%2][y+K] = '0';
            q.push({{(x+1)%2,y+K},t+1});
        }
    }
    cout<<ans<<"\n";
    return 0;
}