#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N;
        if(cin.eof()) break;
        int p = 1;
        while(1) {
            p*=9;
            if(N <= p) {
                cout<<"Baekjoon wins."<<"\n";
                break;
            }
            p*=2;
            if(N <= p) {
                cout<<"Donghyuk wins."<<"\n";
                break;
            }
        }
    }
    return 0;
}