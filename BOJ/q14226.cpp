#include<bits/stdc++.h>
using namespace std;
const int MAX = 2001;
bool visited[MAX][MAX] = {false};
int S,ans;
int solve(int t, int clip, int imoji) {
    queue<tuple<int,int,int>> q;
    visited[imoji][clip] = true;
    q.push({imoji,clip,t});
    while(!q.empty()) {
        imoji = get<0>(q.front());
        clip = get<1>(q.front());
        t = get<2>(q.front());
        q.pop();
        if(imoji == S) {
            return t;
        }
        if(imoji < S && !visited[imoji][imoji]) {
            visited[imoji][imoji] = true;
            q.push({imoji,imoji,t+1});
        }
        if(imoji < S && !visited[imoji+clip][clip]) {
            visited[imoji+clip][clip] = true;
            q.push({imoji+clip,clip,t+1});
        }
        if(imoji > 2 && !visited[imoji-1][clip]) {
            visited[imoji-1][clip] = true;
            q.push({imoji-1,clip,t+1});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>S;
    ans = solve(0,0,1);
    cout<<ans<<"\n";
    return 0;
}