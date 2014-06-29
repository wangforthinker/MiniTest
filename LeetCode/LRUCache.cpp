#include <list>
#include <map>

using namespace std;


struct LRUNode
{
	int value;
	list<int>::iterator it;
};

class LRUCache{

private:
	list<int> key_list;
	map<int,LRUNode*> map_value;
	int cap;

public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		map<int,LRUNode*>::iterator it;
		LRUNode* node = 0;

		it = map_value.find(key);
		if(it == map_value.end())
			return -1;

		node = it->second;
		key_list.erase(node->it);
		key_list.push_front(key);
		node->it = key_list.begin();

		return node->value;
	}

	void set(int key, int value) {
		LRUNode* node = 0;

		if(map_value.find(key) != map_value.end())
		{
			node = map_value[key];
			node->value = value;

			key_list.erase(node->it);
			key_list.push_front(key);
			node->it = key_list.begin();

			return;
		}

		if(key_list.size() == cap)
		{
			int r = key_list.back();
			key_list.pop_back();
			node = map_value[r];
			delete node;
		}

		node = new LRUNode;
		node->value = value;

		key_list.push_front(key);
		node->it = key_list.begin();

		map_value.insert(pair<int,LRUNode*>(key,node));


	}
};

int main()
{
	LRUCache Lru(10);
	Lru.set(10,13);
	Lru.set(3,17);
	Lru.set(6,11);
	Lru.set(10,5);
	Lru.set(9,10);
	Lru.get(13);
	Lru.set(2,19);
	Lru.get(2);
	Lru.get(3);
	Lru.set(5,25);
	Lru.get(8);
	Lru.set(9,22);
	Lru.set(5,5);
	Lru.set(1,30);
	Lru.get(11);
	Lru.set(9,12);
	Lru.get(7);
	Lru.get(5);
	Lru.get(8);
	Lru.get(9);
	Lru.set(4,30);
	Lru.set(9,3);
	Lru.get(9);
	Lru.get(10);
	Lru.get(10);
	Lru.set(6,14);
	Lru.set(3,1);
	Lru.get(3);
	Lru.set(10,11);
	Lru.get(8);
	Lru.set(2,14);
	Lru.get(1);
	Lru.get(5);
	Lru.get(4);
	Lru.set(11,4);
	Lru.set(12,24);
	Lru.set(5,18);
	Lru.get(13);
	Lru.set(7,23);
	Lru.get(8);
	Lru.get(12);
	Lru.set(3,27);
	Lru.set(2,12);
	Lru.get(5);
	Lru.set(2,9);
	Lru.set(13,4);
	Lru.set(8,18);
	Lru.set(1,7);
	Lru.get(6);
	Lru.set(9,29);
	Lru.set(8,21);
	Lru.get(5);
	Lru.set(6,30);
	Lru.set(1,12);
	Lru.get(10);
	Lru.set(4,15);
	Lru.set(7,22);
	Lru.set(11,26);
	Lru.set(8,17);
	Lru.set(9,29);
	Lru.get(5);
	Lru.set(3,4);
	Lru.set(11,30);
	Lru.get(12);
	Lru.set(4,29);
	Lru.get(3);
	Lru.get(9);
	Lru.get(6);
	Lru.set(3,4);
	Lru.get(1);
	Lru.get(10);
	Lru.set(3,29);
	Lru.set(10,28);
	Lru.set(1,20);
	Lru.set(11,13);
	Lru.get(3);
	Lru.set(3,12);
	Lru.set(3,8);
	Lru.set(10,9);
	Lru.set(3,26);
	Lru.get(8);
	Lru.get(7);
	Lru.get(5);
	Lru.set(13,17);
	Lru.set(2,27);
	Lru.set(11,15);
	Lru.get(12);
	Lru.set(9,19);
	Lru.set(2,15);
	Lru.set(3,16);
	Lru.get(1);
	Lru.set(12,17);
	Lru.set(9,1);
	Lru.set(6,19);
	Lru.get(4);
	Lru.get(5);
	Lru.get(5);
	Lru.set(8,1);
	Lru.set(11,7);
	Lru.set(5,2);
	Lru.set(9,28);
	Lru.get(1);
	Lru.set(2,2);
	Lru.set(7,4);
	Lru.set(4,22);
	Lru.set(7,24);
	Lru.set(9,26);
	Lru.set(13,28);
	Lru.set(11,26);
}