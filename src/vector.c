#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

vector_t* alloc_vector(int size) {
  vector_t* vec = (vector_t*)malloc(sizeof(vector_t));
  vec->size = size;
  vec->data = (double*)malloc(sizeof(double) * size);
  vec->is_owner = true;
  set_vector_constant(vec, 0.0);
  return vec;
}

void free_vector(vector_t* vec) {
  if (vec->data && vec->is_owner) {
    free(vec->data);
  }
  free(vec);
}

void set_vector_constant(vector_t* vec, double v) {
  for (int i = 0; i < vec->size; ++i) {
    vec->data[i] = v;
  }
}

void realloc_vector(vector_t* vec, int size) {
  if (vec->data && vec->is_owner) {
    free(vec->data);
  }
  vec->size = size;
  vec->data = (double*)malloc(sizeof(double) * size);
  vec->is_owner = true;
  set_vector_constant(vec, 0.0);
}

void print_vector(const vector_t* vec) {
  for (int i = 0; i < vec->size; ++i) {
    printf("%g\n", get_vector_elem(vec, i));
  }
  printf("\n");
}