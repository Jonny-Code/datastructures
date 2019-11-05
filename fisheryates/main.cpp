#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const string file_path = "/home/jon/Desktop/orwell/trtwp.txt";

// shuffles vector with the fisher-yates algorithm
void fisher_yates_vec(vector<string> &v, int a)
{
  srand(time(NULL));
  for (int i = a - 1; i > 0; i--)
  {
    int idx = (rand() % (i + 1));
    swap(v.at(idx), v.at(i));
  }
}

// shuffles string array with the fisher-yates algorithm
void fisher_yates_arr(string *arr, int a)
{
  int i, j;
  string tmp;
  for (i = a - 1; i > 0; i--)
  {
    j = rand() % (i + 1);
    tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
  }
}

// read the file and return vector with file contents
vector<string> read_file()
{
  ifstream _if;
  _if.open(file_path);

  if (!_if)
    cout << "error opening file!\n";
  cout << "Orwell - The Road to Wigam Pier\n\n";
  string line;
  vector<string> lines;

  while (getline(_if, line))
  {
    lines.push_back(line);
  }

  return lines;
}

void output_vec(string i)
{
  cout << endl
       << " " << i << endl;
}

int main()
{

  vector<string> lines = read_file();

  fisher_yates_vec(lines, lines.size());

  for_each(lines.begin(), lines.end(), output_vec);

  return 0;
}