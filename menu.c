//
// Created by User on 06.04.2021.
//
#include "functions.h"
#include "tests.h"
#include <malloc.h>
#include <stdio.h>
#include "menu.h"

void input_one_or_two_matrices(int pref){
    // если вводим две матрицы
    if (pref == 1 || pref == 2) {
        printf("Enter the order of the first matrix n1xm1: ");
        get_int(&size_n1);
        get_int(&size_m1);
        printf("Enter the order of the second matrix n2xm2: ");
        get_int(&size_n2);
        get_int(&size_m2);
        printf("Enter the element size for the first matrix (int - 4, float - 32): ");
        get_el_size(&el_size_1);
        printf("Enter the element size for the second matrix (int - 4, float - 32): ");
        get_el_size(&el_size_2);
    }
        // если вводим одну матрицу
    else if (pref == 3 || pref == 4) {
        printf("Enter the order of the matrix nxm: ");
        get_int(&size_n1);
        get_int(&size_m1);
        printf("Enter the element size for the matrix (int - 4, float - 32): ");
        get_el_size(&el_size_1);
    }
}

void print_menu(){
    int pref = 0; //определяет какую операцию с матрицами пользователь хочет сделать
    printf("What do you want to do? \n1 - multiply two matrices\n2 - add two matrices\n3 - transpose matrix\n4 - add to the matrix row a linear combination of other rows\n5 - tests\n");
    scanf_s("%d", &pref, sizeof(int));
    input_one_or_two_matrices(pref);
    if(pref == 1){
        mat1 = create(el_size_1, size_n1, size_m1);
        mat2 = create(el_size_2, size_n2, size_m2);
        if (mat1->size_m != mat2->size_n)
            printf("The product of these matrices does not exist\n");
        else{
            printf("Enter the elements of the first matrix one at a time\n");
            fill_mat(mat1);
            printf("Enter the elements of the second matrix one at a time\n");
            fill_mat(mat2);
            printf("First matrix:\n");
            print_mat(mat1);
            printf("Second matrix:\n");
            print_mat(mat2);
            printf("Result: \n");
            print_mat(multiplication(mat1, mat2));
            free(mat2);
        }
    }
    else if(pref == 2){
        mat1 = create(el_size_1, size_n1, size_m1);
        mat2 = create(el_size_2, size_n2, size_m2);
        if (mat2->size_m != mat1->size_m || mat1->size_n != mat2->size_n)
            printf("The sum of these matrices does not exist");
        else {
            printf("Enter the elements of the first matrix one at a time\n");
            fill_mat(mat1);
            printf("Enter the elements of the second matrix one at a time\n");
            fill_mat(mat2);
            printf("First matrix:\n");
            print_mat(mat1);
            printf("Second matrix:\n");
            print_mat(mat2);
            printf("Result: \n");
            print_mat(addition(mat1, mat2));
            free(mat2);
        }
    }
    else if(pref == 3){
        mat1 = create(el_size_1, size_n1, size_m1);
        printf("Enter the elements of the matrix one at a time\n");
        fill_mat(mat1);
        printf("Entered matrix:\n");
        print_mat(mat1);
        printf("Result: \n");
        print_mat(transpose(mat1));
    }
    else if(pref == 4){
        int flag_ans = 1;
        int flag_ans_r = 1;
        mat1 = create(el_size_1, size_n1, size_m1);
        printf("Enter the elements of the matrix one at a time\n");
        fill_mat(mat1);
        while (flag_ans_r) {
            flag_ans = 1;
            while (flag_ans) {
                printf("Enter the row number, the row number you want to add and the coefficient: ");
                scanf_s("%d %d %f", &num_i, &num_p, &coefficient);
                if (mat1->size_n < num_i || mat1->size_n < num_p) {
                    printf("A row number is entered that is outside the matrix. Try it again.\n");
                    flag_ans = 1;
                }
                else{
                    flag_ans = 0;
                    printf("Entered matrix:\n");
                    print_mat(mat1);
                    printf("Result: \n");
                    print_mat(lines_addition(mat1, num_i, num_p, coefficient));
                }
            }
            flag_ans = 1;
            while (flag_ans){
                printf("Want to add one more row? (yes - 1, no - 0): ");
                scanf_s("%d", &flag_ans);
                if (flag_ans != 0 && flag_ans != 1){
                    printf("A nonexistent option was selected. Try it again.\n");
                    flag_ans = 1;
                }
                else{
                    flag_ans_r = flag_ans;
                    flag_ans = 0;
                }
            }
        }
    }
    else if(pref == 5){
        tests();
    }
    else{
        printf("Nonexistent option entered.\n");
        scanf_s("%*c", 0);
    }
}