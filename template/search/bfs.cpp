//
// Created by Joseph on 2020/12/29.
//
#include <iostream>
#include <queue>
using namespace std;

const int N = 100, M = N * 2; //无向图邻接表
int h[N], e[M], ne[M], w[M], idx; // h存的是节点， e存的是边， ne是边的序号 头插法
int q[N], d[N];
bool st[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void bfs(){
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(!st[j]){
                q.push(j);
            }
        }
    }
}

void bfs_1(){
    int hh = 0, tt = 0;
    q[0] = 1; // 开始为1号节点
    memset(d, -1, sizeof d);
    d[1] = 0;
    while (hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(!d[j]){
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
}


int main()
{
    idx = 0;
    memset(h, -1, sizeof(h));
}

