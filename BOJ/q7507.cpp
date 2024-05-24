#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
int N,M,D,S,E,ans;
bool compare(Pair a, Pair b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int n=1;n<=N;n++) {
        vector<pair<int,int>> v[50001];
        cin>>M;
        for(int i=0;i<M;i++) {
            cin>>D>>S>>E;
            v[D].push_back({S,E});
        }
        ans = 0;
        for(int i=1;i<50001;i++) {
            if(v[i].empty()) continue;
            sort(v[i].begin(),v[i].end(),compare);
            int t,cnt;
            t = cnt = 0;
            for(auto item:v[i]) {
                if(t <= item.first) {
                    t = item.second;
                    cnt++;
                }
            }
            ans+=cnt;
        }
        cout<<"Scenario #"<<n<<":"<<"\n";
        cout<<ans<<"\n\n";
    }
    return 0;
}