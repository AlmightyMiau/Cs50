#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    // Get Size of Grid
    int size = get_size();
    // Print Grid
    print_grid(size);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_grid(size)
{
    for (int i = 0; i < size; i++)
    {
        for (int x = 0; x < 2; x++)
        {
            for (int j = 0; j < size; j++)
            {
                if ((size - (j + i)) > 1)
                {
                    printf("!");
                }
                else
                {
                    printf("#");
                }
            } for (int j = size; j > 0; j--) {
                if ((size - (j + i)) > 1)
                {
                    printf("#");
                }
                else
                {
                    printf("!");
                }
            }
            printf("  ");
        }
        printf("\n");
    }
}
