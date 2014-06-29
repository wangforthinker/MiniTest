#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

struct node{
	int value;
	int index;
};

bool ComNode(const node &a, const node &b)
{
	if(a.value < b.value)
		return true;
	else
		return false;
}

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> ret;
		if(numbers.size() < 2)
			return ret;

		vector<node> vec_node; 

		int i = 0;
		while(i < numbers.size())
		{
			node nod;
			nod.index = i+1;
			nod.value = numbers[i];
			vec_node.push_back(nod);
			i++;
		}

		sort(vec_node.begin(),vec_node.end(),ComNode);
		
		int first = 0;
		int last = vec_node.size() - 1;
		while(first < last)
		{
			int temp = vec_node[first].value + vec_node[last].value;
			if(temp == target)
				break;
			else if(temp < target)
				first++;
			else
				last--;

		}

		if(first<last)
		{
			if(vec_node[first].index < vec_node[last].index)
			{
				ret.push_back(vec_node[first].index);
				ret.push_back(vec_node[last].index);
			}
			else
			{
				ret.push_back(vec_node[last].index);
				ret.push_back(vec_node[first].index);
			}
		}

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(6);

	int target = 9;
	vector<int> r = s.twoSum(vec,target);

	if(r.size() == 2)
		cout<<"target "<<target<<",index:"<<r[0]<<","<<r[1]<<endl;

	return 0;

}