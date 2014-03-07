void reverse(const char* src, char des[], int des_length)
{
	assert(des != NULL);
	assert(src != des);
	assert(strlen(src) + 1 <= des_length);

	int length = strlen(src);
	int index = length;
	while (index) {
		//des[length - index] = src[index--]
		des[length - index] = src[index - 1];
		--index;
	}
	des[length] = '\0';
}

void reverse2(char *str)
{
	if (str == NULL)	return;

	int length_str = strlen(str);

	int left_pos = 0;
	int right_pos = length_str - 1;

	while (left_pos < right_pos) {
		//swap
		char tmp = str[left_pos];
		str[left_pos] = str[right_pos];
		str[right_pos] = tmp;

		++left_pos;
		--right_pos;
	}
}
