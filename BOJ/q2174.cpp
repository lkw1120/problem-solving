#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
int matrix[MAX][MAX] = {0};
tuple<int,int,int> p[MAX];
int dY[4] = {1,0,-1,0};
int dX[4] = {0,1,0,-1};
int A,B,N,M;
void rotate(int robot, char cmd) { 
    int x,y,c;
    y = get<0>(p[robot]);    
    x = get<1>(p[robot]);
    c = get<2>(p[robot]);
    c+=4;
    switch(cmd) {
        case 'L':
            c--;
            c%=4;
            break;
        case 'R':
            c++;
            c%=4;
            break;
    }
    p[robot] = {y,x,c};
}
int move(int robot, char cmd) {
    int x,y,c;
    y = get<0>(p[robot]);    
    x = get<1>(p[robot]);
    c = get<2>(p[robot]);
    matrix[y][x] = 0;
    y+=dY[c];
    x+=dX[c];
    if(x <= 0 || A < x || y <= 0 || B < y) {
        return -1;
    }
    if(matrix[y][x] != 0) {
        return matrix[y][x];
    }
    p[robot] = {y,x,c};
    matrix[y][x] = robot;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>A>>B;
    cin>>N>>M;
    int x,y,c,n,r;
    char d;
    for(int i=1;i<=N;i++) {
        cin>>x>>y>>d;
        if(d == 'N') c = 0;
        if(d == 'E') c = 1;
        if(d == 'S') c = 2;
        if(d == 'W') c = 3;
        p[i] = {y,x,c};
        matrix[y][x] = i;
    }
    int code;
    for(int i=0;i<M;i++) {
        cin>>n>>d>>r;
        if(d != 'F') {
            r%=4;
            for(int j=0;j<r;j++) {
                rotate(n,d);
            }
        }
        else{
            for(int j=0;j<r;j++) {
                code = move(n,d);
                if(code == -1) {
                    cout<<"Robot "<<n<<" crashes into the wall"<<"\n";
                    return 0;
                }
                if(code > 0) {
                    cout<<"Robot "<<n<<" crashes into robot "<<code<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"OK"<<"\n";
    return 0;
}