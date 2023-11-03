#include "Ejercicio04.h"

void generarParentesis(int n, int abierto, int cerrado, string actual, vector<string>& resultado) {
    if (cerrado == n) {
        resultado.push_back(actual);
        return;
    }
    if (abierto < n) {
        generarParentesis(n, abierto + 1, cerrado, actual + '(', resultado);
    }
    if (cerrado < abierto) {
        generarParentesis(n, abierto, cerrado + 1, actual + ')', resultado);
    }
}

vector<string> Ejercicio04::generateParenthesis(int n)
{
    vector<string> resultado;
    generarParentesis(n, 0, 0, "", resultado);
    return resultado;
}
