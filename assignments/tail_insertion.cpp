/**
* @ProgramName: Homework-1
* @Author: Alexander Zeizinger
* @Description: 
*     The program creates a list of integers and possesses functions able to place new integers at both the beginning and end of the list, as well as print it.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 10 02 2017
*/

#include <iostream>
using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

class List
{
private:
    Node *Head;
    Node *Tail;
public:
    List()
    {
      Head = NULL;
      Tail = NULL;
    }

    /**
    * @FunctionName: FrontSert
    * @Description: 
    *     Adds an integer to the beginning of the list
    * @Params:
    *    int x - integer value passed in
    * @Returns:
    *    void
    */
    void FrontSert(int x)
    {
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;

      if(Head)
      {
        Temp->Next = Head;
      }

      Head = Temp;
      
      // head and tail become the same if list is empty
      if (!Tail)
      {
        Tail = Head;
      }
    }

/**
	* @FunctionName: EndSert
	* @Description:
	*     Adds an integer to the end of the list
	* @Params:
	*    int y - integer value passed in
	* @Returns:
	*    void
	*/
	void EndSert(int y) 
	{
		Node *Temp = new Node;
		Temp->Data = y;
		Temp->Next = NULL;

		if(Tail)
		{
			Tail->Next = Temp;
		}
		else
		{
			Head = Temp;
		}
		Tail = Temp;
	}

    /**
    * @FunctionName: PrintList
    * @Description: 
    *     Displays the values of the list in succession
    * @Params:
    *    None required
    * @Returns:
    *    void
    */
    void PrintList()
    {
      if(!Head)
      {
        cout << "Empty" << endl;
        return;
      }
      else
      {
        Node *Temp = Head;

        while(Temp != NULL)
        {
          cout << Temp->Data << "->";
          Temp = Temp->Next;
        }
      }
    }
};

int main()
{
    srand(97097807);
    List L;
    
    // 25 will be the last value inserted through the FrontSert function
    for(int i = 0; i < 10; i++)
    {
      L.FrontSert(rand()%100);
    }
    L.PrintList();
    cout << endl;
    
    // will add 43 to the end of the list
    L.EndSert(43);
    L.PrintList();
    cout << endl;
    
    // will add 61 to the front of the list
    L.FrontSert(61);
    L.PrintList();
    cout << endl;
    
    // will add 102 to the front of the list and 0 to the end
    L.FrontSert(102);
    L.EndSert(0);
    L.PrintList();
    
    return 0;
}
