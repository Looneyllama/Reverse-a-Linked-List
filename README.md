# Reverse-a-Linked-List
A project for my C++ Class. We are asked to turn tweets into a linked list and then reverse it.


Twitter data has been extensively used in training machine learning algorithms to learn the structure of sentences in what is called language modeling in the field of Natural Language Processing (NLP). Typically, each sentence is broken into a set of tokens and the tokens are sequentially processed. The file train_text.txt has a number of tweets, one tweet per line. Note that, each tweet has different number of words.
The objective of this project is to create and manipulate linked lists using the following node class.
class node {
   public:
   string* tokens;
   size_t num_tokens;
   node* next;
};
You can suitably modify and use the code from the book or the PowerPoint slides for Chapter 9 to write the linked list class (called List in the PowerPoint). 
Create a member function begin_insert for the List class that takes a string called tweet as a parameter. In begin_insert, split the tweet into a dynamic array of individual tokens. Store the tokens array along with its length in a node and add the node to the beginning of the linked list.
Create a member function end_insert for the List class that takes a string called tweet as a parameter. In end_insert, split the tweet into a dynamic array of individual tokens. Store the tokens array along with its length in a node and add the node to the end of the linked list.
Create a member function switch_order for the List class that switches the order of the nodes in the linked list. This means what was at the end of the linked list should be at the beginning and so on.
Create a member function print_list that will print the tweets in the linked list one per line starting from the head node.
Write a main function that reads the file train_text.txt line by line and inserts the tweet in a linked list using begin_insert. Read the file again and insert the tweets using end_insert in another linked_list.
Print the tweets from both lists.
Call switch_order on the first linked list and then print the tweets on it.


