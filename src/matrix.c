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
  // Initialize with zeros
  set_matrix_constant(m, 0.0);
  return m;
}

void free_matrix(matrix_t* m) {
  if (m->is_owner && m->data) {
    free(m->data);
  }
  free(m);
}

void set_matrix_constant(matrix_t* m, double v) {
  int size = get_matrix_size(m);
  for (int i = 0; i < size; ++i) {
    m->data[i] = v;
  }
}

void reshape_matrix(matrix_t* m, int rows, int cols) {
  assert(get_matrix_size(m) == rows * cols);
  m->rows = rows;
  m->cols = cols;
}

void realloc_matrix(matrix_t* m, int rows, int cols) {
  if (m->is_owner && m->data) {
    free(m->data);
  }
  m->rows = rows;
  m->cols = cols;
  m->data = (double*)malloc(sizeof(rows * cols));
  m->is_owner = true;
  set_matrix_constant(m, 0.0);
}

void print_matrix(const matrix_t* m) {
  for (int i = 0 ; i < m->rows; ++i) {
    for (int j = 0; j < m->cols; ++j) {
      printf("%g  ", get_matrix_elem(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}