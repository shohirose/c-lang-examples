#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

matrix_t* alloc_matrix(int rows, int cols) {
  matrix_t* m = (matrix_t*)malloc(sizeof(matrix_t));
  m->rows = rows;
  m->cols = cols;
  int size = rows * cols;
  m->data = (double*)malloc(sizeof(double) * size);
  m->is_owner = true;
  set_matrix_constant(m, 0.0);
  return m;
}

void free_matrix(matrix_t* m) {
  if (!m) {
    return;
  }
  assert(m->is_owner && "matrix m is not the owner!");
  if (m->data) {
    free(m->data);
  }
  free(m);
}

void set_matrix_constant(matrix_t* m, double v) {
  assert(m && "matrix m is not allocated!");
  int size = get_matrix_size(m);
  for (int i = 0; i < size; ++i) {
    m->data[i] = v;
  }
}

void reshape_matrix(matrix_t* m, int rows, int cols) {
  assert(m && "matrix m is not allocated!");
  assert(m->data && "matrix data is not allocated!");
  assert(get_matrix_size(m) == rows * cols);
  m->rows = rows;
  m->cols = cols;
}

void realloc_matrix(matrix_t* m, int rows, int cols) {
  if (!m) {
    m = (matrix_t*)malloc(sizeof(matrix_t));
    m->is_owner = true;
  }
  assert(m->is_owner && "matrix m is not the owner!");
  if (m->data) {
    free(m->data);
  }
  m->rows = rows;
  m->cols = cols;
  m->data = (double*)malloc(rows * cols * sizeof(double));
  set_matrix_constant(m, 0.0);
}

void print_matrix(const matrix_t* m) {
  if (m->rows != 1) {
    printf("[");
  }
  for (int i = 0; i < m->rows; ++i) {
    if (i == 0) {
      printf("[");
    } else {
      printf(" [");
    }
    for (int j = 0; j < m->cols - 1; ++j) {
      printf("%g  ", get_matrix_elem(m, i, j));
    }
    printf("%g]", get_matrix_elem(m, i, m->cols - 1));
    if (i != m->rows - 1) {
      printf("\n");
    }
  }
  if (m->rows != 1) {
    printf("]");
  }
  printf("\n");
}