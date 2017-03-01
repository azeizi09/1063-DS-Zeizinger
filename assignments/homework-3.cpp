/**
* @Homework: Homework-3
* @Author: Alexander Zeizinger 
* @Description: 
*     This code from the array_based_circ_q.cpp is the Print fix for the function we were developing in class.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 01 03 2017
*/

/**
* @FunctionName: Print
* @Description: 
*     When Front and Rear possess the same value, the queue is either full or empty. If it's full, 
  the Print function will loop through the for loop and print the values of the queue (NumItems > 0). If it's empty, 
  the Print function will print nothing as there are no values in the queue (NumItems = 0).
* @Params:
*    None
* @Returns:
*    None
*/
void Print()
{
  if(Front == Rear)
  {
    for(int i = 0; i < NumItems; i++)
    {
      cout << Q[i] <<" ";
    }
  }
      
  else
  {
    int Index = Front;

    while(Index != Rear)
    {
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
    }

    cout<<endl;
  }
}
