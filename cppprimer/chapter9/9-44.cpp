#include<iostream>
#include<string>

void replaceStr(std::string &s, const std::string &oldVal, const std::string &newVal){
    for (std::string::size_type i = 0; i < s.size(); ++i){
        if (s.substr(i,oldVal.size()) == oldVal){
            s.replace(i,oldVal.size(), newVal);
            i += newVal.size();
        }
        
    }
}
int main() {
  std::string s{"r u ok?\ngo thru\ntho tho altho\nthrough thruu"};

  std::cout << "Old:\n" << s << std::endl;
  replaceStr(s, "tho", "though");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "thru", "through");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "hl", "hello");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "u", "you");
  std::cout << "\nNew:\n" << s << std::endl;

  return 0;
}