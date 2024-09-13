#include <iostream>
#include <vector>

int maiorValor(std::vector<int> arr){
    if(arr.empty()){
        return 0;
    }else if(arr.size() == 1){
        return arr[0];
    }
    
    std::vector<int> subarray(arr.begin()+1,arr.end());
    int maior = maiorValor(subarray);
    return std::max(arr[0],maior);
}

int main(){
    std::cout << "maior " << maiorValor({1,5,7,9,15,2}) << std::endl;
    return 0;
}