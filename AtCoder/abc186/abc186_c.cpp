#include<bits/stdc++.h>
using namespace std;
int N,ans;
bool check(int n,int m) {
    while(n > 0) {
        if(n%m == 7) {
            return false;
        }
        n/=m;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        if(check(i,10) && check(i,8)) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}