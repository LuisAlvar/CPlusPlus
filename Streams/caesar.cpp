#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/// @brief Prints usage instructions
/// @param program_name the name of this program
void usage(string program_name)
{
  cout << "Usage: " << program_name << " [-d] [-kn] infile outfile\n";
  exit(1);
}

/// @brief Prints fiel opening error message.
/// @param filename the name of the file that could not be opened
void open_file_error(string filename)
{
  cout << "Error opening file " << filename << "\n";
  exit(1);
}

/// @brief Computes correct remainder for negative dividend
/// @param a an integer
/// @param n an integer > 0
/// @return the mathematically correct remainder r such that a - r is divisible by n and 0 <= r and r < n
int remainder(int a, int n)
{
  if (a >= 0)
  { 
    return a % n;
  }
  else
  {
    return n - 1 - (-a - 1) % n;
  }
}

/// @brief Encrypts a character using the Caesar cipher
/// @param ch the character to encrypt
/// @param k the encryption key
/// @return the encrypted character
char encrypt(char ch, int k)
{
  const int NLETTER = 'Z' - 'A' + 1;

  if ('A' <= ch && ch <= 'Z')
  {
    return static_cast<char>('A' + remainder(ch - 'A' + k, NLETTER));
  }
  
  if ('a' <= ch && ch <= 'z')
  {
    return static_cast<char>('a' + remainder(ch - 'a' + k, NLETTER));
  }

  return ch;
}

/// @brief Encrypts a stream using the Caesar cipher
/// @param in the stream to read from
/// @param out the stream to write to 
/// @param k the encryption key
void encrypt_file(istream& in, ostream& out, int k)
{
  char ch;
  while (in.get(ch))
  {
    out.put(encrypt(ch, k));
  }
}

/// @brief Converts a string to an integer
/// @param s a string representing an integer
/// @return the equivalen integer
int string_to_int(string s)
{
  istringstream instr(s);
  int n;
  instr >> n;
  return n;
}

int main(int argc, char* argv[]) {
  bool decrypt = false;
  int key = 3; 
  int nfile = 0;

  ifstream infile;
  ofstream outfile;

  if (argc< 3 || argc > 5) usage(string(argv[0]));
  
  int i;
  for (i = 0; i < argc; i++) {
    string arg = string(argv[i]);

    if (arg.length() >= 2 && arg[0] == '-') {
      char option = arg[1];
      if (option == 'd') {
        decrypt = true;
      }
      else if (option == 'k') {
        key = string_to_int(arg.substr(2));
      }
    }
    else {
      nfile++;
      if (nfile == 1)
      {
        infile.open(arg.c_str());
        if (infile.fail()) open_file_error(arg);
      }
      else if (nfile == 2)
      {
        outfile.open(arg.c_str());
        if (outfile.fail()) open_file_error(arg);
      }
    }
  }

  if (nfile != 2) usage(string(argv[0]));
  if (decrypt) key = -key;

  encrypt_file(infile, outfile, key);

  infile.close();
  outfile.close();

  return 0;
  
}