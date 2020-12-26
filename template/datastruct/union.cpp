//
// Created by Joseph on 12/26/2020.
//
const int N = 50010;
int p[N];
int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
