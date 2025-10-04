#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[4];
int r[4];
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<4;i++) {
        cin>>d[i];
    }
    for(int i=0;i<4;i++) {
        cin>>r[i];
    }
    int base = 0;
    for(int i=1;i<4;i++) {
        if(d[i] < d[base]) {
            base = i;
        }
    }
    ll tmp = r[base];
    while(1) {
        bool flag = true;
        for(int i=0;i<4;i++) {
            if(tmp%d[i] != r[i]) { 
                flag = false; 
                break;
            }
        }
        if(flag) {
            ans = tmp;
            break;
        }
        tmp+=d[base];
    }
    cout<<ans<<"\n";
    return 0;
}