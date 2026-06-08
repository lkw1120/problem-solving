#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M;
void dfs(int start) {
    int size = v.size();
    if(size == N) {
        for(int item: v) {
            cout<<item<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=start;i<=M;i++) {
        v.push_back(i);
        dfs(i+1);
        v.pop_back();
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    dfs(1);
    return 0;
}