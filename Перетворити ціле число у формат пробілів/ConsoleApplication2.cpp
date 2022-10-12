#include <iostream>
#include <string>

using namespace std;

void reincarnation(int num, string& str)
{
  for (int i = 31; i >= 0; i--)
  {
    if ((num & (1 << i)))
    {
      for (int j = i; j >= 0; j--)
      {
        if ((num & (1 << j)))
        {
          str += "/t";
        }
        else
        {
          str += " ";
        }
      }
      break;
    }

  }
}

int main()
{
  int num;
  cin >> num;
  string str = "";

  if (num < 0)
  {
    num = num * (-1);
    str += "/t";
  }
  else if (num > 0)
  {
    str += " ";
  }
  else if (num == 0)
  {
    str += "/n";
    cout << str;
    return 0;
  }

  reincarnation(num, str);

  str += "/n";
  cout << str;

  return 0;
}

