#include<bits/stdc++.h>
using namespace std;
int T,N;
bool check(int n) {
    int cnt = 0;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0) {
            cnt++;
            while(n%i == 0) n/=i;
        }
    }
    if(n > 1) cnt++;
    return cnt == 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        cout<<(check(N)? "No": "Yes")<<"\n";
    }
    return 0;
}