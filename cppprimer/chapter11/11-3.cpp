#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>
#include<iterator>
#include<stdexcept>

std::map<std::string,std::size_t>count_words(std::vector<std::string>&words){
    std::map<std::string,std::size_t>counts;
    for (const auto &w : words){
        counts[w]++;
    }
    return counts;
}
int main(){
    std::string filename;
    while(std::cin >> filename){
        try{
            std::ifstream in(filename);
            if(!in.is_open()){
                throw std::runtime_error("Couldn't open the file");            
            }
            std::istream_iterator<std::string>i_iter(in),eof;
            std::vector<std::string>words(i_iter,eof);
            auto counts = count_words(words);
            for (const auto &c : counts){
                std::cout << c.first << " occurs " << c.second 
                        << (c.second > 1 ? "times":"time") << std::endl;
            }
            return 0;
        }
        catch (std::runtime_error err){
            std::cout<<err.what()
                     << "\nTry again? Enter y or n" << std::endl;
            char c;
            std::cin >> c;
            if(!std::cin || c == 'n')
                break;
        }
    }
}