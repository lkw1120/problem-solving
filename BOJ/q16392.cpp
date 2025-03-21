#include<bits/stdc++.h>
using namespace std;
string str;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin.ignore();
    double pi = acos(-1.0);
    for(int i=0;i<N;i++) {
        getline(cin,str);
        double size = str.size();
        for(int j=0;j<str.size()-1;j++) {
            int idx1, idx2;
            char c1 = str[j];
            char c2 = str[j+1];
            if(c1 >= 'A' && c1 <= 'Z') {
                idx1 = c1-'A';
            }
            else if(c1 == ' ') {
                idx1 = 26;
            }
            else {
                idx1 = 27;
            }
            if(c2 >= 'A' && c2 <= 'Z') {
                idx2 = c2-'A';
            }
            else if(c2 == ' ') {
                idx2 = 26;
            }
            else {
                idx2 = 27;
            }
            int diff = abs(idx1-idx2);
            int d = min(diff,28-diff);
            size+=(d*pi)/7.0;
        }
        cout.precision(10);
        cout<<fixed<<size<<"\n";
    }
    return 0;
}