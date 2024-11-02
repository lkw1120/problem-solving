#include<bits/stdc++.h>
using namespace std;
vector<string> v;
map<char,int> mp = {
    {'S',1},{'M',5},{'L',10}
};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    v.resize(R);
    for(int i=0;i<R;i++) {
        cin>>v[i];
    }
    cin>>A>>B;
    queue<pair<int,int>> q;
    q.push({A,B});
    ans = mp[v[A][B]];
    v[A][B] = '*';
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < R && 0 <= dy && dy < C && v[dx][dy] != '*') {
                ans+=mp[v[dx][dy]];
                v[dx][dy] = '*';
                q.push({dx,dy});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}