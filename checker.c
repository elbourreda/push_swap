#include "push_swap.h"

// int main()
// {
//     char str;

//     read(0, &str, 1);
//     printf("[%c]]\n", str);
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int strleen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *strdup1(char *s)
{
    char *str;
    int i = 0;
    int len = strleen(s);
    str = (char *)malloc(sizeof(char *) * (len + 1));
    while (s[i] != '\0')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

char *strjoin1(char *s, char c)
{
    int i = 0;
    char *str;
    int len = strleen(s);
    str = (char *)malloc(sizeof(char *) * (len + 1 + 1));
    while (s[i] != '\0')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    return str;
}

int get_next_line(int fd, char **line)
{
    int r;
    char c = '\0';
    char *tmp;
    
    if (!*line || !(*line = strdup1("")))
        return -1;
    while ((r = read(fd, &c, 1) > 0))
    {
        if (c == '\0' || c == '\n')
        {
            c = '\0';
            break;
        }
        //tmp = *line
        tmp = *line;
        if (!(*line = strjoin1(*line, c)))
            return -1;
        free(tmp);
    }
    return r;
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*c1;
	char	*c2;
	size_t	i;

	if (!s1 || !s2 || !(r = (char *)malloc(strlen(s1) 
    + strlen(s2) + 1)))
		return (NULL);
	c1 = (char *)s1;
	c2 = (char *)s2;
	i = 0;
	while (*c1)
		r[i++] = *(c1++);
	while (*c2)
		r[i++] = *(c2++);
	r[i] = '\0';
	return (r);
}

int main()
{
    char *red;
    int fd = open("main.c", O_RDONLY);
    int r = 0;
    char *str = malloc(1);
    while ((r = get_next_line(0, &red) > 0) )
    {
        str = ft_strjoin(str, red);
        // r = gnop(fd, &red);
        // printf("%d | %s\n", r, red);
        // free(red);
    }

    printf("|%s|\n", str);
    
    // printf("%d | %s\n", r, red);
        // free(red);
    
    // system("leaks a.out --fullStacks");
}