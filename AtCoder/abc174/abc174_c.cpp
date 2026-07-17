#include<bits/stdc++.h>
using namespace std;
int K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    int tmp = 0;
    ans = -1;
    for(int i=1;i<=K;i++) {
        tmp = (tmp*10+7)%K;
        if(tmp == 0) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}