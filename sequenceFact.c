#include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
int main() {
    int n, i;
    double sum = 1.0; 
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        int factIndex = 2 * i - 1;
        sum += (double)i / factorial(factIndex);
    }
    printf("Sum of the series = %.6lf\n", sum);
    return 0;
}