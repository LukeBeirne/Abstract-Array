#include "abstract_array.h" 
#include <string.h>

/*************************************************
 * Allocation and deallocation functions.
*************************************************/
abs_array_t *
abs_array_create(dims_t dims, size_t elem_size, print_func p_func, free_func f_func)
{
	//Creates array struct
	abs_array_t *array = (abs_array_t *)malloc(sizeof(abs_array_t));
	
	//Simply copies input values to struct values
	array->dims = dims;
	array->type_size = elem_size;
	array->print_fp = p_func;
	array->free_fp = f_func;
	
	//Creates arr with size of x*y*element_size
	array->arr = (char *)malloc(dims.x*dims.y*elem_size);
	
	return(array);
}

void
abs_array_destroy(abs_array_t *arr)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into destroy function");
		return;
	}
	if(arr->free_fp == NULL) {
		fprintf(stderr, "Invalid free function in array struct");
		return;
	}
	/*
	 * first frees char *arr in array struct
	 * using the free function pointer in the struct
	 * before freeing the array struct itself
	 */
	arr->free_fp(arr->arr);
	free(arr);
    return;
}



/*************************************************
 * Accessor functions.
*************************************************/
dims_t
abs_array_get_dims(abs_array_t *arr)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into get_dims function");
		dims_t dims = { 0, 0 };
		return(dims);
	}
	//creates a dims struct to store
	//x and y before returning it
	dims_t dims;
	dims.x = arr->dims.x;
	dims.y = arr->dims.y;
	return(dims);
}

void
abs_array_get_i_j(abs_array_t *arr, int i, int j, void *ret)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into get_i_j function");
		return;
	}
	dims_t dims = abs_array_get_dims(arr);
	ret = &arr->arr[i*dims.y + j];
    return;
}



/*************************************************
 * Mutator functions.
*************************************************/
void
abs_array_set_i_j(abs_array_t *arr, int i, int j, void *val)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into set_i_j function");
		return;
	}
	dims_t dims = abs_array_get_dims(arr);
	arr->arr[i*dims.y + j] = *(char *)val;
    return;
}



/*************************************************
 * Helper functions.
*************************************************/
void
abs_array_print(abs_array_t *arr)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into print function");
		return;
	}
	if(arr->print_fp == NULL) {
		fprintf(stderr, "Invalid print function in array struct");
		return;
	}
	
	/*
	 * iterates through array and
	 * prints each element using
	 * print function pointer in struct
	 */
	dims_t dims = abs_array_get_dims(arr);
	for (int i = 0; i < dims.x; i++) {
		for (int j = 0; j < dims.y; j++) {
			arr->print_fp(arr);			
		}
	}
    return;
}

void
abs_array_apply_func(abs_array_t *arr, apply_func apply, void *priv)
{
	//error checking
	if(arr == NULL) {
		fprintf(stderr, "Invalid array into apply function");
		return;
	}
	if(apply == NULL) {
		fprintf(stderr, "Invalid apply function");
		return;
	}
	
    return;
}
