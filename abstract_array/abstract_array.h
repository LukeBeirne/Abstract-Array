/*
 * Abstract array
 *
 * This is the interface to using the abstract array. With an abstract
 * array, any data type can be stored and retrieved from it. All data
 * that is stored in the array is copied to and from it. So it makes
 * deep copies of everything.
 */

#ifndef ABSTRACT_ARRAY
#define ABSTRACT_ARRAY

#include <stdlib.h>
#include <stdio.h>

/*
 * Function pointer typedefs
 */
typedef void (*print_func)(void *);
typedef void (*free_func)(void *);
typedef void (*apply_func)(void *, void *);

/*
 * Dims struct. At the moment we only allow the array to be 2-dimensional.
 * This struct is used to set and retrieve the dimensions of the array.
 */
typedef struct dims
{
    int x;
    int y;
} dims_t;

typedef struct abs_array_s
{
	dims_t dims;		/* Array dimensions */
	char *arr;		/* Contiguous region data is stored in */
	size_t type_size;	/* Size of each element in array */
	print_func print_fp;	/* Print function for the array elements */
	free_func free_fp;	/* Free function for the array elements */
} abs_array_t;

/*
 * Allocation and deallocation functions.
 */
abs_array_t *abs_array_create(dims_t dims, size_t elem_size,
    print_func p_func, free_func f_func);
void abs_array_destroy(abs_array_t *arr);

/*
 * Accessor functions.
 * NOTE: get_dims returns { 0, 0 } on error
 */
dims_t abs_array_get_dims(abs_array_t *arr);
void abs_array_get_i_j(abs_array_t *arr, int i, int j, void *ret);

/*
 * Mutator functions.
 * NOTE: The array makes copies of all data passed to set_i_j. So it is the
 * users responsibility to free any val set that was dynamically allocated!
 */
void abs_array_set_i_j(abs_array_t *arr, int i, int j, void *val);

/*
 * Helper functions.
 */
void abs_array_print(abs_array_t *arr);
void abs_array_apply_func(abs_array_t *arr, apply_func apply, void *priv);

#endif /* ABSTRACT_ARRAY */
