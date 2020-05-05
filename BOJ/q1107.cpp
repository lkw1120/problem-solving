#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
bool broken[10] = {false};
int N,M,m,ans;
int possible(int ch) {
    int len = 0;
    if (ch == 0) {
        return broken[0] ? 0 : 1;
    }
    while(ch > 0) {
        if(broken[ch%10]) {
            return 0;
        }
        ch/=10;
        len++;
    }
    return len;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    ans = abs(N-100);
    for(int i=0;i<M;i++) {
        cin>>m;
        broken[m] = true;
    }
    for(int i=0;i<MAX;i++) {
        int len = possible(i);
        if(len > 0) {
            int btn = abs(i-N);
            ans = min(ans,len+btn); 
        }
    }
    cout<<ans<<"\n";
    return 0;
}