#include<iostream>
#include<vector>
#include"func.h"
using namespace std;
int add(int,int);
int sub(int,int);
int mul(int,int);
int div2(int,int);
int main(){
    vector<int (*) (int a,int b)>vf;
    vf.push_back(add);
    vf.push_back(sub);
    vf.push_back(mul);
    vf.push_back(div2);
    
    int a,b;
    cin >> a >> b;
    for(const auto &e : vf){
        cout << e(a,b) << endl;
    }
    return 0;
}

