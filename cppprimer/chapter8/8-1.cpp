#include<iostream>
#include<string>
std::istream & read (std::istream &is){
    is.clear();
    std::string str;
    while (is >> str) {
        std::cout << str << std::endl;
    }
    is.clear();
    return is;
}
int main(){
    read(std::cin);
    return 0;
}