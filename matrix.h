//
// Created by User on 06.04.2021.
//

#ifndef UNTITLED1_MATRIX_H
#define UNTITLED1_MATRIX_H
#include <stdlib.h>
#include <stdio.h>
typedef struct Matrix{
    void* matrix;
    int size_m;
    int size_n;
    int element_size;
}Matrix;

struct Matrix *create(int e_size, int size_n, int size_m); //создание матрицы
void fill_mat(Matrix *mat); //Функция заполнения матрицы с клавиатуры
void print_mat(Matrix *mat); //Функция печати матрицы

void get_int(int *a); //ввод int с проверкой на некорректный ввод
void get_float(float *a); //ввод float с проверкой на некорректный ввод
void get_el_size(int *a); //ввод размера элементов матрицы

#endif //UNTITLED1_MATRIX_H
