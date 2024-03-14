#include <stdio.h>
#include <stdlib.h>

void lerFuncionario(char *funcao, int *anosExperiencia, int *horasContratadas, int *horasTrabalhadas);
float calcularSalario(char funcao, int anosExperiencia, int horasContratadas, int horasTrabalhadas, float *salarioBruto, int *horasExcedentes, float *descontoInss, float *descontoIr);
void imprimirFolhaPagamento(float salarioBruto, int horasExcedentes, float descontoInss, float descontoIr, float salarioLiquido);

int main(){

    char funcao;
    int anosExperiencia, horasContratadas, horasTrabalhadas, horasExcedentes;
    float salarioBruto, descontoInss, descontoIr, salarioLiquido;
    
    int qtd;
    do{
        printf("Qtd: ");
        scanf("%d", &qtd);
        if (qtd < 1){
            printf("Valor inválido! Insira uma quantidade igual ou superior a 1.\n");
        }

    }while(qtd < 1);
    for(int i = 1; i <= qtd; i++){
        
        
        printf("============\n");
        printf("Funcionario %d\n", i);
        lerFuncionario(&funcao, &anosExperiencia, &horasContratadas, &horasTrabalhadas);
        salarioLiquido = calcularSalario(funcao, anosExperiencia, horasContratadas, horasTrabalhadas, &salarioBruto, &horasExcedentes, &descontoInss, &descontoIr);
        printf("Folha de pagamento do Func. %d\n", i);
        imprimirFolhaPagamento(salarioBruto, horasExcedentes, descontoInss, descontoIr, salarioLiquido);


    }
    
    

    return 0;
}

void lerFuncionario(char *funcao, int *anosExperiencia, int *horasContratadas, int *horasTrabalhadas){

    
    do{
        fflush(stdin);
        printf("- Funcao: ");
        scanf("%c", &*funcao);
        if (*funcao != 'p' && *funcao != 'P' && *funcao != 'g' && *funcao != 'G' && *funcao != 'a' && *funcao != 'A'){
            printf("Funcao invalida! Insira novamente: \n");
        }
    }while(*funcao != 'p' && *funcao != 'P' && *funcao != 'g' && *funcao != 'G' && *funcao != 'a' && *funcao != 'A');
    
    do
    {
        printf("- Anos de Exp.: ");
        scanf("%d", &*anosExperiencia);
        if (*anosExperiencia < 0){
            printf("Valor invalido! insira novamente:\n");
        }
    } while (*anosExperiencia < 0);
    
    do
    {
        printf("- Horas contratadas: ");
        scanf("%d", &*horasContratadas);
        if (*horasContratadas < 0){
            printf("Valor invalido! insira novamente:\n");
        }
    } while (*horasContratadas < 0);
    
    do
    {
        printf("- Horas trabalhadas: ");
        scanf("%d", &*horasTrabalhadas);
        if (*horasTrabalhadas < 0){
            printf("Valor invalido! insira novamente:\n");
        }
    } while (*horasTrabalhadas < 0);
    
}

float calcularSalario(char funcao, int anosExperiencia, int horasContratadas, int horasTrabalhadas, float *salarioBruto, int *horasExcedentes, float *descontoInss, float *descontoIr){

    int valHora;
    *horasExcedentes = 0;
    
    if(funcao == 'p')
        funcao = 'P';
    else if (funcao == 'a')
        funcao = 'A';
    else if (funcao == 'g')
        funcao = 'G';
    
    
    if(funcao == 'P'){
        
        if(anosExperiencia <= 2)
            valHora = 25;
        else if(anosExperiencia <= 5)
            valHora = 30;
        else
            valHora = 38;
        
        
    }
    else if (funcao == 'A'){ 
        
        if(anosExperiencia <= 2)
            valHora = 45;
        else if(anosExperiencia <= 5)
            valHora = 55;
        else
            valHora = 70;

    }
    else{ // GERENTE

        if(anosExperiencia <= 2)
            valHora = 85;
        else if(anosExperiencia <= 5)
            valHora = 102;
        else
            valHora = 130;     
    }

    *salarioBruto = valHora * horasTrabalhadas;
    if (horasTrabalhadas > horasContratadas)
        *horasExcedentes = horasTrabalhadas - horasContratadas;

    
    if(*horasExcedentes <= 13)
        *salarioBruto += 0.23 * (*horasExcedentes * valHora);
    else if(*horasExcedentes <= 22)
        *salarioBruto += 0.37 * (*horasExcedentes * valHora);
    else
        *salarioBruto += 0.56 * (*horasExcedentes * valHora);


    *descontoInss = 0.11 * *salarioBruto;


    if((*salarioBruto - *descontoInss) > 1500){
        if ((*salarioBruto - *descontoInss) <= 2700)
            *descontoIr = 0.15 * (*salarioBruto - *descontoInss);
        else if ((*salarioBruto - *descontoInss) <= 4200)
            *descontoIr = 0.20 * (*salarioBruto - *descontoInss);
        else
            *descontoIr = 0.30 * (*salarioBruto - *descontoInss);
    }
    else
        *descontoIr = 0;

    return *salarioBruto - *descontoInss - *descontoIr;

        
    
    


}

void imprimirFolhaPagamento(float salarioBruto, int horasExcedentes, float descontoInss, float descontoIr, float salarioLiquido){

    printf("- Salario Bruto...(R$): %.2f\n", salarioBruto);
    if (horasExcedentes)
        printf("- Horas excedentes (h): %d\n", horasExcedentes);
    printf("- Desconto INSS...(R$): %.2f\n", descontoInss);
    printf("- Desconto IR.....(R$): %.2f\n", descontoIr);
    printf("- Salario Liquido.(R$): %.2f\n", salarioLiquido);


}