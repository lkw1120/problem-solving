#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
vector<Pair> v;
int N,ans;
bool compare(Pair a, Pair b) {
    if(a.first != b.first) {
        return a.first > b.first;
    }
    else {
        return a.second > b.second;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);
    ans = 0;
    int tmp = -1;
    for(auto [a,b]: v) {
        if(tmp < b) {
            ans++;
            tmp = b;
        }
    }
    cout<<ans<<"\n";
    return 0;
}