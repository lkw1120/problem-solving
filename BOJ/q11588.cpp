#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int conflict[21];
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        conflict[a]|=(1<<b);
        conflict[b]|=(1<<a);
    }
    ans = 0;
    int total = 1<<N;
    for(int i=0;i<total;i++) {
        bool flag = true;
        for(int j=0;j<N;j++) {
            if(i & (1<<j)) {
                if(i & conflict[j]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}