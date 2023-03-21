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

void free_vector(vector_t* v) {
  if (!v) {
    return;
  }
  assert(v->is_owner && "vector v is not the owner!");
  if (v->data) {
    free(v->data);
  }
  free(v);
}

void set_vector_constant(vector_t* v, double value) {
  assert(v && "vector vec is not allocated!");
  assert(v->data && "data of vector vec is not allocated!");
  for (int i = 0; i < v->size; ++i) {
    v->data[i] = value;
  }
}

void realloc_vector(vector_t* v, int size) {
  if (!v) {
    v = (vector_t *)malloc(sizeof(double) * size);
    v->is_owner = true;
  }
  assert(v->is_owner && "vector v is not the owner!");
  if (v->data) {
    free(v->data);
  }
  v->size = size;
  v->data = (double*)malloc(sizeof(double) * size);
  set_vector_constant(v, 0.0);
}

void print_vector(const vector_t* v) {
  printf("[");
  for (int i = 0; i < v->size - 1; ++i) {
    printf("%g ", get_vector_elem(v, i));
  }
  printf("%g]\n", get_vector_elem(v, v->size - 1));
}