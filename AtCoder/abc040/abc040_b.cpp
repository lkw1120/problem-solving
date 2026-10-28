#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int x,y;
    x = sqrt(N);
    y = N/x;
    if(x*y == N) {
        ans = abs(x-y);
    }
    else {
        ans = INT_MAX;
        int sum = 0;
        while(x) {
            y = N/x;
            if(x*y == N) {
                sum = y-x;
            }
            else {
                sum = y-x;
                sum+=N%(x*y);
            }
            ans = min(ans,sum);
            x--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}