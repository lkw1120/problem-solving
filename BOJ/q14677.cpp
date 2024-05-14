#include<bits/stdc++.h>
using namespace std;
char day[3] = {'B','L','D'};
bool visited[1500][1500];
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>str;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    int t,l,r;
    t = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            l = q.front().first;
            r = q.front().second;
            q.pop();
            if(l+r < 3*N) {
                if(str[l] == day[t%3] && !visited[l+1][r]) {
                    visited[l+1][r] = true;
                    q.push({l+1,r});
                }
                if(str[str.size()-1-r] == day[t%3] && !visited[l][r+1]) {
                    visited[l][r+1] = true;
                    q.push({l,r+1});
                }
            }
        }
        ans = t;
        t++;
    }
    cout<<ans<<"\n";
    return 0;
}