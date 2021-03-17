typedef unsigned int uint;

bool esPolindromeAux(char *string, uint n, uint deep) {
    if (deep >= n/2 - 1) 
        return true;
    else
        return string[1+deep] == string[n-deep] && esPolindromeAux(string, n, deep + 1);
}

bool esPolindrome(char *string, uint n){
    return esPolindromeAux(string, n, 0);
}

int main () {
    
}