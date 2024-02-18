#include<iostream>
#include<functional>
#include<map>
#include<string>

int add(int a, int b){
    return a + b;
}

struct multiple{
    int operator()(int a, int b) {return a * b;};
};

auto divide = [](int a, int b){return a / b;};
int main(){
    std::map<std::string, std::function<int(int,int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/",divide},
        {"*",multiple()},
        {"%",[](int a, int b){return a % b;}}
    };
    int a, b;
    std::string op;
    do{
        std::cout << "Enter an expression:" << std::endl;
        std::cin >> a >> op >> b;
        auto it = binops.find(op);
        if (it != binops.end()){
            std::cout << it->second(a,b) << std::endl;
        } 
        else {
            std::cout << "Undefined behavior!" << std::endl;
        }
    }
    while(std::cin);
    return 0;
}
