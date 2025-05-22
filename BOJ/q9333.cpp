#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
double R,B,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>R>>B>>M;
        ll debt = (ll)(round(B*100));
        ll payment = (ll)(round(M*100));
        ll r = (ll)(round(R*100));

        bool flag = false;
        int month = 0;
        while(0 < debt) {
            ll interest = (debt*r+5000)/10000;
            if(payment <= interest) {
                flag = true;
                break;
            }
            debt+=interest;
            debt-=payment;
            month++;
            if(1200 < month) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout<<"impossible"<<"\n";
        }
        else {
            cout<<month<<"\n";
        }
    }
    return 0;
}