#include<bits/stdc++.h>
using namespace std;
int N,A,B,J,C;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>A;
    int sum = A;
    for(int i=1;i<N;i++) {
        cin>>B;
        sum+=B;
    }
    cin>>J>>C;
    ans = A+((double)A/sum)*J*C;
    cout<<fixed;
    cout.precision(10);
    cout<<ans<<"\n";
    return 0;
}