#include <iostream>
#include <vector>



int somaArray(std::vector<int> arr){
    int total = arr[0];
    if(arr.size() == 1){
        return arr[0];
    }else if(arr.empty() == 0){
        return 0;
    }
    arr.erase(arr.begin());
    return total += somaArray(arr);

}


int main(){
    std::cout <<"soma " <<somaArray({1,2,3,4,5})<<std::endl;

    return 0;
}
