#include <assert.h>
#include <string.h>
#include <stdio.h>

#define MAX_CHAR 255

void Compress(char src[], char des[], int length_des)
{
	assert(src != des);
	assert(length_des >= strlen(src));

	char last_char = src[0];
	int count = 1;
	int i = 1, j = 0;
	int length_src = strlen(src);

	for (; i < length_src && j < length_src; ++i) {
		if (src[i] == last_char) {
			++count;
		} else {
			/*注意char类型的范围为0 - 255. */
			assert(count <= MAX_CHAR);
			des[j] = last_char;
			des[j + 1] = count;
			j += 2;

			last_char = src[i];
			count = 1;
		}
	}
	des[j] = last_char;
	des[j + 1] = count;
	j+= 2;

	if (j >= length_src) {
		/*压缩失败. */
		strncpy(des, src, length_src + 1);
	} else {
		des[j] = '\0';
	}
}

int main()
{
	/*Test*/
	char src[12] = "aabcccccaaa";
	char des[12] = {0};
	Compress(src, des, 12);
	printf("%s\n", src);
	printf("%s\n", des);

	char src1[12] = "abca";
	char des1[12] = {0};
	Compress(src1, des1, 12);
	printf("%s\n", src1);
	printf("%s\n", des1);
}
