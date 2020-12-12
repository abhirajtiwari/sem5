#include <stdio.h>

int main(){
    int number;
    float floating;
    char character;
    scanf("%d%f",&number,&floating);
    while(getchar()!='\n');
    character = getchar();
    printf("\nInteger= %d,\nfloat=%f \nchar=%c\n",number, floating,character);
    return 0;
}
