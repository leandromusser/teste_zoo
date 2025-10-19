#include "zoo.h";

int isNumberOfTicketsAllowed(int numberOfTickets, int maxTickets) {
    if (numberOfTickets <= 0) return 0;
    return numberOfTickets <= maxTickets;
}

double getPriceForAge(int age){
    if (age <= 12)
        return 10;
    else if (age <= 59)
        return 30;
    else
        return 60;
}

int calculateTotalPrice(const int *ages, int numberOfTickets) {
    int totalValue = 0;
    for (int i = 0; i < numberOfTickets; i++) {
        totalValue += getPriceForAge(ages[i]);
    }
    return totalValue;
}