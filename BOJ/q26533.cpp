#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string ans;
int N;
void solve(int x, int y) {
    if(x+1 == N && y+1 == N) {
        ans = "Yes";
        return ;
    }
    if(x+1 < N && v[x+1][y] == '.') {
        v[x+1][y] = 'x';
        solve(x+1,y);
    }
    if(y+1 < N && v[x][y+1] == '.') {
        v[x][y+1] = 'x';
        solve(x,y+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ans = "No";
    v[0][0] = 'x';
    solve(0,0);
    cout<<ans<<"\n";
    return 0;
}