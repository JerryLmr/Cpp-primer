#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
std::ostream &print(std::ostream &os, const std::vector<std::string> &vs){
    for (const auto&i : vs){
        os << i << ' ';
    }
    return os;
}
bool isShorter(const std::string &s1, const std::string &s2){
    return s1.size() < s2.size();
}
void elimDups(std::vector<std::string> &words){
    print(std::cout,words) << std::endl;
    std::sort(words.begin(),words.end());
    print(std::cout,words) << std::endl;
    auto end_unique = std::unique(words.begin(),words.end());
    print(std::cout,words) << std::endl;
    words.erase(end_unique,words.end());
    print(std::cout,words) << std::endl;
}
int main(){
    std::vector<std::string>words{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    print(std::cout, words) << std::endl;
}