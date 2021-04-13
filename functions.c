//
// Created by User on 04.04.2021.
//
#include "functions.h"

/*
void *randFloat(void* res){
    float left, right;
    float fl = float_rand(-100, 100);
    memcpy(res, &fl, sizeof(float));
    return res;
}
float float_rand( float min, float max ){
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}
*/

Matrix *multiplication(Matrix *m1, Matrix *m2){
    int el_size_3 = m1->element_size <= m2->element_size ? m2->element_size : m1->element_size;// определяем размер элемента результирующей матрицы
    Matrix *res = create(el_size_3, m1->size_n, m2->size_m);
    int type = m1->element_size + m2->element_size;
    switch (type) {
        case 8:
            for(int l = 0; l < m1->size_n; l++){
                for(int i = 0; i < m2->size_m; i++){
                    int el = 0;
                    for(int j = 0; j < m1->size_m; j++){
                        el += *((int*)m1->matrix + l * m1->size_m + j) * (*((int*)m2->matrix + j * m2->size_m + i));
                    }
                    *((int*)res->matrix + l * m1->size_n + i) = el;
                }
            }
            break;
        case 36:
            if (m1->element_size == 4){
                for(int l = 0; l < m1->size_n; l++){
                    for(int i = 0; i < m2->size_m; i++){
                        float el = 0;
                        for(int j = 0; j < m1->size_m; j++){
                            el += (float)(*((int*)m1->matrix + l * m1->size_m + j)) * (*((float*)m2->matrix + j * m2->size_m + i));
                        }
                        *((float*)res->matrix + l * m1->size_n + i) = el;
                    }
                }
            }
            else{
                for(int l = 0; l < m1->size_n; l++){
                    for(int i = 0; i < m2->size_m; i++){
                        float el = 0;
                        for(int j = 0; j < m1->size_m; j++){
                            el += (*((float*)m1->matrix + l * m1->size_m + j)) * (float)(*((int*)m2->matrix + j * m2->size_m + i));
                        }
                        *((float*)res->matrix + l * m1->size_n + i) = el;
                    }
                }
            }
            break;
        case 64:
            for(int l = 0; l < m1->size_n; l++){
                for(int i = 0; i < m2->size_m; i++){
                    float el = 0;
                    for(int j = 0; j < m1->size_m; j++){
                        el += *((float *)m1->matrix + l * m1->size_m + j) * (*((float *)m2->matrix + j * m2->size_m + i));
                    }
                    *((float *)res->matrix + l * m1->size_n + i) = el;
                }
            }
            break;
        default:
            break;
    }
    return res;
}

Matrix *addition(Matrix *m1, Matrix *m2){
    int el_size_3 = m1->element_size <= m2->element_size ? m2->element_size : m1->element_size;// определяем размер элемента результирующей матрицы
    Matrix *res = create(el_size_3, m1->size_n, m1->size_m);
    int type = m1->element_size + m2->element_size;
    switch (type) {
        case 8:
            for(int i = 0; i < res->size_n * res->size_m; i++)
                *((int*)res->matrix + i) = *((int*)m1->matrix + i) + (*((int*)m2->matrix + i));
            break;
        case 36:
            if (m1->element_size == 4){
                for(int i = 0; i < res->size_n * res->size_m; i++)
                    *((float*)res->matrix + i) = (float)*((int*)m1->matrix + i) + (*((float*)m2->matrix + i));
            }
            else{
                for(int k = 0; k < res->size_n * res->size_m; k++)
                    *((float*)res->matrix + k) = *((float*)m1->matrix + k) + (float)*((int*)m2->matrix + k);
            }
            break;
        case 64:
            for (int k = 0; k < res->size_n * res->size_m; k++)
                *((float*)res->matrix + k) = *((float*)m1->matrix + k) + *((float*)m2->matrix + k);
            break;
        default:
            break;
    }
    return res;
}

Matrix *transpose(Matrix *m1){
    Matrix *res = create(m1->element_size, m1->size_m, m1->size_n);
    if (m1->element_size == 4){
        for(int i = 0; i < m1->size_n; i++){
            for(int j = 0; j < m1->size_m; j++){
                *((int*)res->matrix + j * res->size_m + i) = *((int*)m1->matrix + i * m1->size_m + j);
            }
        }
    }
    else{
        for(int i = 0; i < m1->size_n; i++){
            for(int j = 0; j < m1->size_m; j++){
                *((float *)res->matrix + j * res->size_m + i) = *((float *)m1->matrix + i * m1->size_m + j);
            }
        }
    }
    return res;
}

Matrix *lines_addition(Matrix *m1, int num_i, int num_p, float coefficient){
    //Matrix res = create(m1->element_size, m1->size_m, m1->size_n);
    Matrix *res = m1;
    for(int j = 0; j < m1->size_m; j++){
        *((float*)res->matrix + (num_i - 1) * res->size_m + j) += *((float*)res->matrix + (num_p - 1) * res->size_m + j) * coefficient;
    }
    return res;
}