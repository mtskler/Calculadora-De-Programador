#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Encoding: Western (Windows 1252)

void decimalParaBinario(int n);
void calculoBasico(int escolhaCalc);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char hex[20];
    char octa[20]; 
    int oper = 0;
    int num = 0;
    printf("\nEscolha o tipo de cálculo:\n\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("5 - Converter para hexadecimal\n");
    printf("6 - Converter para octal\n");
    printf("7 - Converter para binário\n\n");
    printf("-> ");
    scanf("%d", &oper);

    if (oper == 1 || oper == 2 || oper == 3 || oper == 4)
    {
        calculoBasico(oper);
    }
    
    else if (oper == 5 || oper == 6 || oper == 7)
    {
        printf("\nDigite o número para converter: ");
        while (getchar() != '\n');
        scanf("%d", &num);
        switch (oper)
        {
            case 5:
                sprintf(hex, "%X", num);
                printf("\nHexadecimal: %s\n\n", hex);
                break;

            case 6:
                sprintf(octa, "%o", num);
                printf("\nOctal: %s\n\n", octa);
                break;

            case 7:
                decimalParaBinario(num);
                break;

            default:
                break;
        }
    }
    else {
        printf("\nOpção inválida\n\n");
    }
    
}

void decimalParaBinario(int n) 
{ 
	int numBinario[32]; 
	int i = 0; 
	while (n > 0) { 
		numBinario[i] = n % 2; 
		n = n / 2; 
		i++; 
	} 

	for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", numBinario[j]);   
    } 
}

void calculoBasico(int escolhaCalc)
{
    float n1, n2;
    while (getchar() != '\n');
    printf("\nPrimeiro número: ");
    scanf("%f", &n1);
    printf("\nSegundo número: ");
    scanf("%f", &n2);
    switch (escolhaCalc)
    {
        case 1:
            printf("\n%.2f + %.2f = %.2f\n\n", n1, n2, n1 + n2);
            break;
        case 2:
            printf("\n%.2f - %.2f = %.2f\n\n", n1, n2, n1 - n2);
            break;
        case 3:
            printf("\n%.2f x %.2f = %.2f\n\n", n1, n2, n1 * n2);
            break;
        case 4:
            if (n2 != 0)
            {
                printf("\n%.2f / %.2f = %.2f\n\n", n1, n2, n1 / n2);
            }
            else {
                printf("\nErro: divisão por zero.\n\n");
            }
            break;
        default:
            break;
    }
}
