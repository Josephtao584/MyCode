//
// Created by Joseph on 2020/12/29.
//
#include <iostream>
using namespace std;
const int N = 100;
int h[N], e[N], ne[N], idx;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
    cout << "hello" << endl;
}

