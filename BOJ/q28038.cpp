#include<bits/stdc++.h>
using namespace std;
int T,N;
double A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    cout.precision(10);
    cout<<fixed;
    while(T--) {
        int type;
        cin>>type;
        cin>>A>>B;
        double r,theta;
        if(type == 1) {
            r = sqrt(A*A+B*B);
            theta = 0.0;
            if(r != 0.0) {
                theta = atan2(B,A);
                if(theta < 0) {
                    theta+=2*M_PI;
                }
            }
            cout<<r<<" "<<theta<<"\n";
        }
        else {
            r = A;
            theta = B;
            double x,y;
            x = r*cos(theta);
            y = r*sin(theta);
            cout <<x<<" "<<y<<"\n";
        }
    }
    return 0;
}