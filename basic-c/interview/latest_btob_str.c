	char* longestPalindrome(char* s)
	{
		int len = strlen(s);
		if (len <= 1) { return s; }
		int start = 0;
		int maxlen = 0;
		//i表示中间元素下标
		for (int i = 1; i < len; i++)
		{
			//偶数长度
			int low = i - 1;
			int high = i;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
			//奇数长度
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
		}
		char *arr = (char *)malloc(sizeof(int) * (maxlen * 2));
		int i = 0;
		for (; i < maxlen; i++)
		{
			arr[i] = s[start++];
		}
		arr[i] = '\0';
		return arr;
	}

