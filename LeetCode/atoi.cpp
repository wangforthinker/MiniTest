#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		if(str == NULL || *str == '\0')
			return 0;

		char c;
		char buf[12];
		memset(buf , 0 , 12);
		bool IsNegative = false;
		bool IsMaxNum = false;
		bool IsSignAllowed = true;
		int sum = 0;

		do 
		{
			c = *str;
			if(c == '\0')
				return 0;

		} while (c == ' '&& (str ++));

		if(c == '-' || c == '+')
		{
			if(c == '-')
				IsNegative = true;

			str ++;
			c = *str;

			if(c == '\0' || c == ' ')
				return 0;
		}

		while(c == '0')
		{
			str++;
			c = *str;
		}

		if(c == '\0' || c == ' ')
			return 0;

		do 
		{
			if(c < '0' || c > '9')
				break;

			if(sum < 11)
				buf[sum++] = c;

		} while ((str++) && (c = *str) != '\0' );

		if(sum == 0)
			return 0;

		bool IsMaxValidDigit = false;
		
		if(sum == 10)
		{
			IsMaxValidDigit = true;
			sum --;
		}
		else if(sum == 11)
		{
			IsMaxNum = true;
		}

		int ret = 0;

		if(!IsMaxNum)
		{	
			int i = sum;
			while( i > 0)
			{
				ret += charToInt(buf[sum - i]) * Mul(i-1 ,10);
				i--;
			}

			if(IsMaxValidDigit)
			{
				if(ret > INT_MAX/10)
				{
					IsMaxNum = true;
				}
				else if(ret == INT_MAX/10)
				{
					if(IsNegative && buf[9] > '7')
						IsMaxNum = true;
					else if(!IsNegative && buf[9] > '6')
						IsMaxNum = true;

				}

				if(!IsMaxNum)
				{
					ret = ret * 10;
					ret += charToInt(buf[9]);
				}

			}

		}

		if(IsMaxNum)
		{
			if(IsNegative)
				return INT_MIN;

			return INT_MAX;
		}

		if(IsNegative)
		{
			ret = -ret;
		}

		return ret;
	}

	int Mul(int n , int num)
	{
		if(n == 0)
			return 1;

		return num * Mul(n-1 , num);
	}

	int charToInt(char c)
	{
		return (c - '0');
	}
};

int Token_Descapuslate(char*** OutData)
{
	char** s = *OutData;
	memset(s[0] , 0 , 4);
	memset(s[1] , 0 , 4);
	memcpy(s[0] , "123" , 3);
	memcpy(s[1] , "456" , 3);

	return 0;
}

//int main()
//{
//	Solution s;
//	char* c = "  21474836479 ";
//	int r = s.atoi(c);
//	cout << r <<endl;
//	return 0;
//}