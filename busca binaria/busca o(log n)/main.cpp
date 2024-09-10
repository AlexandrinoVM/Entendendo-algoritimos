#include <iostream>

int busca(int arr[],int tamanho,int busca){
    int comeco = 0;
    int fim = tamanho -1;
    
    while(comeco <= fim){
        int aux = (comeco + fim) /2;
        int meio = arr[aux];
        if(meio == busca){
            return meio;
        }else if(meio<busca){
            comeco = aux + 1;
        }else{
            fim = aux -1;
        }
    }
    return -1;

}



int main(){
    //inicializando o arry com 1000 posições
    int *arr =new  int[1000];
    //populando o array
    for(int i=0;i<1000;i++){
        arr[i] = i;
    }

    std::cout << busca(arr,1000,1) << std::endl;

    delete[] arr;
    
    return 0;
}