#include <map>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* Find_cycle(struct Node* node)
{
	using namespace std;
	if (node == NULL)	return NULL;

	map<struct Node*, int> container;
	container[node] = 1;

	while (node->next && 
		container.find(node->next) == container.end()) {
		/*New node*/
		container[node->next] = 1;
		node = node->next;
	}

	return node->next;
}
