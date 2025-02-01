#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  list.push_front("dog");
  list.push_front("cat");

  cout<< list.front()<<endl;
  cout<< list.back()<<endl;

  list.push_front("bird");
  list.push_front("rat");

  cout<< list.front()<<endl;
  cout<< list.back()<<endl;

  cout<< list.size()<<endl;

  list.pop_front();
  cout<< list.front()<<endl;
  cout<< list.size()<<endl;

  list.pop_back();
  cout<< list.back()<<endl;
  cout<< list.size()<<endl;

  return 0;
}
