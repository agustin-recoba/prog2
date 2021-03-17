typedef unsigned int uint;

void insertarOrdenado(float * A, uint n, float e)
{
    
}

void ordenar(float * A, uint n)
{
    if (n > 1)
    {
        ordenar(A, n-1);
        insertarOrdenado(A, n-1, A[n]);
    }
}

int main () {
    
}