#include<bits/stdc++.h>
using namespace std;
int N,X1,X2,X3,X4,Y1,Y2,Y3,Y4;
double crossProduct(double a, double b, double c, double d) {
    return a*d-b*c;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    while(N--) {
        cin>>X1>>Y1>>X2>>Y2>>X3>>Y3>>X4>>Y4;
        pair<double,double> ab,cd,ac;
        ab = {X2-X1,Y2-Y1};
        cd = {X4-X3,Y4-Y3};
        ac = {X3-X1,Y3-Y1};
        double cp = crossProduct(ab.first,ab.second,cd.first,cd.second);
        if(cp == 0) {
            if(crossProduct(ab.first,ab.second,ac.first,ac.second) == 0) {
                cout<<"LINE"<<"\n";
            }
            else {
                cout<<"NONE"<<"\n";
            }
        }
        else {
            double t = crossProduct(ac.first,ac.second,cd.first,cd.second)/cp;
            double x = X1+t*ab.first;
            double y = Y1+t*ab.second;
            cout<<fixed;
            cout.precision(2);
            cout<<"POINT "<<x<<" "<<y<<"\n";
        }
    }
    return 0;
}