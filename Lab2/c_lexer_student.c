//**************************************
//INCLUDE files for :Lexical Analyzer in C
//**************************************
//stdio.h
//ctype.h
//string.h
//**************************************
// Name: Lexical Analyzer in C
// Description:It will lexically Analyze the given file(C program) and it will give the various tokens present in it..
//
//
// Inputs:Input the Complete file name with pateh...
//It can also be given in the program itsel..
//i have commented the section...
//
// Returns:keywords,identifiers,operators,headers,arguments
//
//
//Note: Be sure the path is correct
//**************************************

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void keyw(char *p);

int i=0,id=0,kw=0,num=0,op=0;

char ch_sep;
char sep_found;
char sep_type[25];


char keywords[33][10]=
        {"auto","break","case","char","const",
         "continue","default","do","double","else",
         "enum","extern","float","for","goto",
         "if", "int","long","register","return",
         "short", "signed", "sizeof","static","struct",
         "switch", "typedef","union", "unsigned","void",
         "main", "while","volatile"};

int main()
{
    char ch;
    char str[25];
    char separators[15]=" \t\n,;(){}[]#\"<>";
    char operators[]="!%^&*-+=~|.<>/?";
    char comments[2] = "//";
    int j;
    char fname[50] = "/Users/davidjiang/ProLang/Lab2/lab2_test.c";
    FILE *f1;

    //printf("enter file path (drive:\\fold\\filename)\n");
    // scanf("%s",fname);
    //fname = "c:\\isaac\\hello_demo.c";
    //printf("file path %s \n", fname);
//    printf("Lemexe           Token\n");
    f1 = fopen(fname,"r");
    //f1 = fopen("Input","r");
    if(f1==NULL)
    {
        printf("file not found");
        //exit(0);
        return 0;
    }
    while((ch=fgetc(f1))!=EOF)
    {

        //check for operators
        for(j=0;j<=14;j++)
        {
            if(ch==operators[j])
            {
                if(ch=='/')
                {
                    ch=fgetc(f1);
                    if (ch == '/')
                    {
                        //printf("\b Comment found, skip these\n");
                        do
                        {
                            ch=fgetc(f1);
                            //printf("%c",ch);
                        } while(ch!='\n');
                        i=-1;

                    }
                    else
                    {
                        printf("/ \t\t operator\n");
                        op++;
                        i=0;
                        for(j=0;j<=14;j++)
                        {
                            if(ch==operators[j])
                            {
                                printf("%10c \t\t operator\n",ch);
                                op++;
                                str[i]='\0';
                                //'0' - indicate the termination of a char string
                                i=-1;
                            }
                        }

                    }
                }
                else
                {
                    printf("%10c \t\t operator\n",ch);
                    op++;
                    str[i]='\0';
                    //'0' - indicate the termination of a char string
                    i=-1;
                }


            }
        }

        //check for separators
        for(j=0;j<=14;j++)
        {
            if(i==-1)
                break;
            if(ch==separators[j])
            {
                if(ch=='#')
                {
                    while(ch!='>')
                    {
                        printf("%c",ch);
                        ch=fgetc(f1);
                    }
                    printf("%10c \t\t header file\n",ch);
                    i=-1;
                    break;
                }
                if(ch=='"')
                {
                    do
                    {
                        ch=fgetc(f1);
                        printf("%c",ch);
                    } while(ch!='"');

                    printf("\b \t\t argument\n");
                    i=-1;
                    break;
                }
                if(ch=='(')
                {
                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "lparen");
                }
                if(ch==')')
                {
                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "rparen");
                }
                if(ch=='{')
                {

                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "lbrace");
                }
                if(ch=='}')
                {
                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "rbrace");
                }
                if(ch==',')
                {
                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "comma");
                }
                if(ch==';')
                {
                    ch_sep = ch;
                    sep_found = 'y';
                    strcpy(sep_type, "semicolon");
                }


                str[i]='\0';

                keyw(str);
            }
        }

        //Place the character to the string if it is not operator or separator
        if(i!=-1)
        {
            str[i]=ch;
            i++;
        }
        else
        {
            i=0;
        }
    }
    //printf("Keywords: %d\nIdentifiers: %d\nOperators: %d\nNumbers: %d\n",kw,id,op,num);

}

void keyw(char *p)
{
    int k,flag=0;
    //printf("key word\n");
    //printf("%s\n",p);

    for(k=0;k<=32;k++)
    {
        if(strcmp(keywords[k],p)==0)
        {
            printf("%10s \t\t keyword\n",p);
            kw++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(isdigit(p[0]))
        {
            printf("%10s \t\t number\n",p);
            num++;
        }
        else
        {
            //if(p[0]!=13&&p[0]!=10)
            if(p[0]!='\0' && p[0]!='\t' && p[0]!='\n' && p[0]!='\r')
            {
                printf("%10s \t\t identifier\n",p);
                id++;
            }
//            {
//                printf("%s \t\t identifier\n",p);
//                id++;
//            }
        }
    }
    i=-1;

    if (sep_found == 'y')
    {
        printf("%10c \t\t %s\n",ch_sep,sep_type);
    }
    sep_found = 'n';

}

