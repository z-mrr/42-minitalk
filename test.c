#include <unistd.h>
#include <stdio.h>

void    chartobin(char c)
{
    int i;
    i = 8;
    while (i--)
    {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}

int main(int ac, char **av)
{
    int i;

    if (ac != 2)
        return (1);
    i = 0;
    while (av[1][i])
    {
        chartobin(av[1][i]);
        i++;
    }
}