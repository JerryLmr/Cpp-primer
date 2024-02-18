#include<iostream>
#include<vector>
std::vector<int>*factory_vect(){
    return new std::vector<int>;
}
void set(std::vector<int>*vec){
    for (int i; std::cin >> i; vec->push_back(i));
}
void print(std::vector<int>*vec){
    for (const auto &e : *vec){
        std::cout << e << ' ';
    }
}
int main(){
   auto *p = factory_vect();
   set(p);
   print(p);
   delete p;
   return 0; 
}