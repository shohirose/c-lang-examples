#include "matrix.h"
#include "vector.h"

int main() {
  matrix_t* m = alloc_matrix(3, 3);
  print_matrix(m);

  set_matrix_constant(m, 1.0);
  print_matrix(m);

  set_matrix_elem(m, 1, 1, 2.0);
  print_matrix(m);

  reshape_matrix(m, 1, 9);
  print_matrix(m);

  free_matrix(m);

  vector_t* v = alloc_vector(4);
  print_vector(v);

  set_vector_constant(v, 1.0);
  print_vector(v);

  set_vector_elem(v, 3, 2.0);
  print_vector(v);

  free_vector(v);
}