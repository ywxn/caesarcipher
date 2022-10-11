#include <iostream>
#include <string>
using namespace std;

const int maxchar = 'z';
const int minchar = ' ';
const int charrange = 1 + maxchar - minchar;
//A mod function that is "safe" to use even when val might be negative
char safemod(int val, int mod) {
  int modval = val % mod;
  if (modval < 0) {
    modval += mod;
  }
  return char(modval);
}
//encode: a function that takes in a key and an unencrupted message, and returns the encrypted message
string encode(string message, string key){
  string cipher = "";
  for (int i = 0; i < message.length(); i++){
    char intchar = message[i] - minchar;
    char shiftedchar = safemod((intchar + key[safemod(i,key.length())]) - minchar, charrange);
    cipher += shiftedchar + minchar;
  }
  return cipher;
}
//decode: a function that takes in a key and an unencrypted message, and returns the encrypted message
string decode (string message, string key){
  string ogMessage = "";
  for (int i = 0; i < message.length(); i++){ 
    char intchar = message[i] - minchar;
    char shiftedchar = safemod((intchar - key[safemod(i,key.length())]) + minchar, charrange);
    ogMessage += shiftedchar + minchar;
  }
  return ogMessage;
}
//main: function for managing the user interface
int main() {
  string message;
  string key;
  char uiChoice;
  cout << "Enter your message:  ";
  getline(cin, message);
  cout << "Enter your key:  ";
  getline(cin, key);
 
  while (uiChoice != 'e' && uiChoice != 'd'){
  cout << "Would you like to (e)ncode or (d)ecode?: ";
  cin >> uiChoice;
  if (uiChoice != 'e' && uiChoice != 'd'){
    cout << "Invalid choice, please try again." << endl;
  }
  }

  if (uiChoice == 'e'){
    cout << "Translated message:  " << encode(message, key) << endl;
  } else if (uiChoice == 'd'){
    cout << "Translated message:  " << decode(message, key) << endl;
  }
  return 0;
}
