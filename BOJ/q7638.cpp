#include<bits/stdc++.h>
using namespace std;
double arr[11][101];
int N,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(4);
    while(true) {
        cin>>N>>M;
        if(N == 0 && M == 0) break;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin>>arr[j][i];
            }
        }
        for(int j=0;j<M;j++) {
            sort(arr[j],arr[j]+N,greater<double>());
        }
        ans = 0.0;
        for(int i=0;i<N;i++) {
            double tmp = 1.0;
            for(int j=0;j<M;j++) {
                tmp*=arr[j][i];
            }
            ans+=tmp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}