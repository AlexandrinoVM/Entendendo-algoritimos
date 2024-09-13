#include <iostream>
#include <vector>




int pesquisaBinaria(std::vector<int>arr,int fim,int inicio,int valor){
    if(inicio > fim){
        return -1;
    }
    int meio = inicio + (fim - inicio)/2;

    if(valor == arr[meio]){
        return meio;
    }else if(arr[meio] < valor){
        return pesquisaBinaria(arr,fim,meio+1,valor);
    }else{
         return pesquisaBinaria(arr,meio-1,inicio,valor);
    }
    

}

int main(){
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    std::cout << "existe " << pesquisaBinaria(arr,arr.size()-1,0,8) << std::endl;

    return 0;
}