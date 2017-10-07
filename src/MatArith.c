#include <stdlib.h>
#include "../include/MatArith.h"
#include "../include/LibFt.h"
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
