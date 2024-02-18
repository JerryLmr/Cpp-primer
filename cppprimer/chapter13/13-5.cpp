#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s) 
        : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &ori)
        : ps(new std::string(*ori.ps)), i(ori.i) {}

    const std::string &get() const { return *ps; }
    void set(const std::string &s) { *ps = s; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new std::string(*rhs.ps);//拷贝底层string
    delete ps;  //释放旧内存
    ps = newp;
    i = rhs.i;
    return *this;
}
HasPtr::~HasPtr(){
    delete ps;
}
int main() {
  HasPtr hp1("World");
  HasPtr hp2 = hp1;
  hp1.set("Hello");

  std::cout << hp1.get() << " " << hp2.get() << std::endl;

  return 0;
}