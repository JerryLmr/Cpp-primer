#include<iostream>
#include<memory>
#include<vector>
typedef std::shared_ptr<std::vector<int>> share_vec_ptr;
share_vec_ptr factory_vect(){
    return std::make_shared<std::vector<int>>();
}
void set(share_vec_ptr vec){
    for (int i; std::cin >> i; vec->push_back(i));
}
void print(share_vec_ptr vec){
    for (const auto &e : *vec){
        std::cout << e << ' ';
    }
}
int main(){
   auto p = factory_vect();
   set(p);
   print(p);
   return 0; 
}