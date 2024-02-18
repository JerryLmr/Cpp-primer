#include"func.h"
#include<iostream>
using namespace std;
int add(int a,int b){
    cout<<"Called (" << a << '+' << b << ')' << endl;
    return a + b;
}
int sub(int a,int b){
    cout<<"Called (" << a << '-' << b << ')' << endl;
    return a - b;
}
int mul(int a,int b){
    cout<<"Called (" << a << 'x' << b << ')' << endl;
    return a * b;
}
int div2(int a,int b){
    try{
        if(b == 0)
            throw runtime_error("The divided number can't be 0!");
        cout <<"Called (" << a << '/' << b << ')' << endl;
        return a/b;
    }
    catch(runtime_error err){
        cout << err.what()
             << endl;
        return 0;
    }
}