#include<iostream>
// 用于求N中互质的数的数量
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int res = x;
        for(int j = 2; j <= x / j; j++){
            if(x % j == 0){
                while(x % j == 0){
                    x /= j;
                }
                res = res / j * (j - 1);
            }
        }
        if(x > 1) res = res / x * (x - 1);
        cout << res << endl;
    }
}