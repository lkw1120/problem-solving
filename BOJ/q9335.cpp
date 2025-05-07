#include<bits/stdc++.h>
using namespace std;
int arr[21];
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        fill(arr,arr+21,0);
        cin>>N;
        int a,b;
        for(int i=0;i<N;i++) {
            cin>>a;
            for(int j=0;j<a;j++) {
                cin>>b;
                b--;
                arr[i]|=(1<<b);
            }
            arr[i]|=(1<<i);
        }
        int mask = (1<<N)-1;
        ans = N;
        for(int i=0;i<(1<<N);i++) {
            int cnt = __builtin_popcount(i);
            if(ans <= cnt) continue;
            int cover = 0;
            for(int j=0;j<N;j++) {
                if(i & (1<<j)) {
                    cover|=arr[j];
                }
            }
            if(cover == mask) {
                ans = cnt;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}