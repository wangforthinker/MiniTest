#include <iostream>
class Solution {
public:
	bool isMatch(const char *s, const char *p) {

		const char* str,*ptr;
		bool star = false;

		for(str = s, ptr = p; *str != '\0'; str++, ptr++)
		{
			switch(*ptr)
			{
			case '?':
				break;

			case '*':
				star = true;

				s = str;
				p = ptr;
				while(*p == '*') p++;
				if(*p == '\0')
					return true;

				ptr = p - 1;
				str  = s - 1;
				break;

			default:
				if(*ptr != *str)
				{
					if(!star)
						return false;

					ptr = p - 1;
					s ++ ;
					str = s - 1;
				}
			}
		}
		
		while(*ptr == '*')
			ptr ++;

		if(*ptr != '\0')
			return false;
		return true;
	}
};

int main()
{
	char* s = "b";
	char* p = "?*?";
	Solution sn;
	sn.isMatch(s,p);
}