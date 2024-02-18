#include <map>
#include <string>
#include <iostream>

int main() {
  std::multimap<std::string, std::string> authors;

  authors.insert({"Zhang San", "Hello world 3"});
  authors.insert({"Zhang San", "Hello world"});
  authors.insert({"Wang Wu", "Hello again world 2"});
  authors.insert({"Zhang San", "Hello world 2"});
  authors.insert({"Li Si", "Bye world"});
  authors.insert({"Wang Wu", "Hello again world"});
  
  std::string name;
  do{
    std::cout << "All the books are:\n";
    for(const auto &a : authors){
        std::cout << "author: " << a.first
                  << "book: "   << a.second << std::endl;
    }
    std::cout << "\nEnter the author name you want delete: ";
    std::getline(std::cin,name);
    auto it = authors.find(name);
    if (it != authors.end()){
        authors.erase(it);
    } 
    else
      std::cerr << "No author named \"" << name << "\", please try again!\n"
                << std::endl;    
  }while(std::cin);
}