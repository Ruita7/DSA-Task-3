#include <stdio.h>
#define MAX 10
#define MAX_TERMS (MAX * MAX + 1)

/* Triplet representation:
   row 0 stores: number of rows, number of columns, non-zero count.
   Following rows store: row index, column index, value. */

int main(void) {
    int matrix[MAX][MAX];
    int sparse[MAX_TERMS][3];
    int rows, cols, count = 0;

    printf("Enter number of rows and columns (maximum %d x %d): ",
           MAX, MAX);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter the matrix elements row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid matrix input.\n");
                return 1;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
            }
        }
    }

    sparse[0][2] = count;

    printf("\nSparse matrix in triplet form:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n",
               sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
