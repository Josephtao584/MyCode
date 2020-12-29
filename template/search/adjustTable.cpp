//
// Created by Joseph on 2020/12/29.
//
#include <iostream>
using namespace std;

const int N = 100, M = N * 2; //无向图邻接表
int h[N], e[N], ne[N], idx; // h存的是节点， e存的是边， ne是边的序号 头插法
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    st[u] = true;
    for(int i = h[u], i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j])
            dfs[j];
    }
}
int main()
{
    idx = 0;
    memset(h, -1, sizeof(h));
}

