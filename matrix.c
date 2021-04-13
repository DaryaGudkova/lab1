//
// Created by User on 06.04.2021.
//
#include "matrix.h"
Matrix *create(int e_size, int size_n, int size_m){
    Matrix *mtrx = (Matrix*)malloc(sizeof(Matrix));
    mtrx->element_size = e_size;
    mtrx->size_n = size_n;
    mtrx->size_m = size_m;
    mtrx->matrix = malloc(size_n * size_m * e_size);
    for(int i = 0; i < size_n * size_m * e_size; i++)
        *(char*)((char*)mtrx->matrix + i) = 0;
    return mtrx;
}

void get_el_size(int *a){
    do{
        scanf_s("%d", a, sizeof(int));
        if (*a != 4 && *a != 32){ //неправильный элемент
            printf("%s\n", "Error! Try again: \n");
            scanf_s("%*c", 0);
        }
    } while (*a != 4 && *a != 32);
}

void get_int(int *a){
    int n;
    do{
        n = scanf_s("%d", a, sizeof(int));
        if ((void *) n == NULL){ //неправильный элемент
            printf("%s\n", "Error! Try again: ");
            scanf_s("%*c", 0);
        }
    } while ((void *) n == NULL);
}

void get_float(float *a){
    int n;
    do{
        n = scanf_s("%f", a, sizeof(float));
        if (n == 0){ // неправильный элемент
            printf("%s\n", "Error! Try again: ");
            scanf_s("%*c", 0);
        }
    } while (n == 0);
}

void fill_mat(Matrix* mat){
    if(mat->element_size == 4){
        for(int i = 0; i < mat->size_n * mat->size_m; i++)
            get_int((int*)mat->matrix + i);
    }
    else if(mat->element_size == 32){
        for(int i = 0; i < mat->size_n * mat->size_m; i++)
            get_float((float*)mat->matrix + i);
    }
}

void print_mat(Matrix* mat){
    if(mat->element_size == 4){
        for(int i = 0; i < mat->size_n * mat->size_m; i++){
            printf("%d ", *((int*)mat->matrix + i) );
            if((i + 1) % mat->size_m == 0)
                printf("\n");
        }
    }
    else{
        for(int i = 0; i < mat->size_n * mat->size_m; i++){
            printf("%f ", *((float*)mat->matrix + i));
            if ((i + 1) % mat->size_m == 0)
                printf("\n");
        }
    }
}

