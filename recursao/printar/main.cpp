#include <iostream>


void print(int a){
    std::cout << a << " "<<std::endl;
    if(a!=0){
        print(a-1);
    }else{
        return;
    }
    
    
}

int main(){
    int a= 10000;
    print(a);
    return 0;
}