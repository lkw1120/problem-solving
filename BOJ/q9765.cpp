#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> X[8];
vector<ll> C(7);
void find(int a, int b, int c) {
    for(ll i=2;i*i<=C[a];i++) {
        if(C[a] != i && C[a]%i == 0) {
            X[b].push_back(i);
            X[b].push_back(C[a]/i);
            X[c].push_back(i);
            X[c].push_back(C[a]/i);
            break;
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=6;i++) {
        cin>>C[i];
    }
    find(1,1,2);
    find(3,6,7);
    find(5,2,3);
    find(6,5,6);
    for(auto a: X[1]) {
        for(auto b: X[2]) {
            for(auto c: X[3]) {
                for(auto d: X[5]) {
                    for(auto e: X[6]) {
                        for(auto f: X[7]) {
                            if(a*b == C[1] && e*f == C[3] && b*c == C[5] && d*e == C[6]) {
                                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<"\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}