#include<bits/stdc++.h>
using namespace std;
int arr[10001];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N;
        if(!cin || N == 0) break;
        char ch;
        cin>>ch;
        for(int i=0;i<N;i++) {
            int x;
            cin>>x;
            arr[x] = i;
        }
        bool flag = true;
        for(int i=0;i<N && flag;i++) {
            for(int j=1;i+2*j<N;j++) {
                int a,b,c;
                a = arr[i];
                b = arr[i+j];
                c = arr[i+2*j];
                if(a < b && b < c) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"yes"<<"\n";
        }
        else {
            cout<<"no"<<"\n";
        }
    }
    return 0;
}