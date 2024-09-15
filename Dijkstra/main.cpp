#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <vector>


using namespace std;

void adicionar(map<string,map<string,int>>&grafo,string indice,string parente,int valor){
    grafo[indice][parente] = valor;
}



void adicionarCustos(map<string,map<string,int>>&grafo,map<string,int>&custos){
    for(const auto&vertex: grafo){
        for(const auto&parentes : vertex.second){
            custos[parentes.first] = parentes.second;
        }
    }
}

void adicionarPais(map<string,map<string,int>>&grafo,map<string,string>&pais){
    for(const auto&vertex: grafo){
        for(const auto&parentes : vertex.second){
            pais[parentes.first] = vertex.first;
        }
    }
}

string acharMenorValor(map<string,int>&custos){
    int menorValor = numeric_limits<int>::max();
    string aux;
    for(const auto& vertex:custos){
        if(vertex.second < menorValor){
            aux = vertex.first;
            menorValor = vertex.second;
        }
    }
    return  aux;
}

void percorrer(map<string,int>&custos,map<string,map<string,int>>&grafo,map<string,string>&pais,vector<string>&preocessados){
    string menor = acharMenorValor(custos);
    int custo = 0;
    int novoCusto = 0;
    map<string,int>vizinhos;
    while (!menor.empty()){
        custo = custos[menor];
        vizinhos  =grafo[menor];
        for(auto& vertex: vizinhos){
            novoCusto = custo + vertex.second;
            if(custos[vertex.first] > novoCusto){
                custos[vertex.first] = novoCusto;
                pais[vertex.first] = menor;
            }
        }  
        preocessados.push_back(menor);
        custos[menor] = numeric_limits<int>::max(); 
        menor = acharMenorValor(custos);
    }
    cout << novoCusto;

}

int main(){
    double a = std::numeric_limits<double>::infinity();
    map<string,map<string,int>>grafo;
    map<string,int>custos;
    map<string,string>pais;
    map<string,int>vizinhos;

    vector<string> preocessados;

    adicionar(grafo,"inicio","a",6);
    adicionar(grafo,"inicio","b",2);
    adicionar(grafo,"a","fim",1);
    adicionar(grafo,"b","a",3);
    adicionar(grafo,"b","fim",5);

    adicionarCustos(grafo,custos);
    adicionarPais(grafo,pais);
    percorrer(custos,grafo,pais,preocessados);



    return 0;
}