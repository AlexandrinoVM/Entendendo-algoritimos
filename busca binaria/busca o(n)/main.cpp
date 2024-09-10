#include <iostream>

int busca(int arr[],int tamanho,int x){
    for(int i=0;i<tamanho;i++){
        if(arr[i] == x){
            return i;
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

    std::cout << busca(arr,1000,999) << std::endl;

    delete[] arr;
    
    return 0;
}