#include <iostream>
#include <map>
#include <string>

void votar(std::map<std::string,int>&votos){
    std::string auxnome;
    std::string existe;
    int voto;
    std::cout << "digite o nome da pessoa" << std::endl;
    std::cin  >> auxnome;
    if(votos.find(auxnome) != votos.end()){
        std::cout<<"ja votou"<<std::endl;
        return;
    }else{
        std::cout << "nome não existe na lista, liberado para votar"<<std::endl;
        std::cout << "digite 2 para votar no candidato 1"<<std::endl;
        std::cout << "digite 2 para votar no candidato 2"<<std::endl;
        std::cin >> voto;
        while(voto != 1 && voto != 2){
           std::cout << "digite um candidato valido"<<std::endl; 
           std::cin >> voto;
        }
        votos[auxnome] = voto;
    }
}

void printar(std::map<std::string,int>&votos){
    std::map<std::string,int>::iterator iterator;
    for(iterator=votos.begin();iterator!=votos.end();iterator++){
        std::cout << iterator->first << " => " << iterator->second << std::endl;
    }
}

int main(){
    std::map<std::string,int> votaram;
    while(1){
        int escolha;
        std::cout << "1 para votar:" << std::endl;
        std::cout << "2 para imprimir votos:" << std::endl;
        std::cout << "3 para sair:" << std::endl;
        std::cin >> escolha;
        switch (escolha)
        {
        case 1:
            votar(votaram);
        case 2:
            printar(votaram);
        case 3:
            break;
        }
    }

    return 0;
}