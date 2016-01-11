#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double l, s1, s2;
    int q;
    int i;
    scanf("%lf %lf %lf", &l, &s1, &s2);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        double qi;
        scanf("%lf", &qi);
        printf("%.20f\n", sqrt(2) * (l - sqrt(qi)) / abs(s2 - s1));
    }
    return 0;
}
