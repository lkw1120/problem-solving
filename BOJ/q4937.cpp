#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N;
        if(N < 0) break;
        M = N;
        bool flag = true;
        int p = 3;
        while(1 < M) {
            if(M%p == 0) {
                if(p%10 != 3) {
                    flag = false;
                    break;
                }
                M/=p;
            }
            else {
                p++;
            }
        }
        if(flag) {
            cout<<N<<" "<<"YES"<<"\n";
        }
        else {
            cout<<N<<" "<<"NO"<<"\n";
        }
    }
    return 0;
}