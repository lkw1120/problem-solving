#include<bits/stdc++.h>
#define MAX 15
using namespace std;
char ch[MAX] = {};
int L,C;
bool isPw(string &pw) {
    int ja = 0, mo = 0;
    int length = pw.length();
    for (int i = 0; i < length; i++) {
        switch (pw[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                mo++;
                break;
            
            default:
                ja++;
                break;
        }
    }
    return ja >= 2 && mo >= 1;
}
void makePw(string pw, int c) {
    if(pw.length() == L) {
        if(isPw(pw)) {
            cout<<pw<<"\n";
        }
        return ;
    }
    if(c >= C) {
        return ;
    }
    makePw(pw+ch[c],c+1);
    makePw(pw,c+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>L>>C;
    for(int i=0;i<C;i++) {
        cin>>ch[i];
    }
    sort(ch,ch+C);
    makePw("",0);
    return 0;
}