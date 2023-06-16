#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int num;
    
    printf("Input the number for factorial calculation: ");
    scanf("%d", &num);
    
    int result = factorial(num);
    
    printf("The factorial of %d is %d.\n", num, result);
    
    return 0;
}







