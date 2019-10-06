#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void    lissage(char *jeu);
void    delissage(char *jeu);
char	*ft_strncat(char *dest, char *src, size_t nb);
void    redistribute(char *p1, char *p2, int winner, int indice);
void    ft_bzero(void *s, size_t n);

int     solve_pat(char *p1, char *p2, int indice);
int     solve_bataille(char *p1, char *p2, int *indice);

/* PArti sur un jeu en chaine de char mais faisable aussi en liste chainée */

int main()
{
    // the number of cards for player 1
    char *p1;
    char *p2;
    int manche = 0;
    int indice = 0;

    int winner = 0;

    // Max charactere = 117
    int n;
    scanf("%d", &n);
    if (!(p1 = malloc((117) * sizeof(char))))
        return (0);
    p1[0] = 0;
    for (int i = 0; i < n; i++) {
        // the n cards of player 1
        char cardp_1[4];
        scanf("%s", cardp_1);
       p1 = ft_strcat(p1, cardp_1);
    }
    // the number of cards for player 2
    int m;
    scanf("%d", &m);
    if (!(p2 = malloc((117) * sizeof(char))))
        return (0);
    p2[0] = 0;
    for (int i = 0; i < m; i++) {
        // the m cards of player 2
        char cardp_2[4];
        scanf("%s", cardp_2);
        p2 = ft_strcat(p2, cardp_2);
    }

    lissage(p1);
    lissage(p2);

    fprintf(stderr, "%s\n2\n%s\n\n", p1, p2);

    while (!(p1[0] == 0 || p2[0] == 0)) //game is on // gaffe au seg fault
    {
        winner = solve_bataille(p1, p2, &indice);
        if (winner == 0)
        {
            printf("PAT");
            return (0);
        }
        manche++;
        redistribute(p1, p2, winner, indice);

        indice = 0;
    }
    fprintf(stderr, "manches: %d\n", manche);
    if (p1[0] == 0)
        printf("2 ");
    if (p2[0] == 0)
        printf("1 ");
    printf("%d\n", manche);
   // printf("PAT\n");

    return 0;
}
/*
int    bataille(char *p1, char *p2, char *winner, int *indice)
{
    int indice_p1 = count10(p1, 6);
    int indice_p2 = count10(p2, 6);

    winner = solve_bataille(p1, p2, &indice_p1, &indice_p2);
    printf(stderr, "bataille winner: %s\n", winner);
    return (0);
}
*/
int   solve_bataille(char *p1, char *p2, int *indice)
{

                if (p1[*indice] > p2[*indice])
                {
                    fprintf(stderr, "p1 gagne\n");
                    *indice += 2;
                    return (1);
                }
                else if (p1[*indice] < p2[*indice])
                {
                    fprintf(stderr, "p2 gagne\n");
                    *indice += 2;
                    return (2);
                }
                else if (p1[*indice] == p2[*indice])
                {
                    fprintf(stderr, "--- BATAILLE ---\n");
                    *indice += 8;
                    if (!(solve_pat(p1, p2, *indice)))
                        return (0);
                    return (solve_bataille(p1, p2, indice));
                }
}

int solve_pat(char *p1, char *p2, int indice)
{
    int i = 0;

    while (i < indice)
    {
        fprintf(stderr, "la\n");
        if (p1[i] == 0)
            return (0);
        if (p2[i] == 0)
            return (0);
        i++;
    }
    fprintf(stderr, "ici\n");
    return (1);
}

void    redistribute(char *p1, char *p2, int winner, int indice)
{
    char *buffer;

    buffer = malloc(117 * sizeof(char));
    ft_bzero(buffer, 117);

    buffer = ft_strncat(buffer, p1, indice);
    buffer = ft_strncat(buffer, p2, indice);
    fprintf(stderr, "buffer : %s\n", buffer);
    fprintf(stderr, "indice du buffer: %d\n", indice);
    if (winner == 1)
    {
        p1 = ft_strcat(p1, buffer);
        p1[0] = 0;
        p1 = ft_strcat(p1, &p1[indice]);
        p2[0] = 0;
        p2 = ft_strcat(p2, &p2[indice]);
    }
    else if (winner == 2)
    {
        p2 = ft_strcat(p2, buffer);
        p2[0] = 0;
        p2 = ft_strcat(p2, &p2[indice]);
        p1[0] = 0;
        p1 = ft_strcat(p1, &p1[indice]);
    }
    fprintf(stderr, "p1: %s\np2: %s\n\n", p1, p2);
}
/*
int     count10(char *jeu, int indice)
{
    int i = 0;

    while (i < indice)
    {
        if (jeu[i] == ':')
            indice++;
        i++;
    }
    return (indice);
}
  */

int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	megasize;
	char			*b;

    megasize = ft_strlen(s1) + ft_strlen(s2);
    if (megasize <= 0)
        return ("");
    if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
        return (NULL);
    b[0] = 0;
    ft_strcat(b, s1);
    ft_strcat(b, s2);
    fprintf(stderr, "\n%s\n", b);
	return (b);
}

void    lissage(char *jeu)
{
    int i = 0;

    while (jeu[i] != 0)
    {
        if (jeu[i] == 'J')
            jeu[i] = 59;
        if (jeu[i] == 'Q')
            jeu[i] = 60;
        if (jeu[i] == 'K')
            jeu[i] = 61;
        if (jeu[i] == 'A')
            jeu[i] = 62;
        if (jeu[i] == '1')
        {
            jeu[i] = 58;
            jeu[i + 1] = 0;
            jeu = ft_strcat(jeu, &jeu[i + 2]);
        }
        i++;
    }
}

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void    ft_bzero(void *s, size_t n)
{
    unsigned char *str;

    str = (unsigned char *)s;
    while (n--)
    {
        *str++ = '\0';
    }
}

/*
void    delissage(char *jeu)
{
    int i = 0;

    while (jeu[i] != 0)
    {
        if (jeu[i] == 59)
            jeu[i] = 'J';
        if (jeu[i] == 60)
            jeu[i] = 'Q';
        if (jeu[i] == 61)
            jeu[i] = 'K';
        if (jeu[i] == 62)
            jeu[i] = 'A';
        if (jeu[i] == 58)
            jeu[i] = '1';
        i++;
    }
}
*/
