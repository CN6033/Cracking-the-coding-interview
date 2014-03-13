#include <assert.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

/*错误的实现方式*/
void Delete_current_node1(struct Node **node_ptr)
{
	assert (*node_ptr != NULL);

	if (*node_ptr->next == NULL) {
		/*
		这是在试图处理最后一个节点，但这样实现错误。因为我们没法改变前一个节点的next值。
		按照这种实现方式，虽然释放了当前节点，且将当前节点指针赋值NULL，但前一个节点的
		next值将是一个非法的内存地址。
		*/
		free(*node_ptr);
		*node_ptr = NULL;
	} else {
		struct Node *temp_node = *node_ptr->next;
		*node_ptr->data = temp_node->data;
		*node_ptr->next = temp_node->next;
		free(temp_node);
	}
}

/*正确的实现方式*/
void Delete_current_node2(struct Node *node_ptr)
{
	/*无法删除链表最末节点*/
	assert (node_ptr != NULL && node_ptr->next != NULL);

	struct Node *temp_node = node_ptr->next;
	node_ptr->data = temp_node->data;
	node_ptr->next = temp_node->next;
	free(temp_node);
}

int main()
{
	/*Test*/

}
