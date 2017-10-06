#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/MatIO.h"
#include "../include/MatArith.h"

struct Matrix {
	int x;
	int y;
	int** mat;
};
typedef struct Matrix Matrix;

Matrix * m_init(int x_size, int y_size) {
	int ** matt;
	int x;
	struct Matrix* matrix = malloc(sizeof(Matrix));
	matrix->x = x_size;
	matrix->y = y_size;
	matt = malloc(sizeof(int*) * x_size);
	for(x = 0; x < x_size; x++) {
		matt[x] = calloc(y_size, sizeof(int));
	}
	matrix->mat = matt;
	return matrix;
}

Matrix * m_populate(int* matt, int x_s, int y_s) {
	int x;
	int y;
	struct Matrix *matrix = m_init(x_s, y_s);
	for(x = 0; x < x_s; x++) {
		for(y = 0; y < y_s; y++) {
			matrix->mat[x][y] = matt[y_s*x+y];
		}
	}
	return matrix;
}

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
void m_print(Matrix * m) {
	int x;
	int y;
	for(x = 0; x < m->x; x++) {
		for(y = 0;y < m->y; y++) {
			ft_putnbr(m->mat[x][y]);
			ft_putstr((y+1==m->y)?(" "):(",	"));
		}
		ft_putchar('\n');
	}
}

Matrix * m_multiply(Matrix * m1, Matrix * m2) {
	int val;
	int i;
	int j;
	int k;
	struct Matrix *matrix = (m1->y == m2->x)?(m_init(m1->x, m2->y)):(m_init(0,0));

	val = 0;

	if(m1->y != m2->x)
	{
		ft_putstr("Size_Error");
		return matrix;
	}

	matrix = m_init(m1->x, m2->y);

	for(i=0;i<m1->x; i++) {
		for(j=0;j<m2->y; j++)
		{
			matrix->mat[i][j] = 0;
			for(k =0;k<m1->y;k++) {
				matrix->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];
			}
		}
	}
	return matrix;
}

Matrix * m_add(Matrix * m1, Matrix * m2) {
	int x;
	int y;
	struct Matrix *matrix = (m1->y != m2->y || m1->x != m2->x)?(m_init(0,0)):(m_init(m1->x, m1->y));
	if(m1->y != m2->y || m1->x != m2->x)
	{
		ft_putstr("Size_Error");
	} else {
		for(x=0;x<m1->x;x++){
			for(y=0;y<m1->y;y++)
				matrix->mat[x][y] = m1->mat[x][y] + m2->mat[x][y];
		}
	}
	return matrix;
}

Matrix * m_sub(Matrix * m1, Matrix * m2) {
	int x;
	int y;
	struct Matrix *matrix = (m1->y != m2->y || m1->x != m2->x)?(m_init(0,0)):(m_init(m1->x, m1->y));
	if(m1->y != m2->y || m1->x != m2->x)
	{
		ft_putstr("Size_Error");
	} else {
		for(x=0;x<m1->x;x++){
			for(y=0;y<m1->y;y++)
				matrix->mat[x][y] = m1->mat[x][y] - m2->mat[x][y];
		}
	}
	return matrix;
}

