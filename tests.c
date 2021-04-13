//
// Created by User on 04.04.2021.
//

#include "tests.h"
#include "functions.h"
#include <malloc.h>
#include <stdio.h>

Matrix *create_test(int e_size, int size_n, int size_m){
    Matrix *test;
    test = create(e_size, size_n, size_m);
    if(e_size == 4)
        for(int i = 0; i < size_n * size_m; i++)
            *((int*)test->matrix + i) = i + 1;
    else if(e_size == 32)
        for(int i = 0; i < size_n * size_m; i++)
            *((float*)test->matrix + i) = (float)i + 1;
    return test;
}

void tests(){
    int pref = 0;
    printf("What do you want to test? \n1 - multiply two matrices\n2 - add two matrices\n3 - transpose matrix\n4 - add to the matrix row a linear combination of other rows\n5 - filling a matrix\n");
    scanf_s("%d", &pref, sizeof(int));
    if(pref == 1)
        test_multiplication();
    else if(pref == 2)
        test_addition();
    else if(pref == 3)
        test_transpose();
    else if(pref == 4)
        test_lines_addition();
    else if(pref == 5)
        test_fill_mat();
    else{
        printf("Nonexistent item selected. Try again:\n");
        scanf_s("%*c", 0);
    }
    /*
    struct Matrix *m1, *m2, *res;
    int num_i = 1, num_p = 2;
    float coefficient = 2;
    printf("Matrix1:\n");
    m1 = create_test(2, 2, 1);
    print_mat(m1);
    printf("Matrix2:\n");
    m2 = create_test(2, 2, 2);
    print_mat(m2);
    printf("\n");
    //res = create(2,2,2);
    res = ()
    printf("Multiplication of matrix:\n");

    //тесты для суммы: 1) проверка на то что их можно сложить. 2) сумма
    // аналогично для произведения
    // проверка на ввод:

    multiplication(m1, m2, res);
 printf("Addition of matrix:\n");
 addition(m1, m2, res);
 printf("Adding a row multiplied by a factor:\n");
 lines_addition(m1, num_i, num_p, coefficient, res);
 printf("Transposed matrix:");
 transpose(m1, res);

    int test_multiplication(*m1, *m2, *res){
    }

    free(m1);
    free(m2);
    free(res);*/
}

void test_two_matrices(int pref, int e_size_1, int e_size_2, const int res_n_m[9]){
    struct Matrix *m1, *m2, *res;
    int flag = 0;
    m1 = create_test(e_size_1, 3, 3);
    printf("\nThe first matrix:\n");
    print_mat(m1);
    m2 = create_test(e_size_2, 3, 3);
    printf("The second matrix:\n");
    print_mat(m2);
    if(pref == 1)
        res = multiplication(m1, m2);
    else
        res = addition(m1, m2);
    printf("The result:\n");
    print_mat(res);
    if(e_size_1 == 4 && e_size_2 == 4){
        printf("Test with int elements is ");
        for (int i = 0; i < res->size_n * res->size_m; i++)
            if (*((int *) res->matrix + i) != res_n_m[i])
                flag++;
    }
    else{
        if(e_size_1 == 32 && e_size_2 == 32)
            printf("Test with float elements is ");
        else
            printf("Test with int and float elements is ");
        for (int i = 0; i < res->size_n * res->size_m; i++)
            if (*((float *) res->matrix + i) != (float) res_n_m[i])
                flag++;
    }
    if (flag > 0)
        printf("FALSE\n");
    else
        printf("TRUE\n");
    free(m1);
    free(m2);
    free(res);
}

void test_one_matrix(int pref, int e_size, const int res_n_m[9]){
    struct Matrix *m, *res;
    int flag = 0;
    m = create_test(e_size, 3, 3);
    printf("\nThe matrix:\n");
    print_mat(m);
    if (pref == 3)
        res = transpose(m);
    else{
        printf("The row number: %d\n the row number to add: %d\n the coefficient: %d\n", 1, 2, 2);
        res = lines_addition(m, 1, 2, 2);
    }
    printf("The result:\n");
    print_mat(res);
    if(e_size == 4){
        printf("Test with int elements is ");
        for (int i = 0; i < res->size_n * res->size_m; i++)
            if (*((int *) res->matrix + i) != res_n_m[i])
                flag++;
    }
    else if(e_size == 32){
        printf("Test with float elements is ");
        for (int i = 0; i < res->size_n * res->size_m; i++)
            if (*((float *) res->matrix + i) != (float) res_n_m[i])
                flag++;
    }
    if (flag > 0)
        printf("FALSE\n");
    else
        printf("TRUE\n");
    free(m);
    if(pref == 3)
        free(res);
}
void test_multiplication(){
    int res_3_3[9] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    /// test int
    test_two_matrices(1, 4,4, res_3_3);

    ///тест float
    test_two_matrices(1, 32, 32, res_3_3);

    ///test float and int
    test_two_matrices(1, 4, 32, res_3_3);
}

void test_addition(){
    int res_3_3[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    /// test int
    test_two_matrices(2, 4, 4, res_3_3);

    ///тест float
    test_two_matrices(2, 32, 32, res_3_3);

    ///test int and float
    test_two_matrices(2, 4, 32, res_3_3);
}

void test_transpose(){
    int res_3_3[9] = {1,4,7,2,5,8,3,6,9};
    /// test int
    test_one_matrix(3, 4, res_3_3);
    ///тест float
    test_one_matrix(3, 32, res_3_3);
}

void test_lines_addition(){
    int res_3_3[9] = {9, 12, 15, 4, 5, 6, 7, 8, 9};
    /// test int
    test_one_matrix(4, 4, res_3_3);
    ///тест float
    test_one_matrix(4, 32, res_3_3);
}

void test_fill_mat(){
    ///test correct input
    struct Matrix *m;
    printf("Enter the matrix 2x2 with integers\n");
    m = create(4, 2, 2);
    fill_mat(m);
    printf("The result:\n");
    print_mat(m);
}
