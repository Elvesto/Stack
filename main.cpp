#include <stdio.h>

#include <assert.h>
#include <malloc.h>

#include "log.h"
#include "stack_t.h"

int main() {
    openLog("dumps.txt");
    
    Stack stack = {};
    StackError err = OK;

    err = stackInit(&stack, 30);
    if (err) {
        perror("TEXT_CREATE_ERROR");
        return err;
    }

    stackPush(&stack, 5);
    stackPush(&stack, 10);
    int temp = stackPop(&stack);
    printf("%d\t%d\n", temp, stackPop(&stack));

    // for (int i = 0; i < instructions.capacity; i++)
    //     printf("%d\n", instructions.data[i]);

    err = stackDestroy(&stack);
    if (err) {
        perror(errorToString(err));
        return PTR_ERROR;
    }    
    closeLog();
}