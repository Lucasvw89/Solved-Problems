#include <stdio.h>

int main()
{
    int kg;

    scanf("%d", &kg);

    if ((kg % 2 == 0) & (kg > 2)){
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}
