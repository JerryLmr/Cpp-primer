#include<iostream>
#include<string>
using namespace std;
class Screen{
public:
    typedef string :: size_type pos;
    Screen() = default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht * wd, ' '){}
    Screen(pos ht,pos wd, char c): height(ht),width(wd),contents(ht * wd, c){}
    char get() const{
        return contents[cursor];
    }
    Screen set(char);
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);
    Screen display(ostream &os){do_display(os); return *this;}
    const Screen display(ostream &os)const {do_display(os); return *this;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const { os << contents;}
};
inline Screen Screen::set(char c){
    contents[cursor] = c;
    return *this;
} 
inline Screen Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const{
    pos row = r * width;
    return contents[row + c];
}
int main(){
    Screen myScreen(5,5,'x');
    myScreen.move(4,0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << "\n";
    return 0;
}