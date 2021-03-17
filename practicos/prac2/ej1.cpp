typedef unsigned int uint;

void insertarOrdenado(float * A, uint n, float e)
{
    if (n == 0) {
        A[n + 1] = e;
    } else if (A[n] < e) {
        A[n+1] = e;
        n++;
    } else {
        A[n+1] = A[n];
        insertarOrdenado(A, n-1, e);
    }
}

void insertarOrdenadoIterativo(float * A, uint n, float e)
{
    int i = n;
    while(i > 0 && A[i] > e) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = e;
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