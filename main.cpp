#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int** mat(int**, int, int, int);

int det(int** matrix, int range)
{
    if (range == 1)
        return matrix[0][0];
    else
    {
        int opr = 0;
        for (int i = 0; i < range; i++)
        {
            int** bon = mat(matrix, range, i, 0);
            opr += matrix[i][0]*pow(-1,i)*det(bon, range - 1);
        }   
     
        return opr;
    }
}
int** mat(int** matrix, int range, int a, int b)
{
    int** newMatrix = (int**) calloc(range - 1, sizeof(int*));
    for (size_t i = 0; i < range - 1; i++)
        newMatrix[i] = (int*) calloc(range - 1, sizeof(int));
    
    for (size_t i = 0; i < a; i++)
        for (size_t j = 0; j < b; j++)
            newMatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < b; i++)
        for (size_t j = a + 1; j < range; j++)
            newMatrix[i][j - 1] = matrix[i][j];
    for (size_t i = b + 1; i < range; i++)
        for (size_t j = 0; j < a; j++)
            newMatrix[i - 1][j] = matrix[i][j];
    for (size_t i = b + 1; i < range; i++)
        for (size_t j =  a + 1; j < range; j++)
            newMatrix[i - 1][j - 1] = matrix[i][j];
    
    return newMatrix;
}
int main() {
    
    int range;
    printf("vvedite poradok matrici ");
    scanf("%d", &range);
    int** array = (int**) calloc(range, sizeof(int*));
    for (int i = 0; i < range; i++)
        array[i] = (int*) calloc(range, sizeof(int));
    for (int i = 0; i < range; i++) {
        printf("%d row: ", i+1);
        for (int j = 0; j < range; j++)
        {
            scanf("%d", &array[i][j]);  // *(*(array + i) + j)
        }
        
    }
    
    printf("%d \n", det(array, range));
    

}