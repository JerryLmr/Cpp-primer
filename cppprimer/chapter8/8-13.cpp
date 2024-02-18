#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
struct Personinfo{
    string name;
    vector<string> phones;
};
constexpr int kPhoneNumberLength = 11;
bool valid(const string &num){
    if(num.size() != kPhoneNumberLength)
        return false;
    for (int i = 0; i < num.size(); ++i){
        if(num[i] < '0' || num[i] > '9')
            return false;
    }
    return true;
}
string format(const string & num){
    return num.substr(0,3) + '-' + num.substr(3,4) + '-' + num.substr(7,4);
}
int main(){
    string filename;
    cin >> filename;
    ifstream in(filename);
    if(!in){
        cerr << "Couldn't open the file:" + filename<< endl;
        return -1;
    }
    string line, word;
    vector<Personinfo> people;
    while(getline(in,line)){
        Personinfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for(const auto &e :people){
        ostringstream formatted,badNums;
        for(const auto &p : e.phones){
            if(!valid(p)){
                badNums << ' ' << p;
            }
            else{
                formatted << ' ' << format(p);
            }
        }
        if(badNums.str().empty()){
            cout << e.name << ' ' << formatted.str() << endl;
        }
        else{
            cerr << "input error:" << e.name << "\tinvalid number(s)" << badNums.str() << endl;
        }
    }
    return 0;
}