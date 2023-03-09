#include <cstdio>
#include <cstring>

// Global Variables
int stack_position = 0,
stack_ptr = 0,
in_str_ptr = 0,
input_len = 0;

char in_str[16], //input string
     stk[15];    //stack
void check()
{
    // begin with checking stack_ptr first.
    for(stack_position = 0; stack_position < input_len; stack_position++) {
        // checking stack for producing rule F->i
        if (stk[stack_position] == 'i') {
            printf("REDUCE TO F -> i");
            stk[stack_position] = 'F';
            stk[stack_position + 1] = '\0';

            //printing stack info
            printf("\n$%s\t%s$\t", stk, in_str);
        }
    }
    for(stack_position = 0; stack_position < input_len - 2; stack_position++) {
        if (stk[stack_position] == 'F') {
            if (stk[stack_position - 2] == 'T' && stk[stack_position - 1] == '*') {
                printf("REDUCE TO T -> T * F");
                stk[stack_position] = '\0';
                stk[stack_position - 1] = '\0';
                stack_ptr -= 2;
                printf("\n$%s\t%s$\t", stk, in_str);
                break;
            }
            printf("REDUCE TO T -> F");
            stk[stack_position] = 'T';
            stk[stack_position + 1] = '\0';

            //printing stack info
            printf("\n$%s\t%s$\t", stk, in_str);
        }
    }
    for (stack_position = 0; stack_position < input_len - 1; stack_position++) {
        if (stk[stack_position] == 'T') {
            if (stk[stack_position - 2] == 'T' && stk[stack_position - 1] == '+') {

                printf("REDUCE TO E -> T + T");
                stk[stack_position] = '\0';
                stk[stack_position - 1] = '\0';
                stk[stack_position - 2] = 'E';
                stack_ptr -= 2;
                printf("\n$%s\t%s$\t", stk, in_str);
                break;
            }
        }

    }


    return ; // return to main
}

int main()
{
    printf("GRAMMAR is -\nE  -> T + T | T \nT ->  T * F | F \nF ->  i\n");

    strcpy(in_str,"i*i+i");
    printf("Input string is: %s\n", in_str);
    // strlen(in_str) will return the length of in_str
    input_len =strlen(in_str);
    // This will print Lables (column name)
    printf("\nStack    Input  Action");
    // This will print the initial values of stack and input
    printf("\n$\t%s$\t", in_str);   //stack = $

    // This will run up to length of input string
    for(stack_ptr = 0; in_str_ptr < input_len; stack_ptr++, in_str_ptr++)
    {
        printf("SHIFT");   //start with SHIFT
        // Shift- pushing into stack
        stk[stack_ptr] = in_str[in_str_ptr];
        stk[stack_ptr + 1] = '\0';  //'0' is end of string

        // Remove char from in_str - make it blank
        in_str[in_str_ptr]=' ';

        // Printing action
        printf("\n$%s\t%s$\t", stk, in_str);
        //check the stack to see if it contains any production rules
        check();
    }

    // if top of the stack is E(starting symbol, then it will accept the input
    if(stk[0] == 'E' && stk[1] == '\0')
        printf("Accept\n");
    else //else reject
        printf("Reject\n");
}