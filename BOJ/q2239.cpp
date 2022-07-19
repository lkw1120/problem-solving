#include<bits/stdc++.h>
using namespace std;
int sudoku[10][10];
bool c1[10][10];
bool c2[10][10];
bool c3[10][10];
int square(int x, int y) {
    return (x/3)*3+(y/3);
}
bool solve(int z) {
    if (z == 81) {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                cout<<sudoku[i][j];
            }
            cout<<"\n";
        }
        return true;
    }
    int x = z/9;
    int y = z%9;
    if (sudoku[x][y] != 0) {
        return solve(z+1);
    } else {
        for (int i=1; i<=9;i++) {
            if (c1[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i] == 0) {
                c1[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                sudoku[x][y] = i;
                if (solve(z+1)) {
                    return true;
                }
                sudoku[x][y] = 0;
                c1[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    for(int i=0;i<9;i++) {
		string input;
		cin>>input;
        for (int j=0;j<9;j++) {
            sudoku[i][j] = input[j]-'0';
            if (sudoku[i][j] != 0) {
                c1[i][sudoku[i][j]] = true;
                c2[j][sudoku[i][j]] = true;
                c3[square(i,j)][sudoku[i][j]] = true;
            }
        }
    }
	solve(0);
	return 0;
}