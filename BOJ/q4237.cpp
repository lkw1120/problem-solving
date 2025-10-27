#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N;
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        if(N <= 1) {
            ans = N;
        }
        else {
            int cnt,tmp;
            tmp = cnt = 1;
            for(int i=1;i<N;i++) {
                int diff = v[i]-v[i-1];
                if((diff < 0 && tmp >= 0) || (diff > 0 && tmp <= 0)) {
                    cnt++;
                    tmp = diff;
                }
            }
            ans = cnt;
        }
        cout<<ans<<"\n";
    }
    return 0;
}