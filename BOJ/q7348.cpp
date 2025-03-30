#include<bits/stdc++.h>
using namespace std;
int room[205];
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(room,room+205,0);
        cin>>N;
        int s,t;
        for(int i=0;i<N;i++) {
            cin>>s>>t;
            if(t < s) swap(s,t);
            s--,t--;
            s/=2,t/=2;
            room[s]++;
            room[t+1]--;
        }
        int now = 0;
        for(int i=0;i<=200;i++) {
            now+=room[i];
            room[i] = now;
        }
        ans = 0;
        for(int i=0;i<=200;i++) {
            ans = max(ans,room[i]*10);
        }
        cout<<ans<<"\n";
    }
    return 0;
}