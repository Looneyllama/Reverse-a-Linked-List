
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Node Class
class Node{
	public:
		string* tokens;
		size_t num_tokens;
		Node* next;
};


// List Class
class List{
	public:
		List() { head = NULL;}
		void begin_insert(string tweet); //inserts at head
		void end_insert(string tweet); //inserts at end
		void switch_order(); //swaps order of list
		void print_list(); //prints list
	private:
		Node* head;
};

int main(){
	ifstream file("train_text.txt");
	List first;
	List second;
	string line;

	// grabs tweets from text file and runs them through the functions begin_insert, and end_insert
	while(getline(file,line)){
		first.begin_insert(line);
		second.end_insert(line);
	}

	//Displays first List
	cout << "First List using begin_insert: " << endl;
	first.print_list();

	// Displays second List
	cout << endl << endl << "Second List using end_insert: " << endl;
	second.print_list();

	//Displays swapped List
	first.switch_order();
	cout << endl << endl << "Switched_order of the first List: " << endl;
	first.print_list();

}

//used to swap List
void List::switch_order(){
	Node* current = head;
	Node* prev = NULL, *next = NULL;

	//traverse through List swamping Nodes
	while(current != NULL){
		next = current->next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

//inserts Node at head
void List::begin_insert(string line){

	// used to count the number of spaces
	size_t spaceCount = 0;
	for(int x = 0; x < line.length();x++){
		if(line[x] == ' ')
			spaceCount++;
	}

	spaceCount++; // adds one extra for the last word not having a space
	string* array = new string[spaceCount];
	stringstream ss(line); // used to make it where getline can be used to seprate the words into an array by spaces
	string temp;

	int i = 0;
	//adds words to array
	while(getline(ss, temp,' ')){
		array[i] = temp;
		i++;
	}

	//process to add data to the node and then place it at the head
	Node* newNode = new Node();
	newNode-> tokens = array;
	newNode-> num_tokens = spaceCount;
	newNode-> next = head;
	head = newNode;



}

//inserts at end
void List::end_insert(string line){
	//used to count the number of spaces
	size_t spaceCount = 0;
	for(int x = 0; x < line.length();x++){
		if(line[x] == ' ')
			spaceCount++;
	}

	spaceCount++;
	string* array = new string[spaceCount];
	stringstream ss(line); // used to make it where getline can be used to seprate the words into an array by spaces
	string temp;

	int i = 0;
	// adds word to array
	while(getline(ss, temp,' ')){
		array[i] = temp;
		i++;
	}

	Node* newNode = new Node();
	newNode-> tokens = array;
	newNode-> num_tokens = spaceCount;
	newNode-> next = NULL;

	// if head is pointing to nothing it adds node to the front
	if(head == NULL){
		newNode-> next = head;
		head = newNode;
	}
	else{
		Node* flag = head;
		// run through all the way to the back of the List
		while(flag->next != NULL)
			flag = flag->next;
		//adds node to end of list
		flag->next = newNode;
	}
}

// prints out list
void List::print_list(){

	Node* currNode = head;
	// runs until the node its at is pointing at nothing
	while(currNode != NULL){
		int size = (currNode-> num_tokens);
		// runs through the size of that node
		for(int x = 0;x < size;x++){
			cout << currNode->tokens[x] << " ";
		}
		// advances to next node
		currNode = currNode->next;
		cout << endl;
	}
}



























