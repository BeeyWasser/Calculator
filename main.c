#include <stdio.h> /* Importando as bibliotecas necessárias */
#include <stdlib.h>

int main(void) { /* Função principal, void palavra-chave em C que indica que a função não retorna nenhum valor, e declaro a variável da opção em int */
    int opcao;  
    while (1) { /* Um loop infinito para exibir o menu e processar as operações */
        printf("================================\n");
        printf("   Calculadora Simples\n");
        printf("================================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Opção:\n");

        if (scanf("%d", &opcao) != 1) { /* Se a leitura do scanf falhar, limpa o buffer e pede novamente */
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Opção inválida! Por favor, selecione uma opção válida de 1 a 5.\n");
            continue;
        }

        if (opcao < 1 || opcao > 5) { /* Se a opção for menor ou maior que 1 e 5, imprimo o aviso e retorna o loop.*/
            printf("Opção inválida! Por favor, selecione uma opção válida de 1 a 5.\n");
            continue;
        }

        if (opcao == 5) { /* Se a opção for 5, sai do programa (ele quebra com break) */
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            break;
        }

        double num1, num2, resultado; /* Declaração das variáveis para os números e o resultado, double pra permitir números com casas decimais e inteiros.*/

        printf("Digite o primeiro número: ");
        if (scanf("%lf", &num1) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida.\n");
            continue;
        }

        printf("Digite o segundo número: ");
        if (scanf("%lf", &num2) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida.\n");
            continue;
        }

        if (opcao == 1) { /* Adição */
            resultado = num1 + num2;
            printf("Resultado: %lf + %lf = %lf\n", num1, num2, resultado);
        }

        if (opcao == 2) { /* Subtração */
            resultado = num1 - num2;
            printf("Resultado: %lf - %lf = %lf\n", num1, num2, resultado);
        }

        if (opcao == 3) { /* Multiplicação */
            resultado = num1 * num2;
            printf("Resultado: %lf * %lf = %lf\n", num1, num2, resultado);
        }

        if (opcao == 4) { /* Divisão */
            if (num2 == 0) {
                printf("Erro: Divisão por zero não é permitida.\n"); /* se o num2 for zero, n é possível realizar a divisão, senão, efetuo a divisão normal */
            } else { 
                resultado = num1 / num2;
                printf("Resultado: %lf / %lf = %lf\n", num1, num2, resultado); 
            }
        }

        while (1) {
            char resp;
            printf("Deseja realizar outra operação? (s/n): "); /* Enquanto a resposta for inválida, continua pedindo, mas se for certa, ele volta pro menu principal ou quebra.*/
            scanf(" %c", &resp);

            if (resp == 's' || resp == 'S') {
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                break;
            } else if (resp == 'n' || resp == 'N') {
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                return 0;
            } else {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }
    }

    return 0;
}
