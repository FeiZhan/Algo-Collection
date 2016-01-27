//@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s

#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    *a += *b;
    *b = *a - 2 * *b;
    if (*b < 0) {
        *b *= -1;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
