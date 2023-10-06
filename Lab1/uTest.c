/* uTest.c --- 
 * 
 * Filename: testexample.c
 * Description: Testing Factorial and Fibonacci functions
 * Author: Lukas
 * Maintainer: 
 * Created: Thu Oct 28 10:16:11 2023 (+0100)
 * Last-Updated: Thu Oct 28 10:19:50 2023 (+0100)
 *           By: Lukas
 *     Update #: 3
 * 
 */

#include <stdio.h>
#include "minunit.h"
#include "stuff.c"

int tests_run = 0;

/*
*Factorial Test
*/
static char* test_factorial()
{
    mu_assert("error, factorial(3) != 6", factorial(3) == 6);
    return 0;
}

/*
*Fibonacci Test
*/
static char* test_fibonacci()
{
    mu_assert("error, fibonacci(4) != 7", fibonacci(4) == 7);
    return 0;
}

static char* all_tests() 
{
    mu_run_test(test_factorial);
    mu_run_test(test_fibonacci);
    return 0;
}

int main(int argc, char** argv) 
{
    char* result = all_tests();
    if (result != 0) 
    {
        printf("%s\n", result);
    }
    else 
    {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}