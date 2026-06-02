#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll p3 = 3;
    for(int a=1;a<=37;a++) {
        ll p5 = 5;
        for(int b=1;b<=25;b++) {
            if(p3+p5 == N) {
                cout<<a<<" "<<b<<"\n";
                return 0;
            }
            p5*=5;
        }
        p3*=3;
    }
    cout<<-1<<"\n";
    return 0;
}