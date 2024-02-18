#include<iostream>
#include<string>
#include<vector>
#include<fstream>
std::vector<std::string> read(const std::string &filename){
    std::ifstream in(filename);
    std::vector<std::string>vc;
    if(in){
        /*for(std::string s;std::getline(in,s);){
            vc.push_back(s);
        }*/
        for(std::string s;in >> s;){;
            vc.push_back(s);
        }
    }
    else{
        std::cerr << "Couldn't open: " + filename << std::endl; 
    }
    return vc;
}
int main(){
    std::string filename;
    std::cin >> filename;
    auto vc = read(filename);
    for (int i = 0; i < vc.size(); ++i){
        std::cout << i + 1 << "\t" << vc[i] << std::endl;
    }
    return 0;
}