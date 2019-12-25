/*
* @Atuthor: lwl
* @Date: 2019-12-25
* @Description: �Ҷ������нڵ�ĺ�̽ڵ� & ǰ���ڵ� ʱ�临�Ӷ� O(1) �ռ临�Ӷ� O(1)
*/

#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* parent;
	Node* left;
	Node* right;
	Node(int value) {
		val = value;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

/*
*             ** �Һ�̽ڵ������ **
* 1. ����ڵ�����������������������ڵ���Ǻ�̽ڵ�
* 2. ����ڵ������������������ҵ����ڵ������Ϊ���ڵ�ĵ�һ���ڵ㣬���ظ��ڵ�
* �ĵã���ʵ��������� ��-��-�� ������Ӧ��
*/
class CFindSucceedNode {
private:
	Node* getMostLeftNode(Node* node) {
		Node* cur = nullptr;
		while (node != nullptr) {
			cur = node;
			node = node->left;
		}
		return cur;
	}

public:
	void findSucceed(Node* node) {
		if (node == nullptr) {
			return;
		}
		Node* cur = nullptr;
		if (node->right != nullptr) {
			cur = getMostLeftNode(node->right);
		}
		else {
			Node* tmp = node;
			while (tmp->parent != nullptr) {
				if (tmp->parent->left == tmp) {
					cur = tmp->parent;
					break;
				}
				tmp = tmp->parent;
			}
		}
		cout << "Succeed-Node: " << node->val << "-" << (cur == nullptr ? -1 : cur->val) << endl;
	}
};

/*
* ** ��ǰ���ڵ������ **
* 1. ����������������������ҵĽڵ����ǰ���ڵ�
* 2. ��������������������ҵ����ڵ���������Ǳ��ڵ�ĵ�һ���ڵ㣬���ظ��ڵ�
*  �ĵã�������� ��-��-�� ������Ӧ��
*/
class CFindPercursorNode {
private:
	Node* getMostRightNode(Node* node) {
		Node* cur = nullptr;
		while (node != nullptr) {
			cur = node;
			node = node->right;
		}
		return cur;
	}

public:
	void findPercursor(Node* node) {
		if (node == nullptr) {
			return;
		}
		Node* cur = nullptr;
		if (node->left != nullptr) {
			cur = getMostRightNode(node->left);
		}
		else {
			Node* tmp = node;
			while (tmp->parent != nullptr) {
				if (tmp->parent->right == tmp) {
					cur = tmp->parent;
					break;
				}
				tmp = tmp->parent;
			}
		}
		cout << "Percursor-Node: " << node->val << "-" << (cur == nullptr ? -1 : cur->val) << endl;
	}
};

class CComparator {
private:
	Node* head;
	CFindSucceedNode findSucceedNode;
	CFindPercursorNode findPercursorNode;

private:
	void generalBiTree() {
		head = new Node(6);
		head->parent = nullptr;
		head->left = new Node(3);
		head->left->parent = head;
		head->left->left = new Node(1);
		head->left->left->parent = head->left;
		head->left->left->right = new Node(2);
		head->left->left->right->parent = head->left->left;
		head->left->right = new Node(4);
		head->left->right->parent = head->left;
		head->left->right->right = new Node(5);
		head->left->right->right->parent = head->left->right;
		head->right = new Node(9);
		head->right->parent = head;
		head->right->left = new Node(8);
		head->right->left->parent = head->right;
		head->right->left->left = new Node(7);
		head->right->left->left->parent = head->right->left;
		head->right->right = new Node(10);
		head->right->right->parent = head->right;
	}

	void printPre(Node* node) {
		if (node != nullptr) {
			cout << node->val << "-" << (node->parent == nullptr ? -1 : node->parent->val) << " ";
			printPre(node->left);
			printPre(node->right);
		}
	}

	void printIn(Node* node) {
		if (node != nullptr) {
			printIn(node->left);
			cout << node->val << "-" << (node->parent == nullptr ? -1 : node->parent->val) << " ";
			printIn(node->right);
		}
	}

public:
	void runComparator() {
		generalBiTree();
		cout << "In-Order: ";
		printIn(head);
		cout << endl;
		findSucceedNode.findSucceed(head->left);
		findPercursorNode.findPercursor(head->left);
	}
};

int main() {
	CComparator comparator;
	comparator.runComparator();
	system("pause");
	return 0;
}