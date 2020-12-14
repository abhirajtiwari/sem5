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
void L();
void Lprime();

void S()
{
    if(str[curr] == '(')
    {
        curr++;
        L();

        if(str[curr] == ')')
        {
            curr++;
            return;
        }

        else
            invalid();
    }

    else if(str[curr] == 'a')
    {
        curr++;
        return;
    }

    else
        invalid();
}

void L()
{
    S();
    Lprime();
}

void Lprime()
{
    if(str[curr] == ',')
    {
        curr++;
        S();
        Lprime();
    }
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
}