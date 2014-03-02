void reverse(const char* src, char des[], int des_length)
{
	assert(des != NULL);
	assert(src != des);
	assert(strlen(src) + 1 <= des_length);

	int length = strlen(src);
	int index = length;
	while(index) {
		//des[length - index] = src[index--]
		des[length - index] = src[index - 1];
		--index;
	}
	des[length] = '\0';
}
