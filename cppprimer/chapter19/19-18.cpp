#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

int main(){
    std::vector<std::string>vs = {"a", "bb", "", "ccc", ""};
    std::function<bool (const std::string&)> fcn = std::string::empty;
    auto it1 = std::find_if(vs.begin(),vs.end(),fcn);
    std::cout << "fcn:" << it1 - vs.begin() << std::endl;
}