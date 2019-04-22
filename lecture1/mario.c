#include <cs50.h>
#include <stdio.h>

int insertCheck()
{
    int height;
    char *p, s[100];
    while (fgets(s, sizeof(s), stdin))
    {
        height = strtol(s, &p, 10);
        if (p == s || *p != '\n' || height < 1 || height > 8)
        {
            printf("Height:");
        } 
        else 
            break;
    }
    return height;
}
int main(void)
{
    int Height = 0;
    printf("Height:");
    Height = insertCheck();
    for(int i = 1; i <= Height; i++)
    {
        for(int j = Height -i; j > 0; j--) 
            printf(" ");
        for(int j = 0; j < i; j ++) printf("#");
        printf("  ");
        for(int j =0; j < i; j ++) printf("#");
        printf("\n");
    }
}


