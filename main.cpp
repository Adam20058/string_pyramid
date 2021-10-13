#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Welcome page to pyramid app
  cout << endl;
  cout << "==============================================" << endl;
  cout << "Welcome to String to Letter Pyramid Converter" << endl;
  cout << "==============================================" << endl;

  char selection {};
  
  do
  {

    cout << "\nDo you wish to use the Letter Pyramid Converter (y/n): ";
    cin >> selection;
    
    if (selection == 'y' || selection == 'Y') {
      // ignores first call to input used above
      cin.ignore();
      // Get the input from the user and store it in a std::string variable
      string USER_STRING{};
      cout << "Enter a string: ";
      getline(cin, USER_STRING);
      cout << endl;

      //Loop for each letter in the string entered by the user
      size_t NUM_LETTER = USER_STRING.length();
      int POSITION{0};

      for (char c : USER_STRING)
      {
        // Determine how many blank spaces must be displayed before the current row and display them
        size_t NUM_SPACES = NUM_LETTER - POSITION;
        while (NUM_SPACES > 0)
        {
          cout << " ";
          --NUM_SPACES;
        }
        // Determine how many letters must be displayed before the current character and display them
        for (size_t j = 0; j < POSITION; j++)
        {
          cout << USER_STRING.at(j);
        }

        // Display the current 'center' character
        cout << c;

        // Display the remaining characters in reverse order
        for (int j = POSITION - 1; j >= 0; --j)
        {
          // You can use this line to get rid of the size_t vs int warning if you want
          auto k = static_cast<size_t>(j);
          cout << USER_STRING.at(k);
        }
        cout << endl;
        ++POSITION;
    }
    } else if (selection == 'n' || selection == 'N') {
      cout << "Goodbye" << endl;
    } else {
    cout << "Illegal response -- Please try again" << endl;
    }
  } while (selection != 'n' && selection !='N');
  cout << endl;
  return 0;
}