#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if(s.length() == 0)
			return "";

		int MaxSize = 0;
		int MinIndex = 0;
		int MaxIndex = 0;
		int i = 0;

		int Max1,Max2,Min1,Min2,ret1,ret2,Max,Min;
		while(i < s.length())
		{
			ret1 = getSingleLongesetPalindrome(s , i , Min1 , Max1);
			ret2 = getDoubleLongesetPalindrome(s, i , Min2 , Max2);
			Max = ret1 > ret2 ? Max1:Max2;
			Min = ret1 > ret2 ? Min1:Min2;

			if(Max - Min + 1 > MaxSize)
			{
				MaxSize = Max - Min + 1;
				MaxIndex = Max;
				MinIndex = Min;
			}

			i++;
		}

		return s.substr(MinIndex , MaxSize );
	}

	int getSingleLongesetPalindrome(string& s , int i , int& MinIndex , int& MaxIndex)
	{
		MaxIndex = MinIndex = i;
		
		int MaxSize = s.length() > (2 * i + 1)? i:(s.length() - i - 1);
		int j = 0;
		while(j < MaxSize + 1 )
		{
			if(s[MinIndex] != s[MaxIndex])
				break;

			MinIndex --;
			MaxIndex ++;
			j ++;
		}

		if(j == 0)
			return 0;

		MinIndex ++;
		MaxIndex --;

		return (MaxIndex - MinIndex + 1); 
	}

	int getDoubleLongesetPalindrome(string& s , int i , int& MinIndex , int& MaxIndex)
	{
		if(i + 1 >= s.length())
			return 0;

		MaxIndex =  i + 1;
		MinIndex = i ;

		int MaxSize = s.length() > (2 * i + 2) ? i:(s.length() - i - 2);
		int j = 0;
		while(j < MaxSize + 1 )
		{
			if(s[MinIndex] != s[MaxIndex])
				break;

			MinIndex --;
			MaxIndex ++;
			j ++;
		}

		if(j == 0)
			return 0;

		MinIndex ++;
		MaxIndex --;

		return (MaxIndex - MinIndex + 1); 
	}

};

int main()
{
	string s1 = "1234565432112345";
	Solution s;
	string s2 = s.longestPalindrome(s1);
	cout<<s2.data()<<endl;
	return 0;
}