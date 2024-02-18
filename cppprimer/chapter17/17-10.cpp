#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
int main(){
    vector<int>vec{1, 2, 3, 5, 8, 13, 21};
    bitset<32>bset;
    for (const auto i : vec){
        bset.set(i);
    }
    cout << bset << endl;
}