Matrix * m_read() {
	int x;
	int y;
	struct Matrix *matrix;
	ft_putstr("matrix->x: ");
	fscanf(stdin, "%d", &x);
	ft_putstr("matrix->y: ");
	fscanf(stdin, "%d", &y);
	x=((x<0||x>255)?(1):(x));
	y=((y<0||y>255)?(1):(y));
	matrix = m_init(x,y);
	for (x=0;x<matrix->x;x++) {
		ft_putstr("[ ");
		for (y=0;y<matrix->y;y++) {
			fscanf(stdin, "%d", &matrix->mat[x][y]);
			ft_putstr(", ");
		}
		ft_putstr("]\n");
	}
	return matrix;
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

void help(void) {
	ft_putstr("Usage: MultMat [options] file\n");
	ft_putstr("\nOptions:\n");
	ft_putstr("  -h\t\tPrint this message\n");
	ft_putstr("  -i\t\tInput two Matrix\n");
	ft_putstr("  -m\t\tMultiply two Matrix\n");
	ft_putstr("  -a\t\tAdd two Matrix\n");
	ft_putstr("  -s\t\tSubstract two Matrix\n");
	ft_putstr("  -e FILENAME\tExport input\n");
}

void FWrite(char * fname, char * str) {
	FILE *f = fopen(fname, "a");
	if (f == NULL)
	{
		FILE *f = fopen(fname, "w+");
		if (f == NULL)
		{
			ft_puterrstr("Error opening file!\n");
			exit(1);
		}
	}
	fprintf(f, "%s\n", str);
	fclose(f);
}

void FWriteInt(char * fname, int n) {
	FILE *f = fopen(fname, "a");
	if (f == NULL)
	{
		FILE *f = fopen(fname, "w+");
		if (f == NULL)
		{
			ft_puterrstr("Error opening file!\n");
			exit(1);
		}
	}
	fprintf(f, "%d\n", n);
	fclose(f);
}

void m_export(char * fname,Matrix * m) {
	int x;
	int y;
	FWriteInt(fname, m->x);
	FWriteInt(fname, m->y);
	for(x = 0; x < m->x; x++) {
		for(y = 0;y < m->y; y++) {
			FWriteInt(fname, m->mat[x][y]);
		}
	}
}

void Operator(int iflag, int ope, int eflag, char * fname) {
	int a[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int b[] = {
		1, 3, 2,
		4, 6, 5,
		12,11,14
	};
	Matrix* m1;
	Matrix* m2;
	Matrix* m3;

	if(eflag) {
		if(fname == NULL) {
			fname = "missingno.txt";
		}
	}
	if(iflag==1) {
		m1 = m_read();
		m_print(m1);
		ft_putstr("\n");
		m2 = m_read();
		m_print(m2);
		ft_putstr("\n");
		if(eflag==1) {
			m_export(fname, m1);
			m_export(fname, m2);
		}
	} else {
		ft_putstr("No input, using demo matrix :\n");
		m1 = m_populate(a, 3, 3);
		m_print(m1);
		ft_putstr("\n");
		m2 = m_populate(b, 3, 3);
		m_print(m2);
		ft_putstr("\n");
		if(eflag==1) {
			m_export(fname, m1);
			m_export(fname, m2);
		}
	}
	switch (ope) {
		case 1:
			m3 = m_multiply(m1,m2);
			break;
		case 2:
			m3 = m_add(m1,m2);
			break;
		case 3:
			m3 = m_sub(m1,m2);
			break;
		case 0:
			m3 = m_init(1,1);
			break;
		default:
			m3 = m_init(1,1);
			break;
	}
	m_print(m3);
	ft_putstr("\n");
}

int	main(int argc, char *argv[])
{
	int iflag;
	int eflag;
	int ope;
	char *fname = NULL;
	int c;
	iflag = 0;
	eflag = 0;
	ope = 0;
	opterr = 0;
	while ((c = getopt (argc, argv, "himase:")) != -1) {
		switch (c)
		{
			case 0:
				/* If this option set a flag, do nothing else now. */
				printf ("option %d", optopt);
				if (optarg)
					printf (" with arg %s", optarg);
				printf ("\n");
				break;
			case 'i':
				iflag = 1;
				break;
			case 'm':
				ope = 1;
				break;
			case 'a':
				ope = 2;
				break;
			case 's':
				ope = 3;
				break;
			case 'e':
				fname = (optarg == 0)?("TheNothing"):(optarg);
				eflag = 1;
				break;
			case '?':
				if (optopt == 'e') {
					ft_puterrstr("The option ");
					ft_puterrchar(optopt);
					ft_puterrstr(" requires an argument.\n");
				} else {
					ft_puterrstr("Error : option character ");
					ft_puterrchar(optopt);
					ft_puterrstr(" is unknown\n");
				}
				return 1;
			case 'h':
			default:
				help();
				break;
		}
	}
	if (argc == 1) {
		help();
	} else if(argc <= 5) {
		ft_putnbr(argc);
		Operator(iflag, ope, eflag, fname);
	} else {
		ft_puterrstr("Error : Too many arguments !\n");
	}
	return (0);
}
