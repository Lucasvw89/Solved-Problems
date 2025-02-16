#include <stdio.h>

int main()
{
    unsigned long long m, n, a;

    scanf("%llu", &m);
    scanf("%llu", &n);
    scanf("%llu", &a);

    unsigned long long m_a = 0, n_a = 0;

    if (m % a == 0) {
        m_a = m/a;
    } else {
        m_a = m/a + 1;
    }

    if (n % a == 0) {
        n_a = n/a;
    } else {
        n_a = n/a + 1;
    }

    printf("%llu\n", m_a*n_a);

    return 0;
}
