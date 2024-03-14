#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rotacaoDireita(long long int *k, int n, int digitos);
int rotacaoEsquerda(long long int *k, int n, int digitos);
int insercaoInicio(long long int *k, int n, int digitos);
int insercaoFim(long long int *k, int n, int digitos);



int main(){

    long long int k, aux;
    int n, invalido, alteracao, digitos;
    char op;

    do{
        invalido = 0;
        printf("Valor de K: ");
        scanf("%lld", &k);

        if (k < 100 || k > 9999999999){
            invalido = 1;
            printf("Valor invalido! Insira novamente:\n");
        }
        
    }
    while (invalido);

    //Determinar digitos
    
    digitos = 0;
    aux = k;
    while (aux)
    {
        aux /= 10;
        digitos++;
    }

    //

    do{
        do{
        
        invalido = 0;
        fflush(stdin);
        printf("Operacao: ");
        scanf("%c", &op);        
        
        switch (op){
            case 'd': op = 'D'; break;
            case 'e': op = 'E'; break;
            case 'i': op = 'I'; break;
            case 'f': op = 'F'; break;
            case 't': op = 'T'; break;
            default: break;
 
        }
        
        
        if (op != 'D' && op != 'E' && op != 'I' && op != 'F' && op != 'T'){
            invalido = 1;
            printf("Operacao invalida! Insira novamente:\n");
        }

        if (op == 'T')
            return 0;
        
        scanf("%d", &n);

    }while (invalido);


    switch(op){
        case 'D': alteracao = rotacaoDireita(&k, n, digitos); break;
        case 'E': alteracao = rotacaoEsquerda(&k, n, digitos); break;
        case 'I': alteracao = insercaoInicio(&k, n, digitos); break;
        case 'F': alteracao = insercaoFim(&k, n, digitos); break;
        default: return 0;

    }

    if (alteracao){
        digitos = 0;
        aux = k;
        while (aux)
        {
            aux /= 10;
            digitos++;
        }
        if (digitos < 3){
            printf("%03lld\n", k);
            digitos = 3;
        }
        else
            printf("%lld\n", k);
    }
        
        
        
        
    else
        printf("ERRO: nao foi possivel executar a operacao!\n");

    
    }while (op != 'T');


    

    return 0;
}

int rotacaoDireita(long long int *k, int n, int digitos){
    
    if (n < 0)
        return 0;
    else{
        int expoente = digitos - n;
        double potencia = powl(10, n);
        long long esquerda = *k / potencia;
        long long direita = *k % (long long)potencia;
        long long resultado = (direita * powf(10, expoente)) + esquerda;
        *k = resultado;
        return 1;
    }

}
int rotacaoEsquerda(long long int *k, int n, int digitos){
    
    if (n < 0)
        return 0;
    else{
        int expoente = digitos - n;
        double potencia = powl(10, expoente);
        long long esquerda = *k / potencia;
        long long direita = *k % (long long)potencia;
        long long resultado = (direita * powf(10, n)) + esquerda;
        *k = resultado;
        return 1;
    }
}
int insercaoInicio(long long int *k, int n, int digitos){

    if (n < 0 || n > 9)
        return 0;
    else{
        double potencia = powl(10, digitos-1);
        long long esquerda = *k / 10;
        long long resultado = esquerda + (n * potencia);
        *k = resultado;
        return 1;
    }

}
int insercaoFim(long long int *k, int n, int digitos){
    
    if (n < 0 || n > 9)
        return 0;
    else{
        double potencia = powl(10, digitos-1);
        long long direita = *k % (long long)potencia;
        long long resultado = n + (direita * 10);
        *k = resultado;
        return 1;
    }
}


