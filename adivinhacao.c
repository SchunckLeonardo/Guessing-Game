//adiciona a biblioteca stdio.h para conseguir imprimir as coisas na tela
#include <stdio.h>

//Adiciona a biblioteca do abs
#include <stdlib.h>

//Adiciona a funcao time
#include <time.h>

int main(void) {

    // imprime cabeçalho do nosso jogo
        printf("********************************\n");
        printf("* Welcome to our guessing game * \n");
        printf("********************************\n");

    //criando uma variável para o número secreto
    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100;
    
    //criando uma variável para o chute do usuário
    int chute;

    //variavel para as tentativas
    int tentativas = 1;

    //variavel para os pontos do usuário
    double pontos = 1000;

    //Seleção de dificuldade
    int nivel;
    printf("What's the difficult level?\n");
    printf("(1) Easy (2) Medium (3) Hard\n\n");
    printf("Choose: ");
    scanf("%d", &nivel);

    //Variavel numero de tentativas
    int numeroDeTentativas;

    switch(nivel) {
        case 1:
            numeroDeTentativas = 20;
            break;

        case 2:
            numeroDeTentativas = 15;
            break;
        
        default:
            numeroDeTentativas = 6;
            break;
    }

    //Estrutura de repetição de acerto para o usuário
    for(int i = 1; i <= numeroDeTentativas; i++) {

        //imprimindo o chute do usuário
        printf("Attempt %d \n",tentativas);
        printf("What's your guess? ");
        scanf("%d", &chute);
        printf("Your guess was %d \n", chute);

        //Restringindo números negativos
        if(chute < 0) {
            printf("The game don't accept negative numbers!\n");

            //Para a execução do código, mas faz o for continuar
            continue;
        }

        //criando uma variável se o usuário acertou
        //Variáveis para executar a comparação
        //0 = false | 1 = true
        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        //Mostra se o usuário acertou ou errou o número secreto
        if(acertou) {
            printf("Congratulations! You're right! \n");

            //Parar a execução da repetição
            break;
        }

        //Faz a comparação para ver se o número é maior ou menor
        else if(maior) {
            printf("Your guess was bigger than Secret Number\n");
        } else {
            printf("Your guess was less than Secret Number\n");
        }
        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;//conversão de int para double
        pontos = pontos - pontosPerdidos;
    }

    int acertou = chute == numeroSecreto;

    printf("Game Over!\n");

    if(acertou) {
        printf("You win!\n");
        printf("You're right on %d attempts\n", tentativas);
        printf("Total Points: %.2f \n", pontos);
    } else {
        printf("You lose! Try again!");
    }
}