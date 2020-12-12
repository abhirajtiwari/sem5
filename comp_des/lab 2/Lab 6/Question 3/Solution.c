#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 100

int curr = 0;
char str[SIZE];

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

void S();
void A();
void Aprime();
void B();

void S()
{
    if(str[curr] == 'a')
    {
        curr++;
        A();

        if(str[curr] == 'c')
        {
            curr++;
            B();

            if(str[curr] == 'e')
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

    else
        invalid();
}

void A()
{
    if(str[curr] == 'b')
    {
        curr++;
        Aprime();
    }
}

void Aprime()
{
    if(str[curr] == 'b')
    {
        curr++;
        Aprime();
    }
}

void B()
{
    if(str[curr] == 'd')
    {
        curr++;
        return;
    }

    else
        invalid();
}

int main()
{
    printf("Enter the string: ");
    scanf("%s",str);

    S();

    if(str[curr] == '$')
        valid();
    else
        invalid();

    return 0;
}