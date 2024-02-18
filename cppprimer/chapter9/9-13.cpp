#include<iostream>
#include<list>
#include<vector>
int main(){
    std::list<int>l1{0,1,2};
    std::vector<int>v1{0,1,2};
    std::vector<double>vc(l1.begin(),l1.end());
    std::vector<double>vc2(v1.begin(),v1.end());
    std::cout << vc[0] << ' ' << vc2[0] << std::endl;
    return 0;
}