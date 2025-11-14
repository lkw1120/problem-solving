#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+1;
unordered_map<string,vector<string>> adj;
int cnt[MAX_N];
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>str;
    for(int i=0;i<N-1;i++) {
        string str1,str2;
        char ch;
        cin>>str1>>ch>>str2;
        adj[str1].push_back(str2);
    }
    queue<pair<string,int>> q;
    q.push({str,0});
    while(!q.empty()) {
        string cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        cnt[depth]++;
        for(auto next: adj[cur]) {
            q.push({next,depth+1});
        }
    }
    ans = *max_element(cnt,cnt+MAX_N);
    cout<<ans<<"\n";
    return 0;
}