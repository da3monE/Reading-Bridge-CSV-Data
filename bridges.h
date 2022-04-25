#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::string;
using std::endl;
using std::cout;
using std::cin;

void bridges(string input, string output);

void Read(istream &in, string &ID, string &River, string &Loc,
string &Year, string &Purpose, string &Length, string &ClearG,
string &TorD, string &Material, string &Span, string &Rel, string &Type);

void Display(ostream &out, string &ID, string &River, string &Loc,
string &Year, string &Purpose, string &Length, string &ClearG,
string &TorD, string &Material, string &Span, string &Rel, string &Type, bool flag);

void River(string recordData, ostream &out, string river);
void Age(string recordData, ostream &out, string age);
void Purpose(string recordData, ostream &out, string purpose);
void ID(string recordData, ostream &out, string id);
