#include<bits/stdc++.h>
using namespace std;
bool check[1000001];
int N,A,B,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        cin>>A>>B>>C;
        if(!check[A] && !check[B] && !check[C]) {
            ans++;
        }
        check[A] = check[B] = check[C] = true;
    }
    cout<<ans<<"\n";
    return 0;
}