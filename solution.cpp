#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<int> set;
    while(n--){
        char c;
        int num;
        cin >> c >> num;
        if(c == 'I'){
            set.insert(num);
        }else{
            if(set.count(num))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}