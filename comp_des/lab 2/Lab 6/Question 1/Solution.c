#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

int curr = 0;
char str[SIZE];

void S();
void T();
void Tprime();

void invalid()
{
    printf("ERROR!\n");
    exit(0);
}

void valid()
{
    printf("SUCCESS\n");
    exit(0);
}

void S()
{
    if(str[curr] == 'a')
    {
        curr++;
        return;
    }

    else if(str[curr] == '>')
    {
        curr++;
        return;     
    }

    else if(str[curr] == '(')
    {
        curr++;
        T();

        if(str[curr] == ')')
        {
            curr++;
            return;
        }

        else
            invalid();
    }

    else
        invalid();   
}

void T()
{
    S();
    Tprime();
}

void Tprime()
{
    if(str[curr] == ',')
    {
        curr++;
        S();
        Tprime();
    }

}   

int main()
{  
    printf("Enter the string: ");
    scanf("%s",str);\
    
    S();

    if(str[curr] == '$')
        valid();
    
    else
        invalid();
}       