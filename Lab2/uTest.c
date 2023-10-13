#include <stdio.h>
#include "minunit.h"
#include "stdlib.h"
#include "DLinkedList.h"

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
    mu_assert("error - (size) incorrect after push ", 1==size(myList));
    insertAfter(myList,2);
    mu_assert("error - (size) incorrect after insertAfter ", 2==size(myList));
    insertBefore(myList,3);
    mu_assert("error - (size) incorrect after insertBefore ", 3==size(myList));
    deleteCurrent(myList);
    mu_assert("error - (size) incorrect after deleteCurrent ", 2==size(myList));
    pop(myList);
    mu_assert("error - (size) incorrect after pop ", 1==size(myList));
    free(myList);
    return 0;
}

static char* test_push()
{
    DLList * myList = createDLList();
    push(myList, 1);
    //mu_assert("error - (push) incorrect after push", 1==push(myList));
    mu_assert("error - (push) incorrect", 0 == push(myList, 1));
    free(myList);
    return 0;
}

static char* test_pop()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (pop) incorrect after push", 1==pop(myList));
    push(myList, 2);
    mu_assert("error - (pop) incorrect after 2nd push", 2==pop(myList));
    pop(myList);
    mu_assert("error - (pop) incorrect after pop", 1==pop(myList));
    free(myList);
    return 0;
}

static char* test_getCurrent()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (getCurrent) incorrect after push", 1==getCurrent(myList));
    getCurrent(myList, 1);
    mu_assert("error - (getCurrent) incorrect after getCurrent", 1==getCurrent(myList));
    free(myList);
    return 0;
}

static char* test_first()
{
    DLList *myList = createDLList();
    push(myList, 1);
    first(myList);
    mu_assert("error - (first) incorrect after first", 1 == getCurrent(myList));
    free(myList);
    return 0;
    
}

static char* test_next()
{
     DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (next) incorrect after push", 1==next(myList));
    push(myList, 2);
    mu_assert("error - (next) incorrect after push", 1==next(myList));
    first(myList);
    next(myList);
    mu_assert("error - (next) inccorect after next", 2==next(myList));
    free(myList);
    return 0;
}

static char* test_atEnd()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (atEnd) incorrect after push", 1==atEnd(myList));
    push(myList, 2);
    mu_assert("error - (atEnd) incorrect after push", 1==atEnd(myList));
    first(myList);
    mu_assert("error - (atEnd) incorrect after first", 1==atEnd(myList));
    next(myList);
    mu_assert("error - (atEnd) incorrect after next", true==atEnd(myList));
    next(myList);
    mu_assert("error - (atEnd) incorrect after next", true==atEnd(myList));
    free(myList);
    return 0;
}

static char* test_deleteCurrent()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (deleteCurrent) incorrect after push", 1==deleteCurrent(myList));
    deleteCurrent(myList);
    mu_assert("error - (deleteCurrent) incorrect after deleteCurrent", 0==deletCurrent(myList));
    free(myList);
    return 0;
}

static char* test_insertAfter()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (insertAfter) incorrect after push", 1==insertAfter(myList));
    //mu_assert("error - (insertAfter) failed", 0 == insertAfter(myList, 2));
    insertAfter(myList, 2);
    mu_assert("error - (insertAfter) incorrect after insertAfter", 2==insertAfter(myList));
    free(myList);
    return 0;
}

static char* test_insertBefore()
{
    DLList *myList = createDLList();
    push(myList, 1);
    mu_assert("error - (insertBefore) incorrect after push", 2==insertBefore(myList));
    //mu_assert("error - (insertBefore) failed", 0 == insertBefore(myList, 2));
    insertBefore(myList, 2);
    mu_assert("error - (insertBefore) incorrect after insertBefore", 2==insertBefore(myList));
    free(myList);
    return 0;
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
