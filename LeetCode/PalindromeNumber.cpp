#include <iostream>

using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if(x == 0)
			return true;

		bool IsNeg = false;
		if(x < 0)
		{
			IsNeg = true;
			x = -x;
		}

		int nx = 0;
		int temp = x;
		while(temp/10)
		{
			nx = nx * 10 + temp%10;
			temp = temp/10;

		}

		if(nx > INT_MAX/10)
			return false;
		else if(nx == INT_MAX/10)
		{
			int last = temp%10;
			if(IsNeg)
			{
				if(last > 8)
					return false;
			}
			else
			{
				if(last > 7)
					return false;
			}
		}

		nx = nx * 10 + temp%10;
		if(nx == x)
			return true;

		return false;

	}

};

int main()
{
	Solution s;
	s.isPalindrome(-2147447412);
}