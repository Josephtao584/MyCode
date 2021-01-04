
#include<iostream>
using namespace std;
typedef long long ll;
const long long mod = 1e9+7;

ll quick_pow(ll a, ll x)
{
    ll ans = 1;
    while(x){
        if(x & 1) ans = ans * a % mod;
        x >>= 1;
        a = a * a % mod;
    }
    return ans;
}


int main(){
   cout << quick_pow(2, 0);
}