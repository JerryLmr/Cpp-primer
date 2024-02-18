#include<iostream>
#include<forward_list>

int main() {
	std::forward_list<int>l1{0,1,2,3,4,5,6,7,8,9};
	auto prev = l1.before_begin();
	auto cur = l1.begin();
	while( cur != l1.end()){
		if (*cur % 2 == 0){
			cur = l1.erase_after(prev);
		}
		else{
			prev = cur;
			cur++;
		}
	}
	for (const auto & e : l1){
		std::cout << e << ' ' << std::endl;
	}
}