#include<cstdio>
char RGB[13] ={'0', '1', '2', '3', '4', '5', '6', '7',
               '8', '9', 'A', 'B', 'C'};
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("#");
    printf("%c%c", RGB[a / 13], RGB[a % 13]);
    printf("%c%c", RGB[b / 13], RGB[b % 13]);
    printf("%c%c\n", RGB[c / 13], RGB[c % 13]);
    return 0;
}