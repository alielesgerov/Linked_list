#include<iostream>
#include<Windows.h>
#include<string>
#include<assert.h>

class Level
{
	std::string name;
	std::string difficult;
public:
	Level():name(""),difficult("") {};
	Level(const std::string& name, const std::string difficult)
	{
		setName(name);
		setDifficult(difficult);
	}
	//Setter
	void setName(std::string name)
	{
		this->name = name;
	}
	void setDifficult(const std::string& difficult)
	{
		this->difficult = difficult;
	}
	//Getter
	std::string getName() const
	{
		return this->name;
	}
	std::string getdifficult() const
	{ 
		return this->difficult;
	}
};


template<typename T>
class Node {
public:
	T* data;
	Node* next;
};
template<typename T>
class LinkedList
{
	Node<T>* head;
public:
	LinkedList():head(nullptr){}
	Node<T>* getNode(size_t index)
	{
		Node<T>* temp = head;
		for (size_t i=0;i != index;i++)
		{
			temp = temp->next;
		}
		return temp;
	}
	//Add
	void pushFirst(T& data)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = &data;
		new_node->next = head;
		head = new_node;
		
	}
	void pushLast(T& data)
	{
		Node<T>* new_node = new Node<T>;
		Node<T>* last = head;
		new_node->data = &data;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			return;
		}
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_node;
	}
	void pushAfter(Node<T>* node,T& data)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = &data;
		new_node->next = node->next;
		node->next = new_node;
	}
	//Delete
	void deleteLast()
	{
		Node<T>* temp = head;
		Node<T>* last = head;
		while (last->next != NULL)
		{
			if (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			last = last->next;
		}
		if (temp != last)
		{
			delete last;
			temp->next = NULL;
		}
		else
		{
			delete head;
			head = nullptr;
		}
	}
	void deleteFirst()
	{	
		if (head!=NULL)
		{
			Node<T>* temp;
			temp = head;
			head = head->next;
		}
	}
	void deleteAfter(Node<T>*node)
	{
		Node<T>* temp;
		if (node->next != NULL)
		{
			temp = node->next;
			node->next=node->next->next;
		}
	}
	//Show
	void Show() const
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			std::cout << "===============================================\n";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			std::cout << "Name: ";
			SetConsoleTextAttribute(hConsole, 10);
			std::cout<< temp->data->getName() << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "difficult: ";
			SetConsoleTextAttribute(hConsole, 10);
			std::cout<< temp->data->getdifficult() << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
			temp = temp->next;
		}
	}
	//
	~LinkedList()
	{
		delete[]head;
	}
};


int main() 
{

	LinkedList<Level> linked_list;
	Level l1("Level1", "easy");
	Level l2("Level2", "normal");
	Level l3("Level3", "hard");
	Level l4("Level4", "impossible");
	Level l5("Level5", "GOD level");
	Level* level = new Level[4]{ l1,l2,l3,l4 };


	/*for (size_t i = 0; i < 4; i++)
	{
		linked_list.pushFirst(level[i]);
	}*/

	/*for (size_t i = 0; i < 4; i++)
	{
		linked_list.pushLast(level[i]);
	}*/
	
	//linked_list.deleteAfter(linked_list.getNode(1));
	//linked_list.pushAfter(linked_list.getNode(2),l5);
	//linked_list.deleteFirst();
	//linked_list.deleteLast();
	linked_list.Show();
	return 0;
}
