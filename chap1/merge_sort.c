#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define Element_type int

static void Msort(Element_type [], Element_type [], int start, int end);
static void Merge(Element_type [], Element_type [], int left_pos, int right_pos, int right_end);

void Merge_sort(Element_type array[], int size)
{
	assert(array != NULL);
	assert(size > 0);

	Element_type *temp_array = (Element_type*)(malloc(size * sizeof(Element_type)));

	if (temp_array != NULL) {
		Msort(array, temp_array, 0, size - 1);
	} else {
		//Fatal error
	}
}

static void Msort(Element_type array[], 
	Element_type temp_array[], 
	int start, 
	int end)
{
	if (start >= end)	return;

	int center = (start + end) / 2;
	Msort(array, temp_array, start, center);
	Msort(array, temp_array, center + 1, end);
	Merge(array, temp_array, start, center + 1, end);
}

static void Merge(Element_type array[],
	Element_type temp_array[],
	int left_pos,
	int right_pos,
	int right_end)
{
	int left_end = right_pos - 1;
	int temp_pos = left_pos;
	int num_of_elements = right_end - left_pos + 1;

	while (left_pos <= left_end && right_pos <= right_end) {
		if (array[left_pos] <= array[right_pos]) {
			temp_array[temp_pos++] = array[left_pos++];
		} else {
			temp_array[temp_pos++] = array[right_pos++];
		}
	}

	while (left_pos <= left_end) {
		temp_array[temp_pos++] = array[left_pos++];
	}

	while (right_pos <= right_end) {
		temp_array[temp_pos++] = array[right_pos++];
	}

	int i = 0;
	for (; i< num_of_elements; ++i, --right_end) {
		array[right_end] = temp_array[right_end];
	}
}


int main()
{
	Element_type array[10] = {9,8,7,6,5,0,1,3,4,2};
	Merge_sort(array, 10);
	printf("%d\n", array[0]);
	printf("%d\n", array[1]);
	printf("%d\n", array[4]);
	printf("%d\n", array[8]);
	printf("%d\n", array[9]);
}