#include<bits/stdc++.h>
using namespace std;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = (N*1.0)/((N-1)*2);
    cout<<ans<<"\n";
    return 0;
}