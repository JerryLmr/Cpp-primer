#include<iostream>
#include<vector>
#include<deque>
using namespace std;
template<typename T>void print(const T &t){
    for (typename T::size_type i = 0; i != t.size(); ++i){
        cout << t[i] << ' '; 
    }
    cout << endl;
}
int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  std::vector<double> vd { 1.1, 2.2, 3.3, 4.4, 5.5 };
  std::deque<int> di { 1, 2, 3, 4, 5 };

  print(vi);
  print(vd);
  print(di);

  return 0;
}