#include <iostream>
#include <map>
#include <string>

using namespace std;

void adicionar(map<string,map<string,string>>&mapa,string indice,string chave,string value){
    mapa[indice][chave] = value;
}

void printar(map<string,map<string,string>>&mapa){
    for(const auto &vertex : mapa){
        for(const auto &child : vertex.second){
            cout <<"index " << vertex.first << " parente de "<< child.first << " valor de " << child.second << endl;
        }
    }
}

void procurar(map<string,map<string,string>>& mapa){
    auto &verificado = mapa;
    for(const auto &vertex : mapa){
        for(const auto &child : vertex.second){
            if(verificado[vertex.first][child.first] != "verificado"){
                if(child.second == "sim"){
                    cout << "nome do index " << vertex.first << " nome do index " << child.first << endl;
                    
                }else{
                    verificado[vertex.first][child.first] = "verificado";
                }
            }
            
        }
        
    }
    printar(verificado);

}


int main(){

    map<string,map<string,string>> principal;
    adicionar(principal,"voce","alice","nao");
    adicionar(principal,"voce","bob","nao");
    adicionar(principal,"voce","claire","nao");
    adicionar(principal,"claire","robson","nao");
    adicionar(principal,"robson","bob","sim");
    printar(principal);
    cout << endl;
    procurar(principal);
    return 0;
}