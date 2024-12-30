#include<bits/stdc++.h>
using namespace std;
double H,V,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>V;
    double d = sqrt(V*V+H*H);
    double a,b,c;
    a = V*(H/(H+d));
    b = V*(d/(H+d));
    c = sqrt(a*a+H*H);
    X = c/2;
    Y = (b*H)/c;
    cout<<X<<" "<<Y<<"\n";
    return 0;
}