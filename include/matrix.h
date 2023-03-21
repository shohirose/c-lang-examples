#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <stdbool.h>

typedef struct {
  int rows;       // Number of rows
  int cols;       // Number of columns
  double* data;   // Row-major memory layout
  bool is_owner;  // If this object owns the data or not
} matrix_t;

static inline double get_matrix_elem(const matrix_t* m, int i, int j) {
  assert(m && i < m->rows && j < m->cols);
  return m->data[i * m->cols + j];
}

static inline void set_matrix_elem(matrix_t* m, int i, int j, double v) {
  assert(m && i < m->rows && j < m->cols);
  m->data[i * m->cols + j] = v;
}

static inline int get_matrix_size(const matrix_t* m) {
  return m->rows * m->cols;
}

matrix_t* alloc_matrix(int rows, int cols);

void free_matrix(matrix_t* m);

void set_matrix_constant(matrix_t* m, double v);

// Reshape a given matrix
//
// The size of the old and new matrix must be the same
// because this function does not allocate any memory.
// The stored data will remain the same.
void reshape_matrix(matrix_t* m, int rows, int cols);

// Reallocate a given matrix
//
// This allows users to set a new matrix to a given pointer.
// The pointer to the old data in the matrix will be freed.
void realloc_matrix(matrix_t* m, int rows, int cols);

// Print matrix data to stdout
void print_matrix(const matrix_t* m);

#endif  // MATRIX_H