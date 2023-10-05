#include <stdio.h>
#include "minunit.h"
#include "stdlib.h"
#include "DLinkList.h"

int tests_run = 0;

static char* test_create()
{
    DLList * myList = createDLList();
    mu_assert("error - size not initialised", 0==size(myList));
    free(myList);
    return 0;
}

static char* test_size()
{
    DLList * myList = createDLList();
    push(myList, 1);
    mu_assert("error - size incorrect after push ", 1==size(myList));
    insertAfter(myList,2);
    mu_assert("error - size incorrect after insertAfter ", 2==size(myList));
    insertBefore(myList,3);
    mu_assert("error - size incorrect after insertBefore ", 3==size(myList));
    deleteCurrent(myList);
    mu_assert("error - size incorrect after deleteCurrent ", 2==size(myList));
    pop(myList);
    mu_assert("error - size incorrect after pop ", 1==size(myList));
    free(myList);
    return 0;
}

static char* test_push()
{
    DLList * myList = createDLList();
    
}

static char* test_pop()
{

}

static char* test_getCurrent()
{

}

static char* test_first()
{

}

static char* test_next()
{
    
}

static char* test_atEnd()
{
    mu_assert("error - atEnd ", true == atEnd(myList));
    return 0;
}

static char* test_deleteCurrent()
{
    
}

static char* test_insertAfter()
{
    
}

static char* test_insertBefore()
{
    
}

static char* test_printList()
{

}

static char* all_tests() 
{
    mu_run_test(test_create);
    mu_run_test(test_size);
    mu_run_test(test_push);
    mu_run_test(test_pop);
    mu_run_test(test_getCurrent);
    mu_run_test(test_first);
    mu_run_test(test_next);
    mu_run_test(test_atEnd);
    mu_run_test(test_deleteCurrent);
    mu_run_test(test_insertAfter);
    mu_run_test(test_insertBefore);
    mu_run_test(test_printList);
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