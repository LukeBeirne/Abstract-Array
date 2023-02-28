/*
 * This is the driver program to create an array of ints.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "abstract_array.h"

/*
 * Static function declarations.
 */
static void print_help(char *exec);
static void print_int(void *val);
static void get_max_val(void *val, void *priv);

int
main(int argc, char **argv)
{
	dims_t dims = { 3, 3 };
	int opt;

	/*
	 * We use srand() to make sure we always have the same
	 * array values.
	 */
	srand(3);

	/*
	 * Parsing user arguments.
	 */
	while ((opt = getopt(argc, argv, "x:y:h")) != -1) {
		switch (opt) {
		    	case 'x':
				dims.x = atoi(optarg);
				break;
			case 'y':
				dims.y = atoi(optarg);
				break;
			case 'h':
				print_help(argv[0]);
				exit(0);
			default: /* ? */
				print_help(argv[0]);
				exit(1);
		}
	}

	/*
	 * Allocating array.
	 */
	abs_array_t *arr = abs_array_create(dims, sizeof(int), print_int, NULL);


	/*
	 * Getting array dimensions.
	 */
	dims_t arr_dims = abs_array_get_dims(arr);
	
	/*
	 * Setting values in array with rand().
	 */
	for (int i = 0; i < arr_dims.x; i++) {
		for (int j = 0; j < arr_dims.y; j++) {
			int val = rand() % 100;
			abs_array_set_i_j(arr, i, j, &val);
		}
	}

	/*
	 * Printing out the array contents.
	 */
	printf("Array contents of ints:\n");
	abs_array_print(arr);
	printf("\n");

	/*
	 * Finding the middle column of the array and printing out the contents
	 * of the column.
	 */
	int mid_col = (arr_dims.y - 1) / 2;
	printf("Getting all values in array from column 1\n");
	for (int i = 0; i < arr_dims.x; i++) {
		int val;
		abs_array_get_i_j(arr, i, mid_col, &val);
		printf("Value at (%d, %d) is %d\n", i, mid_col, val);
	}

	/*
	 * Doubling the contents of the middle column of the array.
	 */
	printf("\nAbout to double all values in %d column\n", mid_col);
	for (int i = 0; i < arr_dims.x; i++) {
		int val;
		abs_array_get_i_j(arr, i, mid_col, &val);
		val *= 2;
		abs_array_set_i_j(arr, i, mid_col, &val);
	}

	/*
	 * Printing out the array contents.
	 */
	printf("Array contents of ints:\n");
	abs_array_print(arr);
	printf("\n");

	/*
	 * Finding and printing out the maximum value in the array.
	 */
	printf("Getting max value in array.\n");
	int max_val = 0;
	abs_array_apply_func(arr, get_max_val, &max_val);
	printf("Maximum value in array is: %d\n", max_val);

	/*
	 * Destroying the array.
	 */
	abs_array_destroy(arr);

	return (0);
}

/*
 * Static function definitions.
 */
void
print_help(char *exec)
{
    printf("%s -x x_dims -y y_dims\n", exec);
    printf("DEFAULTS: x_dim=3, y_dims=3\n");
}

void
print_int(void *val)
{
	int *value = (int *)val;
	printf("%5d", *value);
}

void
get_max_val(void *val, void *priv)
{
	int *max_val = (int *)priv;
	int *curr_val = (int *)val;

	if (*curr_val > *max_val)
		*(int *)priv = *curr_val;
}
