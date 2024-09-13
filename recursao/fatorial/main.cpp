#include <iostream>

int fac(int val){
    if(val == 1){
        return val;
    }
    return val * fac(val -1);
}

int main(){
    int val = 11;
    std::cout << fac(val) << std::endl;

    return 0;
}