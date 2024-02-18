#include<iostream>
using namespace std;
int main(){
    int a, b;
    while (cin >> a >> b){
        try{
            if (b == 0)
                throw runtime_error("The divided number should not be 0!");
            cout << a / b;
        }
        catch(runtime_error err){
            cout << err.what()
                 << "\nTry again? Enter y or n" << endl; 
            char c;
            cin >> c;
            if (!c || c == 'n'){
                break;
            }
        }    
    }

}