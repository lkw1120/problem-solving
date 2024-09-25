#include<bits/stdc++.h>
using namespace std;
bool cam[100001];
int N,K,R,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K>>R;
    for(int i=0;i<K;i++) {
        cin>>X;
        cam[X] = true;
    }
    int cnt = 0;
    for(int i=1;i<=N;i++) {
        if(cam[i]) cnt++;
        if(R <= i) {
            if(cam[i-R]) cnt--;
            if(cnt < 2) {
                for(int j=i;j>0;j--) {
                    if(!cam[j]) {
                        cam[j] = true;
                        cnt++;
                        if(2 <= cnt) break;
                    }
                }
            }
        }
    }
    cnt = 0;
    for(int i=1;i<=N;i++) {
        if(cam[i]) cnt++;
    }
    ans = cnt-K;
    cout<<ans<<"\n";
    return 0;
}