#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll tmp = N;
    int depth = 0;
    while(tmp > 0) {
        depth++;
        tmp/=2;
    }
    ll x = 1;
    int turn = 0;
    while(x <= N) {
        if(depth%2 == 1) {
            x = turn%2 == 0? x*2+1: x*2;
        }
        else {
            x = turn%2 == 0? x*2: x*2+1;
        }
        turn++;
    }
    cout<<(turn%2 == 0? "Takahashi": "Aoki")<<"\n";
    return 0;
}