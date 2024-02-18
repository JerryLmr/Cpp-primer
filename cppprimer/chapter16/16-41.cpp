#include<iostream>
using namespace std;
template<typename T>
auto sum(T lhs, T rhs) -> decltype (lhs + rhs){
    return lhs + rhs;
}
int main(){

}