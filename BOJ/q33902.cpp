#include <bits/stdc++.h>
using namespace std;
bool win[1001];
int X,Y;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X>>Y;
    fill(win,win+1001,false);
    for(int i=Y-1;i>=2;i--) {
        bool check = false;
        for(int j=i+1;j<=Y;j++) {
            if(!win[j] && gcd(i,j) == 1) {
                check = true;
                break;
            }
        }
        win[i] = check;
    }
    if(win[X]) {
        cout<<"khj20006"<<"\n";
    }
    else {
        cout<<"putdata"<<"\n";
    }
    return 0;
}
