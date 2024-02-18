#include<iostream>
#include<list>
#include<vector>
#include<string>
int main(){
    std::list<char*>l1{"abc"};
    std::vector<std::string>v1;
    v1.assign(l1.begin(),l1.end());
    for(const auto &c : v1)
        std::cout << c;
    return 0;
}