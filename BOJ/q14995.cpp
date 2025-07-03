#include<bits/stdc++.h>
using namespace std;
const int MAX_K = 1e6+1;
bool like[2][MAX_K];
int X,Y,A,B,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X;
    for(int i=0;i<X;i++) {
        int k;
        cin>>k;
        like[0][k] = true;
    }
    cin>>Y;
    for(int i=0;i<Y;i++) {
        int k;
        cin>>k;
        like[1][k] = true;
    }
    A = B = C = 0;
    for(int k=0;k<MAX_K;k++) {
        bool x = like[0][k];
        bool y = like[1][k];
        if(x && !y) {
            int tmp = max(B,C)+1;
            A = max(A,tmp);
        }
        else if(!x && y) {
            int tmp = max(A,C)+1;
            B = max(B,tmp);
        }
        else if(x && y) {
            int tmp = max({A,B,C})+1;
            C = max(C,tmp);
        }
    }
    ans = max({A,B,C});
    cout<<ans<<"\n";
    return 0;
}