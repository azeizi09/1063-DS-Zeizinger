/**
* @ProgramName: Infix Calculator
* @Author: Alexander Zeizinger 
* @Description: 
*     This program receives an equation, converts the equation from infix to postfix, and then calculates 
 the output before displaying the correct result for the user to see.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 13 03 2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


/**
* @FunctionName: Queue
* @Description: 
*     Implementation of a char queue
*/
class Queue
{
  private:
  //////////////////////////////////////////////////////
  int ArraySize;
  char *Q;
  int Front;
  int Rear;
  int NumItems;

  public:
  //////////////////////////////////////////////////////
  /**
  * @FunctionName: Queue
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial queue size
  * @Returns:
  *    void
  */
  Queue(int insize)
  {
    ArraySize = insize;
    Q = new char[ArraySize];
    Front = Rear = NumItems = 0;
  }

  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c)
  {
    if(Full())
    {
      cout<<"Queue Full!"<<endl;
      return;
    }
    Q[Rear] = c;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return;
  }

  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop()
  {
    if(Empty())
    {
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }

  /**
  * @FunctionName: printQueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintQueue()
  {
    for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%ArraySize)
    {
      cout<<Q[i]<<" ";
    }
    cout<<endl;
  }

  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty()
  {
    return (NumItems == 0);
  }

  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full()
  {
    return (NumItems == ArraySize);
  }
};


/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a char stack
*/
class Stack
{
  private:
  //////////////////////////////////////////////////////
  char *S;
  int top;
  int size;

  public:
  //////////////////////////////////////////////////////
  /**
  * @FunctionName: Stack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  Stack(int insize)
  {
    size = insize;
    top = -1;
    S = new char[size];
  }

  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void push(char c)
  {
    if(!full())
    {
      S[++top] = c;
    }
    else
    {
      cout<<"Stack Overflow!"<<endl;
    }
  }

  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char pop()
  {
    if(!empty())
    {
      return S[top--];
    }
    else
    {
      return -1;
    }
  }

  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void printStack()
  {
    for(int i=top;i>=0;i--)
    {
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool empty()
  {
    return top == -1;
  }

  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool full()
  {
    return top == size-1;
  }
};

class Convert
{
private:
   Stack *S;
   Queue *Q;
   
public:
  Convert()
  {
    S = new Stack(20);
    Q = new Queue(20);
  }

  void tempFunc()
  {
    char temp;
    int i;
    string infix = "(3+4)*9-(3+4)*8";

    for(int i=0;i<infix.length();i++)
    {
      S->push(infix[i]);
    }
    
    while(!S->empty())
    {
      temp = S->pop();
      cout << temp;
      //we could simply do cout<<s1.pop(); as well. 
    }
  }
};

int main()
{
  /**
   * this is for the stack class
   */
  srand(546365);
  string infix;
  char temp;
  
  cout<<"Expression [e.g. (3+4)*9-(3+4)*8 ]:";
  cin>>infix;
  cout << infix << endl;
  Stack s1(infix.length()+2);
  s1.push('(');
  
  for(int i=0;i<infix.length();i++)
  {
    s1.push(infix[i]);
  }
  
  s1.push(')');
  
  while(!s1.empty())
  {
    temp = s1.pop();
    cout<<temp;
  }
  cout<<endl;
  
  return 0;
}
