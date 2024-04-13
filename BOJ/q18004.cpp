#include<bits/stdc++.h>
using namespace std;
int A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    if(A < B) {
        ans = B-A;
    }
    else {
        int cnt = 0;
        while(A != B) {
            if(B*2 <= A) {
                if(A%2) {
                    A++;
                }
                else {
                    A/=2;
                }
            }
            else {
                if(A%2) {
                    A++;
                    cnt++;
                }
                A/=2;
                cnt++;
                cnt+=B-A;
                break;
            }
            cnt++;
        }
        ans = cnt;
    }
    cout<<ans<<"\n";
    return 0;
}