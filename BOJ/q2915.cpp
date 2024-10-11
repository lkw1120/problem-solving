#include<bits/stdc++.h>
using namespace std;
int I,V,X,L,C;
string str;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    I = V = X = L = C = 0;
    int size = str.size();
    for(int i=0;i<size;i++) {
        if(str[i] == 'I') I++;
        if(str[i] == 'V') V++;
        if(str[i] == 'X') X++;
        if(str[i] == 'L') L++;
        if(str[i] == 'C') C++;
    }
    str = "";
    // 1
    if(V == 1) {
        if(I == 0) str+="V";
        if(I == 1) str+="IV";
        if(I == 2) str+="VII";
        if(I == 3) str+="VIII";
    }
    else {
        if(I == 1) {
            if((L == 1 && X == 2) || (C == 0 && L == 0 && 1 <= X) || (C == 1 && X == 2)) {
                str+="IX";
                X--;
            }
            else {
                str+="I";
            }
        }
        else {
            if(I == 2) str+="II";
            if(I == 3) str+="III";
        }
    }
    // 10
    if(L == 1) {
        if(X == 0) str = "L"+str;
        if(X == 1) str = "XL"+str;
        if(X == 2) str = "LXX"+str;
        if(X == 3) str = "LXXX"+str;
    }
    else {
        if(X == 1 && C == 1) {
            str = "XC"+str;
        }
        else {
            if(X == 1) str = "X"+str;
            if(X == 2) str = "XX"+str;
            if(X == 3) str = "XXX"+str;
        }
    }
    cout<<str<<"\n";
    return 0;
}