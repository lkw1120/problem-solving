#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 5000001;
bool row[MAX];
bool col[MAX];
ll M,N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>K;
    ll r,c;
    r = c = 0;
    for(int i=0;i<K;i++) {
        char ch;
        int x;
        cin>>ch>>x;
        if(ch == 'R') {
            r+=row[x]? -1: 1;
            row[x] = !row[x];
        }
        else {
            c+=col[x]? -1: 1;
            col[x] = !col[x];
        }
    }
    ans = r*(N-c)+c*(M-r);
    cout<<ans<<"\n";
    return 0;
}