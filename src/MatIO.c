#include <stdlib.h>
#include <stdio.h>
#include "../include/MatIO.h"
#include "../include/MatArith.h"
#include "../include/LibFt.h"

typedef struct Matrix Matrix;

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
