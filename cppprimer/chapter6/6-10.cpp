#include<iostream>
using namespace std;
void swap1(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a,b;
    cin >> a >> b;
    swap1(&a,&b);
    cout << a << ' ' << b << endl;
    return 0;
}