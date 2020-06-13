#include<bits/stdc++.h>
using namespace std;
const int MAX = 2001;
vector<int> v[MAX];
bool check[MAX] = {false};
int N,M,a,b,ans;
void dfs(int x, int cnt) {
    if(cnt == 5) {
        ans = 1;
        return ;
    }
    check[x] = true;
    for(auto item: v[x]) {
        if(!check[item]) {
            dfs(item,cnt+1);
        }
        if(ans == 1) {
            return ;
        }
    }
    check[x] = false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        dfs(i,1);
        if(ans == 1) break;
    }
    cout<<ans<<"\n";
    return 0;
}