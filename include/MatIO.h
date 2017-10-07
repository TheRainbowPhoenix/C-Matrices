struct Matrix {
	int x;
	int y;
	int** mat;
};
typedef struct Matrix Matrix;

void FWrite(char * fname, char * str);

void FWriteInt(char * fname, int n);

void m_export(char * fname,Matrix * m);

Matrix * m_read();
