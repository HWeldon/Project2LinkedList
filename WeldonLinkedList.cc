#include <iostream>
using namespace std;

/* Struct */
struct NodeType
{
   int data;
   NodeType* next;
};

/* Class */
class NumberSet
{
   private:
      int length;
      NodeType* start;

   public:
      NumberSet();
      ~NumberSet();
      void MakeEmpty();
      int Size() const;
      void Add(int item);
      void Remove(int item);
      void Output();
};

/* Member Function Definitions */
NumberSet::NumberSet()
{
   length = 0;
   start = NULL;
}

// Add an element to the set
void NumberSet::Add(int item)
{
   NodeType* temp = new NodeType;
   temp -> data = item;
   temp -> next = start;
   start = temp;

   length++;
}

// Clean up the list in memory
void NumberSet::MakeEmpty()
{
   NodeType* temp;
   while(start != NULL)
   {
      temp = start;
      start = start -> next;
      delete temp;
   }
   length = 0;
}

// Destructor to clean memory
NumberSet::~NumberSet()
{
   MakeEmpty();
}

// Return the size (#nodes) of list
int NumberSet::Size() const
{
   return length;
}

// Display the data in the nodes
void NumberSet::Output()
{
   NodeType* temp = start;
   while(temp != NULL)
   {
      cout << temp -> data << endl;
      temp = temp -> next;
   }
}

// Remove an element from the set
void NumberSet::Remove(int item)
{
   if(start != NULL)
   {
      // If element is in the first node
      NodeType* temp = start;
      if(item == start -> data)
      {
         start = start -> next;
         delete temp;
         length--;
      }
      // If element is not in the first node
      else
      {
         // While the next element is not equal to the target
         while (temp -> next != NULL && (!(item == (temp -> next -> data))))
         {
            temp = temp -> next;
         }
         // Element found or element not in list
         NodeType* target = temp -> next;
         if(target != NULL)
         {
            temp -> next = target -> next;
            delete target;
            length--;
         }
      }
   }
}

/* Main Function */
int main()
{
   NumberSet ns;

   // Introduction
   cout << endl;
   cout << "Welcome to the Linked List version of NumberSet!" << endl;
   cout << endl;

   // Menu screen looping variable
	int userMenuChoice;

	// Menu screen loop
	do
   {
      // Menu text
      cout << "1) Add an element to the set" << endl;
		cout << "2) Remove an element from the set" << endl;
		cout << "3) Return the size of the set" << endl;
		cout << "4) Print the set" << endl;
		cout << "To perform an operation type 1,2,3, or 4 (enter 0 to quit): ";
		cin >> userMenuChoice;
		cout << endl;

		// Menu branches

		// add an element to the set
		if (userMenuChoice == 1)
		{
         cout << "Enter a positive integer: ";
		   int userInput;
		   cin >> userInput;
		   ns.Add(userInput);
		   cout << endl;
		}

		// remove an element from the set
		else if (userMenuChoice == 2)
		{
         cout << "Enter a positive integer: ";
		   int userInput;
		   cin >> userInput;
		   ns.Remove(userInput);
		   cout << endl;
		}

		// return size of set
		else if (userMenuChoice == 3)
		{
         cout << "Size is: " << ns.Size() << endl;
         cout << endl;
		}

		// output the set
		else if (userMenuChoice == 4)
		{
		  cout << "The set is: " << endl;
		  ns.Output();
		  cout << endl;
		}

		// close program, clean memory
		else if (userMenuChoice == 0)
		{
			ns.MakeEmpty();
			cout << "Closing program now." << endl;
			cout << endl;
		}

		// Check for incorrect input
		else
		{
			cout << "Invalid option entered. Please select 1,2,3,4,5 or 0" << endl;
			cout << endl;
		}
   } while (userMenuChoice != 0);

   return 0;
}
