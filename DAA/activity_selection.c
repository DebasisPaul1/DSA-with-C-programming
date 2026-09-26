#include <stdio.h>

struct Activity {
    int start, finish;
};

int main() {
    struct Activity a[100];
    int n, last = -1;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish time:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].finish);

    printf("Selected activities:\n");

    for (int i = 0; i < n; i++) {
        if (a[i].start >= last) {
            printf("(%d, %d) ", a[i].start, a[i].finish);
            last = a[i].finish;
        }
    }

    return 0;
}
