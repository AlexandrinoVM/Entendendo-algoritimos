#include <iostream>
#include <vector>


int contarNumero(std::vector<int>arr,int total){
    if(arr.empty()){
        return 0;
    }else if(arr.size() == 1){
        return total+1;
    }
    arr.erase(arr.begin());
    total+=1;
    return contarNumero(arr,total);
  
}

int main(){

    std::cout << contarNumero({1,2,3,4,5,1,12,2},0) << std::endl;
    return 0;
}