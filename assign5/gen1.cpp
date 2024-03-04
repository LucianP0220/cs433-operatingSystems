#include<iostream>
#include<string>
#include<queue>
using namespace std;
--------------------------------------------

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
  bool Bstring;//initialize variable to return T or F

  //iterate through string
  for (int i = 0; i < s.length(); i++)
    {
      if(s[i]=='0' || s[i] =='1')//if s is a 0 or 1 return true
        {
          Bstring = true;
        }
      else//else return false
        {
          Bstring = false;
        }
    }
  return Bstring;
}// end of recognizer


// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed.
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C
//   after about 20 strings have been displayed.
int main()
{
  string E[] = {"0","1","2"};
  string UserTerm;
  string s1,s2;
  int count = 0;
  queue<string> Myqueue;


  while(true)
    {
      // generate a string
      // if the recognizer says true, display it
      s1=Myqueue.front();
      Myqueue.pop();
      if(recognizer(s1))
        {
        cout<< s1 <<endl;
        count++;
        }
      //      if(!Myqueue.isFull())
      //{
      for(int i = 0; i < 3; i++)
        {
          s2 = s1+E[i];
          Myqueue.push(s2);
        }
          //}
        if(count >= 20)
          {
            cout<< "Would you like to display 20 more? (enter y or n)" <<endl;
            cin>> UserTerm;
            if(UserTerm == "n")
              break;
            else
              continue;
          }
    }// end of while

}// end of main

