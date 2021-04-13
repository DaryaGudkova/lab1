//
// Created by User on 04.04.2021.
//

#ifndef UNTITLED1_FUNCTIONS_H
#define UNTITLED1_FUNCTIONS_H

#include "matrix.h"

Matrix *multiplication(Matrix *m1, Matrix *m2);// Умножение двух матриц
Matrix *addition(Matrix *m1, Matrix *m2); //Сложение двух матриц
Matrix *transpose(Matrix *m1); //Транспонирование матрицы
Matrix *lines_addition(Matrix *m1, int num_i, int num_p, float coefficient); //Прибавление строки, умноженной на коэфициент, к другой строке

//float float_rand( float min, float max );

#endif //UNTITLED1_FUNCTIONS_H
