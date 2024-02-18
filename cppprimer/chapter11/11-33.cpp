#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<string>
#include<stdexcept>
std::map<std::string, std::string> buildMap(std::ifstream &map_file){
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    while (map_file >> key && getline(map_file,value))    
        if (value.size() > 1)
            trans_map[key] = value.substr(1); //跳过前导空格
        else
            throw std::runtime_error("no rule for" + key);
    return trans_map;
}
const std::string & transform(const std::string &s, const std::map<std::string,std::string> &m){
    auto map_it = m.find(s);
    if (map_it != m.end()){
        return map_it -> second;
    }
    else
        return s;
}
void word_transform(std::ifstream &map_file,std::ifstream &input){
    auto trans_map = buildMap(map_file);
    std::string text;
    while(getline(input,text)){
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while (stream >> word){
            if (firstword)
                firstword = false;
            else    
                std::cout << " ";
            std::cout << transform(word,trans_map);
        }
        std::cout << std::endl;
    }
}
int main(){
    std::string dict,text;
    while(std::cin >> dict >> text){
        try{
            std::ifstream dic(dict);
            std::ifstream txt(text);
            if(!dic.is_open()){
                throw std::runtime_error("Couldn't open the dictionary file");            
            }
            if(!txt.is_open()){
                throw std::runtime_error("Couldn't open the text file");            
            }
            word_transform(dic,txt);
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
