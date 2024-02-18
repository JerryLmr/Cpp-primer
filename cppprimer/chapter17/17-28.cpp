#include<iostream>
#include<random>
using namespace std;
unsigned random_func(){
    static uniform_int_distribution<unsigned>u;
    static default_random_engine e;
    return u(e);
}
unsigned random_func(unsigned i){
    static uniform_int_distribution<unsigned>u;
    static default_random_engine e(i);
    return u(e);
}
unsigned random_func(unsigned i, unsigned min, unsigned max){
    static uniform_int_distribution<unsigned>u(min,max);
    static default_random_engine e(i);
    return u(e);
}
int main(){
    cout << random_func() << endl;
    cout << random_func(2) << endl;
    for (int i = 0; i < 10; ++i){
        cout << random_func(1,0,10) << endl;
    }
    return 0;
}
