/*
 * 首先应确定所处理问题的范围，即构成字符串的字符集有多大，
 * 这也许才是面试官关注的重点。
 * 
 * 假设字符集为256个ASCII码。
 */
bool Is_unique(string str)
{
	bool char_set[256];
	memset(char_set, 0, sizeof(char_set));
	int length = str.length();
	for (int i = 0; i < length; ++i) {
		int index = (int)str[i];
		if (char_set[index]) return false;
		char_set[index] = true;
	}
	return true;
}
