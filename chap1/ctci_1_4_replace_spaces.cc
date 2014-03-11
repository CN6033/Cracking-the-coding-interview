void Replace_spaces(char str[], 
	int length/*使用题中给出的条件做为函数参数*/)
{
	int count_space = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			++count_space;
		} 
	}

	int new_length = length + count_space * 2;

	for (int i = length;/*字符串末尾‘\0’也需要被复制*/
		i >= 0; --i) {
		if (str[i] == ' ') {
			str[new_length] = '0';
			str[new_length - 1] = '2';
			str[new_length - 2] = '%';
			new_length -= 3;
		} else {
			str[new_length] = str[i];
			--new_length;
		}
	}
}
