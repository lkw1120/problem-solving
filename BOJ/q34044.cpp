#include<bits/stdc++.h>
using namespace std;
int N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N == 1) {
        ans = "-1";
    }
    else {
        ans = "";
        if(N%2 == 0) {
            for(int i=0;i<N/2;i++) {
                ans+="4323";
            }
        }
        else {
            ans+="173173";
            int tmp = N-3;
            for(int i=0;i<tmp/2;i++) {
                ans+="4323";
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}