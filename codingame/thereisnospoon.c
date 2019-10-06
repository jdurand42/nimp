#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
char	*ft_strndup(char *src, int n);

int main()
{
    // the number of cells on the X axis
    int width;
    scanf("%d", &width);
    // the number of cells on the Y axis
    int height;

    scanf("%d", &height); fgetc(stdin);
    // PARSING MAN
    char **tab;
    tab = malloc(height * sizeof(char*));

    for (int i = 0; i < height; i++) {
        // width characters, each either 0 or .
        char line[32];
        fgets(line, 32, stdin);
        tab[i] = ft_strndup(line, width);
    }
    fprintf(stderr, "height :%d\nwidth :%d\n", height, width);
    for (int i = 0; i < height; i++)
    {
        fprintf(stderr, "%s\n", tab[i]);
    }

    // game loop
    int x = 0;
    int y = 0;
    int xb = 0;
    int yb = 0;
    int poor = 1;

    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (tab[y][x] == '0')
            {
                // found a node
                printf("%d %d ", x, y);

                if (x + 1 >= width)
                {
                    printf("-1 ");
                    printf("-1 ");
                }
                else //search the node to the right
                    {
                        for (xb = x + 1; xb < width && poor == 1; xb++)
                        {
                            if (tab[y][xb] == '0')
                            {
                                printf("%d ", xb);
                                printf("%d ", y);
                                poor = 0;
                            }

                        }
                        if (xb == width && poor == 1)
                        {
                            printf("-1 ");
                            printf("-1 ");
                        }
                        poor = 1;
                    }
                if (y + 1 >= height)
                {
                    printf("-1 ");
                    printf("-1 ");
                }
                else
                    {
                        for (yb = y + 1; yb < height && poor == 1; yb++)
                        {
                            if (tab[yb][x] == '0')
                            {
                                printf("%d ", x);
                                printf("%d ", yb);
                                poor = 0;
                            }
                        }
                        if (yb == height && poor == 1)
                        {
                            printf("-1 ");
                            printf("-1 ");
                        }
                        poor = 1;
                    }
                printf("\n");
            } // found a node loop
            x++;
        }
        y++;
    }
    // Three coordinates: a node, its right neighbor, its bottom neighbor
    return 0;
}




char	*ft_strndup(char *src, int n)
{
	unsigned int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}
