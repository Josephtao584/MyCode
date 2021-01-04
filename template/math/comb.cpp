#include <iostream>

using namespace std;

const int N = 2010;
const int mod = 1e9 + 7;

int n;
int c[N][N];

int main(){
    cin >> n;
    for(int i = 0; i <= 2000; i++)
        for(int j = 0; j <= i; j++){
            if(j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }

    return 0;
}