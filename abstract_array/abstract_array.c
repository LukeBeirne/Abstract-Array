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
	
	//Creates arr with size of x*y*element_size
	array->arr = (char *)malloc(dims.x*dims.y*elem_size);
	
	//Simply copies input values to struct values
	array->dims = dims;
	array->type_size = elem_size;
	array->print_fp = p_func;
	array->free_fp = f_func;
	return(array);
}

void
abs_array_destroy(abs_array_t *arr)
{
	//first frees char *arr in array struct
	//before freeing the array struct itself
	free(arr->arr);
	free(arr);
    return;
}



/*************************************************
 * Accessor functions.
*************************************************/
dims_t
abs_array_get_dims(abs_array_t *arr)
{
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
    return;
}



/*************************************************
 * Mutator functions.
*************************************************/
void
abs_array_set_i_j(abs_array_t *arr, int i, int j, void *val)
{
    return;
}



/*************************************************
 * Helper functions.
*************************************************/
void
abs_array_print(abs_array_t *arr)
{
	//Research function pointers
	//arr->print_fp;...?
    return;
}

void
abs_array_apply_func(abs_array_t *arr, apply_func apply, void *priv)
{
    return;
}
