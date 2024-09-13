#include <iostream>
#include <vector>


std::vector<int> quicksort(std::vector<int>arr){
    if(arr.empty()){
        return arr;
    }else if(arr.size()==1){
        return arr;
    }
    int pivo = arr[0];
    arr.erase(arr.begin());
    std::vector<int> menores;
    std::vector<int> maiores;
    for(int i=0;i<arr.size();i++){
        if(pivo < arr[i]){
             maiores.push_back(arr[i]);
        }else{
            menores.push_back(arr[i]);
        }
    }
    menores = quicksort(menores);
    maiores = quicksort(maiores);

    std::vector<int> resultado = menores;
    resultado.push_back(pivo);
    resultado.insert(resultado.end(),maiores.begin(),maiores.end());
    return resultado;
    
}


int main(){
    std::vector<int> ordenado = quicksort({5,7,8,13,1,0,15,25});

    for(int i=0;i<ordenado.size();i++){
        std::cout << ordenado[i] << "->";
    }
    return 0;
}