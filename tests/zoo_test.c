#include "minunit.h"
#include "../src/zoo.h"

MU_TEST(test_price_for_age) {
    mu_check(getPriceForAge(50) == 30);
    mu_check(getPriceForAge(5) == 10);
    mu_check(getPriceForAge(70) == 60);
}

MU_TEST(test_tickets_valid) {
    mu_check(isNumberOfTicketsAllowed(-1, 5) == 0);
    mu_check(isNumberOfTicketsAllowed(6, 5) == 0);
    mu_check(isNumberOfTicketsAllowed(3, 5) == 1);
    mu_check(isNumberOfTicketsAllowed(5, 5) == 1);
}

MU_TEST(test_total_price_multiple_ages) {
    int ages[] = {10, 30, 70};
    mu_check(calculateTotalPrice(ages, 3) == (10 + 30 + 60));
}

MU_TEST(test_total_price_single_ticket) {
    int ages[] = {50};
    mu_check(calculateTotalPrice(ages, 1) == 30);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_price_for_age);
    MU_RUN_TEST(test_tickets_valid);
    MU_RUN_TEST(test_total_price_multiple_ages);
    MU_RUN_TEST(test_total_price_single_ticket);
}

int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}