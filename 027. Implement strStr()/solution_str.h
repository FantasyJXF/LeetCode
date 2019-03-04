class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle.empty()) return 0;
		
		int m = haystack.length(), n = needle.length();
		if(m < n)
			return -1;
		
		for(int i = 0; i < m - n; i++)
		{
			int j = 0;
			for(int j = 0; j < n; j++)
			{
				if(haystack[i+j] != needle[j]) 
					break;
			}
			
			if(n == j)
				return i;
		}
		
        return -1;
    }
};
