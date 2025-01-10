#include<bits/stdc++.h>
using namespace std;
int T,A,B,C;
string ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>A>>B>>C;
        if(A < C && B < C) {
            ans = "NO";
        }
        else {
            if(C%gcd(A,B) == 0) {
                ans = "YES";
            }
            else {
                ans = "NO";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}