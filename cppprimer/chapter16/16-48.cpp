#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string debug_rep(char *p){
    ostringstream ret;
    ret << "pointer: " << p;
    return ret.str();
}
template <typename T> string debug_rep(const T& t){
    ostringstream ret;
    ret << t;
    return ret.str();
}
int main(){
    std::cout << debug_rep("hello world");
}

