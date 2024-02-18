#include<iostream>
using namespace std;
struct Person{
    friend istream &read(istream &, Person &);
    public:
        Person() = default;
        Person(const string &s): name(s){};
        Person(const string &s, const string & s2): name(s),address(s2){};
        Person(istream &is);
        string getname() const {return name;}
        string getaddress() const {return address;}
    private:
        string name;
        string address;
};
istream &read(istream &is, Person &rhs){
    is >> rhs.name >> rhs.address;
    return is;
}
ostream &print(ostream &os, const Person &rhs){
    os << rhs.getname() << " " << rhs.getaddress();
    return os;
}
Person::Person(istream& is){
    read(is,*this);
}
int main(){
    Person p1;
    Person p2("Zhang San");
    Person p3("Zhang San", "Earth");
    Person p4(cin);

    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    print(cout, p4) << endl;
}