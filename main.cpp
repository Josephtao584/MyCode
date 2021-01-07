#include<iostream>
#include<algorithm>

using namespace std;


const int N = 6010;

int n;
int h[N], e[N], ne[N], idx;
int w[N], in[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int[] search(int x){

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        in[a]++;
    }
    int start = 0;
    for(int i = 0; i < n; i++){
        if(in[i] == 0){
            start = i;
            break;
        }
    }

    int ans = 0;
}