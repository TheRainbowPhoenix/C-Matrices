# define ANSWER 42

typedef struct Matrix Matrix;

Matrix * m_init(int x_size, int y_size);
Matrix * m_populate(int* matt, int x_s, int y_s);
void m_print(Matrix * m);
Matrix * m_multiply(Matrix * m1, Matrix * m2);
Matrix * m_add(Matrix * m1, Matrix * m2);
Matrix * m_sub(Matrix * m1, Matrix * m2);
