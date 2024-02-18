#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s) 
        : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr &ori)
        : ps(ori.ps), i(ori.i), use(ori.use) {++*use;}

    const std::string &get() const { return *ps; }
    void set(const std::string &s) { *ps = s; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();
private:
    std::size_t *use;
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++ *rhs.use;
    if(--*rhs.use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
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