#include <stdio.h>
#include <string.h>

char nums[10][5][4] = 
{
    {
        "***",
        "* *",
        "* *",
        "* *",
        "***"
    },
    {
        "  *",
        "  *", 
        "  *", 
        "  *", 
        "  *"
    },
    {
        "***",
        "  *",
        "***",
        "*  ",
        "***"
    },
    {
        "***",
        "  *",
        "***",
        "  *",
        "***",
    },
    {
        "* *",
        "* *",
        "***",
        "  *",
        "  *",
    },
    {
        "***",
        "*  ",
        "***",
        "  *",
        "***",
    },
    {
        "***",
        "*  ",
        "***",
        "* *",
        "***",
    },
    {
        "***",
        "  *",
        "  *",
        "  *",
        "  *",
    },
    {
        "***",
        "* *",
        "***",
        "* *",
        "***",
    },
    {
        "***",
        "* *",
        "***",
        "  *",
        "***",
    }
};

int main()
{
    char *input[6];
    memset(input, 0, sizeof(input));
    size_t buffsize = 0;
    for(int i = 0; i < 5; i++)
        getline(&input[i], &buffsize, stdin);

    int num = 0;
    for(int i = 0; i < strlen(input[0]); i+=4) 
    {
        int digit = -1;
        for(int j = 0; j < 10; j++)
        {
            bool good = true;
            for(int k = 0; k < 5; k++)
            {
                if(strncmp(&input[k][i], nums[j][k], 3))
                    good = false;
            }
            if(good)
                digit = j;
        }
        if(digit == -1)
        {
            printf("BOOM!!\n");
            return 0;
        }
        num *= 10;
        num += digit;
    }

    //fprintf(stderr, "%d", num);
    if(num % 6)
        printf("BOOM!!\n");
    else
        printf("BEER!!\n");
}
