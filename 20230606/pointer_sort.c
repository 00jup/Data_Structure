#include <stdio.h>

int ascend(int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }

void insert_sort_fn(int list[], int n, int (*f)(int, int))
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && f(list[j], key) < 0; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

int main()
{
    int list[] = {2, 3, 4, 5, 1};
    int n = sizeof(list) / sizeof(list[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    // Sorting in ascending order
    insert_sort_fn(list, n, ascend);

    printf("Sorted array (ascending): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    // Sorting in descending order
    insert_sort_fn(list, n, descend);

    printf("Sorted array (descending): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
