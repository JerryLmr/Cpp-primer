#include<bitset>
#include<iostream>
using namespace std;
template<unsigned N>
class quiz{
template<unsigned M>
friend ostream& operator<<(ostream& os,const quiz<M>& q);

template<unsigned M>
friend size_t grade(const quiz<M>&q1, const quiz<M>&q2);
public:
    quiz(string &s): bset(s){}
    void update(size_t n, bool b){
        bset[n] = b;
    }
private:
    bitset<N>bset;
};
template<unsigned M>
ostream& operator<<(ostream& os,const quiz<M>& q){
    os << q.bset;
    return os;
}
template<unsigned M>
size_t grade(const quiz<M>&q1, const quiz<M>&q2){
    return (q1.bset ^ q2.bset).flip().count();
}
int main(){
	std::string s1("0101010101");
	std::string s2("0101010100");

	quiz<10> q1(s1);
	quiz<10> q2(s2);

	std::cout << grade(q1, q2) << std::endl;
    return 0;
}