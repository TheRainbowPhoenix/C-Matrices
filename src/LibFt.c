#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/LibFt.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}
int	ft_puterrchar(char c)
{
	write(2, &c, 1);
	return 0;
}
void	ft_putnbr(int nb)
{
	char g_buff[1000];
	char g_nbr[] = "0123456789";
	int g_cmptr;
	int g_tmp;
	int g_fnl;
	int g_base;

	g_cmptr = 0;
	g_tmp = 0;
	g_fnl = 0;
	g_base = 10;
	if (nb==0)
		ft_putchar('0');
	if (nb < 0)
	{
		g_fnl++;
		ft_putchar('-');
	}
	while (nb)
	{
		g_tmp = nb % g_base;
		g_tmp = (g_tmp < 0) ? -g_tmp : g_tmp;
		g_buff[g_cmptr] = g_nbr[g_tmp];
		g_cmptr++;
		nb /= g_base;
	}
	while (g_cmptr >= 0)
	{
		ft_putchar(g_buff[g_cmptr-1]);
		g_cmptr--;
	}
}

void	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i]) {
		ft_putchar(str[i]);
		i++;
	}
}
void	ft_puterrstr(char *str)
{
	int i;
	i = 0;
	while (str[i]) {
		ft_puterrchar(str[i]);
		i++;
	}
}

void	ft_swap(char **a, char **b)
{
	char *swappy;
	swappy = *b;
	*b = *a;
	*a = swappy;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return ((char)s1[i] - (char)s2[i]);
}
