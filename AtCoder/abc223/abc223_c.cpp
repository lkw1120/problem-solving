#include<bits/stdc++.h>
using namespace std;
vector<double> a,b;
int N;
double A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    double total = 0.0;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        total+=A/B;
        a.push_back(A);
        b.push_back(B);
    }
    double half = total/2.0;
    ans = 0.0;
    for(int i=0;i<N;i++) {
        double burn = a[i]/b[i];
        if(half >= burn) {
            ans+=a[i];
            half-=burn;
        } 
        else {
            ans+=b[i]*half;
            break;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}