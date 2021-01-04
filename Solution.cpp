#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, M = 1010;

int h[N], e[M], ne[M], idx = 0;
bool st[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j])dfs(j);
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cout << "hello" << endl;
}