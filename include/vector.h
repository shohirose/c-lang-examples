#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include <stdbool.h>

// Row vector
typedef struct {
  int size;
  double* data;
  bool is_owner;      // If this object owns the data or not
} vector_t;

static inline double get_vector_elem(const vector_t* vec, int i) {
  assert(vec && i < vec->size);
  return vec->data[i];
}

static inline void set_vector_elem(vector_t* vec, int i, double v) {
  assert(vec && i < vec->size);
  vec->data[i] = v;
}

vector_t* alloc_vector(int size);

void free_vector(vector_t* vec);

void set_vector_constant(vector_t* vec, double v);

// Reallocate a given vector
void realloc_vector(vector_t* vec, int size);

// Print vector data to stdout
void print_vector(const vector_t* vec);

#endif  // VECTOR_H