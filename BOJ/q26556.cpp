#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,M,ans;
void find(int n, int m, int cnt) {
    if(m == M) {
        ans = min(cnt,ans);
        return ;
    }
    for(int i=n;i<N;i++) {
        if(m+v[i] <= M) {
            find(i+1,m+v[i],cnt+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N;
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        cin>>M;
        ans = INT_MAX;
        find(0,0,0);
        if(ans != INT_MAX) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"Not possible"<<"\n";
        }
    }
    return 0;
}