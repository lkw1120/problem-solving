#include<bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
double X1,X2,X3,Y1,Y2,Y3;
double D,X,Y,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>X1;
        if(cin.eof()) break;
        cin>>Y1>>X2>>Y2>>X3>>Y3;
        D = 2*(X1*(Y2-Y3)+X2*(Y3-Y1)+X3*(Y1-Y2));
        X = ((X1*X1+Y1*Y1)*(Y2-Y3)+(X2*X2+Y2*Y2)*(Y3-Y1)+(X3*X3+Y3*Y3)*(Y1-Y2))/D;
        Y = ((X1*X1+Y1*Y1)*(X3-X2)+(X2*X2+Y2*Y2)*(X1-X3)+(X3*X3+Y3*Y3)*(X2-X1))/D;
        R = sqrt((X1-X)*(X1-X)+(Y1-Y)*(Y1-Y));
        ans = R*2*PI;
        cout<<fixed;
        cout.precision(2);
        cout<<ans<<"\n";
    }
    return 0;
}