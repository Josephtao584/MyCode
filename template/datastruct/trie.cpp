#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx; // 下标是0的点，既是根节点，又是空节点
char str[N];

void insert(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];

}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char op[2];
        cin >> op >> str;
        if(op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}