#include <stdio.h>
#include <stdlib.h>
#include "zoo.h"

#define MAX_NUMBER_OF_TICKETS_ALLOWED 5

int main()
{
    while(1){
        int option;
        printf("Iniciar venda (1) - Fechar (2): ");
        scanf("%d", &option);
        
        if (option != 1){
            printf("Finalizado!");
            return 0;
        }
        
        int numberOfTickets;
        printf("\nDigite a quantidade de bilhetes: ");
        scanf("%d", &numberOfTickets);

        if (!isNumberOfTicketsAllowed(numberOfTickets, MAX_NUMBER_OF_TICKETS_ALLOWED)){
            printf("Quantidade de bilhetes não permitida!");
            return 0;
        }

        int *ages = malloc(numberOfTickets * sizeof(int));
        
        for (int i = 0; i < numberOfTickets; i++){
            printf("Digite a idade da pessoa portadora do bilhete %d: ", i + 1);
            scanf("%d", &ages[i]);
        }

        int totalPrice = calculateTotalPrice(ages, numberOfTickets);
        
        printf("\nValor total dos bilhetes: %d\n\n", totalPrice);

        free(ages);
    }
    return 0;
}
