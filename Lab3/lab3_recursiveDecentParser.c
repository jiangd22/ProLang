/* Lab 3A: Simple recursive descent parser 
 * BNF grammar:
 *   <expr> -> <term> 
 *           | <expr> + <term> 
 *   <term> -> <factor> 
 *           | <term> * <factor>  
 *   <factor> -> digit  
 *
 *Assignment:    
 *Add logic for the following BNF grammar:
 *   <expr> -> <term> 
 *           | <expr> + <term> 
 *           | <expr> - <term> 
 *   <term> -> <factor> 
 *           | <term> * <factor>  
 *           | <term> / <factor> 
 *   <factor> -> digit | (<expr>) 
 * 
 * in EBNF grammar:
 *    <expr> -> <term> {(+ | -) <term>} 
 *    <term> -> <factor> {(* | /) <factor>}  
 *    <factor> -> digit | (<expr>) 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int parseExpr();
int parseTerm();
int parseFactor();

char *x; //make the input string global for simplicity


int main()
{

    //input strings
    //x = "2*3+4*5"; //test 1 - before change = 26,  x:26
    //x = "k2*3+4*5";        //test 2 - for error message x:error
    //x = "8/2-1*3";         //test 3 - for / and -  x:1
    //x = "8/(4-2)";         //test 4 - for () x:4
    //x = "8*(4-2)+7";       //test 5 - for checking whole logic x:23

    printf("Please enter a math expression. \n");  //- Add logic for this.
    char y[100];
    scanf("%s", y);
    x = y;
    //scanf("%[^\\n]s", x); //get input string

    printf("The input expression : %s\n", x);
    int result = parseExpr();
    printf("**Parsing successful! \n");
    printf("result = %d\n", result);
}

int parseExpr()
{
    printf("Enter Expression : digit is %c\n", *x);
    int product1 = parseTerm();
    while (*x == '+')
    {
        ++x;
        int product2 = parseTerm();
        printf("product1 + product2 : %d + %d = %d \n", product1, product2, product1 + product2);
        product1 = product1 + product2;
    }
    while (*x == '-')
    {
        ++x;
        int product2 = parseTerm();
        printf("product1 - product2 : %d - %d = %d \n", product1, product2, product1 - product2);
        product1 = product1 - product2;
    }

    return product1;
}

int parseTerm()
{
    printf("Enter Term : digit is %c\n", *x);
    int factor1 = parseFactor();
    while (*x == '*')
    {
        ++x;
        int factor2 = parseFactor();
        printf("factor1 * factor2 : %d * %d = %d\n", factor1, factor2, factor1 * factor2);
        factor1 = factor1 * factor2;
    }
    while (*x == '/')
    {
        ++x;
        int factor2 = parseFactor();
        printf("factor1 / factor2 : %d / %d = %d\n", factor1, factor2, factor1 / factor2);
        factor1 = factor1 / factor2;
    }

    return factor1;
}

int parseFactor()
{
    printf("Enter Factor: digit is %c\n", *x);
    if (*x >= '0' && *x <= '9')
    {
        int y = *x - '0';
        x++; //advance to next character.
        return y;
    } else if (*x == '(')
    {
        ++x;
        int y = parseExpr();
        if (*x == ')')
        {
            ++x;
            return y;
        } else
        {
            printf("Error: missing ) \n");
            exit(1);
        }
    } else
    {
        printf("Error: invalid digit found:%c \n", *x);
        exit(1);
    }
    
}