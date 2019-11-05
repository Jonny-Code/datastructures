//Jon Sledge
//COP2535.001
//Project 7

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>


//structure
struct EmployeeInfo
{
	int IDnum;
	std::string name;

	EmployeeInfo(int phone = 0, std::string name = "") {
		this->IDnum = phone;
		this->name = name;
	}
};

class BST
{
	class BTreeNode
	{
	public:
		BTreeNode(EmployeeInfo x, BTreeNode *leftp = NULL,
			BTreeNode *rightp = NULL) {
			value = x;
			left = leftp;
			right = rightp;
		}
		EmployeeInfo value;
		BTreeNode *left, *right;
	};
	//binary search tree declaration
public:
	void insert(EmployeeInfo x);
	BST() { tree = NULL; }

public:
	BTreeNode *tree;
};


//operator overload <
bool operator < (EmployeeInfo x, EmployeeInfo y) {
	return x.IDnum < y.IDnum;
}

//overload operator ==
bool operator == (EmployeeInfo x, EmployeeInfo y) {
	return x.IDnum == y.IDnum;
}

//overload operator <<
std::ostream& operator << (std::ostream &out, EmployeeInfo e) {
	std::cout << "Phone: " << e.IDnum << "\tName: " << e.name;
	return out;
}

//BST insert
void BST::insert(EmployeeInfo x) {
	if (tree == NULL) {
		tree = new BTreeNode(x);
		std::cout << x << std::endl;
		system("pause");
		return;
	}

	BTreeNode *p = tree;
	while (p != NULL) {
		if (x < p->value) {
			if (p->left == NULL) {
				p->left = new BTreeNode(x);
				std::cout << x << std::endl;
				system("pause");
				return;
			}
			else
				p = p->left;
		}
		else {
			if (p->right == NULL) {
				p->right = new BTreeNode(x);
				std::cout << x << std::endl;
				system("pause");
				return;
			}
			else
				p = p->right;
		}
	}
}

//-----------------driver----------------//

int main()
{
	BST tree1;

	std::string line;
	std::ifstream inputFile;
	std::vector<int> numbers;
	std::vector<std::string> names;

	inputFile.open("employee.txt");

	while (getline(inputFile, line)) {
		std::string first, second, last;
		std::istringstream iss(line);

		getline(iss, first, '\t');
		getline(iss, second, '\t');
		getline(iss, last, '\t');

		second += " ";
		second += last;

		numbers.push_back(stoi(first));
		names.push_back(second);
	}
	
	for (int i = 0; i < numbers.size(); i++)
	{
		EmployeeInfo obj(numbers[i], names[i]);
		tree1.insert(obj);
		system("pause");
	}

	return 0;
}