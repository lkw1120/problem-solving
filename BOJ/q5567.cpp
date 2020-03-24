#include<bits/stdc++.h>
#define MAX 501
using namespace std;
vector<int> v[MAX];
int friends[MAX] = {0};
int N, M, ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N;
    cin>>M;
    int a, b;
    for(int i=0;i<M;i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++) {
            if(friends[v[x][i]] == 0) {
                friends[v[x][i]] = friends[x]+1;
                q.push(v[x][i]);
            }
        }
    }
    for(int i=2;i<=N;i++) {
        if(friends[i] == 1 || friends[i] == 2) {
            ans++; 
        }
    }
    cout<<ans<<"\n";
    return 0;
}