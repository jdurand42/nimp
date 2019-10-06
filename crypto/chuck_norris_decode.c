#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

static int ft_nbrlen_base(long int nbr, int baselen)
{
    int nbrlen;

    nbrlen = 1;
    if (nbr < 0)
    {
        nbr = -nbr;
        nbrlen++;
    }
    while (nbr >= baselen)
    {
        nbr /= baselen;
        nbrlen = nbrlen + 1;
    }
    return (nbrlen);
}

static int get_baselen(char *base)
{
    int baselen;

    baselen = 0;
    while (base[baselen] != '\0')
        baselen++;
    return (baselen);
}

char *ft_itoa_base(int nbr, char *base)
{
    char *str;
    int nbrlen;
    long int nbr2;
    int     baselen;

    nbr2 = (long int)nbr;
    baselen = get_baselen(base);
    nbrlen = ft_nbrlen_base(nbr2, baselen);
    if (!(str = (char*)malloc((nbrlen + 1) * sizeof(char))))
        return (0);
    if (nbr2 < 0)
        nbr2 = -nbr2;
    str[0] = '-';
    str[nbrlen--] = '\0';
    if (nbr2 == 0)
        str[nbrlen] = base[0];
    while (nbr2)
    {
        str[nbrlen--] = base[nbr2 % baselen];
        nbr2 = nbr2 / baselen;
    }
    return (str);
}

void decode(char *encoded, char *buffer)
{
    int i = 0;
    int j = 0;
    int len;

    while (encoded[j] != 0)
    {
        if (encoded[j] == '0' && encoded[j + 1] == '0')
        {
            buffer[i++] = '0';
            j++;
            while (encoded[j] != 0 && c_bin[j] == '0')
            {
                buffer[i++] = '0';
                j++;
            }
            buffer[i++] = ' ';
        }
        if (c_bin[j] == '1')
        {
            buffer[i++] = '0';
            buffer[i++] = ' ';
            buffer[i++] = '0';
            j++;
            while (c_bin[j] != 0 && c_bin[j] == '1')
            {
                buffer[i++] = '0';
                j++;
            }
            buffer[i++] = ' ';
        }
    }
    buffer[i - 1] = 0;
}

static char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

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

static unsigned int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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
	return (b);
}

int main(int argc, char **argv)
{
    int i = 0;
    void(argc);
    int len = strlen(argv[0]);
    char *c_bin = malloc(((len + 1) * sizeof(char));
    char *chuck = malloc((len * 31) * sizeof(char));
    char *buffer;
    c_bin[0] = 0;
    chuck[0] = 0;;

    while (i < len)
    {
        buffer = ft_itoa_base(argv[0][i], "01");
        if (strlen(buffer) < 7)
            c_bin = ft_strjoin(c_bin, "0");
        c_bin = ft_strjoin(c_bin, buffer);
        i++;
    }
    conv(c_bin, chuck);
    printf("%s\n", chuck);
    return 0;
}
