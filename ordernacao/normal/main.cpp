#include <iostream>
#include <vector>

int buscarMenor(std::vector<int> arr){
        int menor = arr[0];
        int menor_indice = 0;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] < menor){
                menor = arr[i];
                menor_indice = i;
            }
        }
        return menor_indice;
}

void ordenarArr(std::vector<int> arr,int tamanho){
    int menor = 0;
    std::vector<int> aux;
    aux.reserve(tamanho);
    for(int i=0;i <tamanho;i++){
        menor = buscarMenor(arr);
        aux.push_back(arr[menor]);
        arr.erase(arr.begin() + menor);

        std::cout << aux[i] << std::endl;

    }
}


int main(){
    std::vector<int> vec={5,2,3,4,1,7};

    ordenarArr(vec,6);
    return 0;
}