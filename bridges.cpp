#include "bridges.h"

//here is my main function
void bridges(string input, string output)
{
  ifstream in(input);
  ofstream out(output);

  string command; //used to read in commands
  string recordItem; // used to read in the record item corresponding to a command
  string file; //used to read in the file

  in >> command;//prime

  while(!in.fail())//process
  {
    //reads in the file if the command
    //is file and has a series of outputs
    if(command == "File")
    {
      in >> file;
      out << "Command: " << command << " " << file << endl;
      out << "\tData file in use: " << file << endl;
    }

    //reads in the record item if the command
    //is River and has a series of outputs
    else if(command == "River")
    {
      in >> recordItem;
      out << "Command: " << command << " " << recordItem << endl;
      River(file, out, recordItem);
    }

    //reads in the record item if the command
    //is Age and has a series of outputs
    else if(command == "Age")
    {
      in >> recordItem;
      out << "Command: " << command << " " << recordItem << endl;
      Age(file, out, recordItem);
    }

    //reads in the record item if the command
    //is Purpose and has a series of outputs
    else if(command == "Purpose")
    {
      in >> recordItem;
      out << "Command: " << command << " " << recordItem << endl;
      Purpose(file, out, recordItem);
    }

    //reads in the record item if the command
    //is ID and has a series of outputs
    else if(command == "ID")
    {
      in >> recordItem;
      out << "Command: " << command << " " << recordItem << endl;
      ID(file, out, recordItem);
    }

    in >> command; //reprime

  }
}

//This is my read function. This will read in the corresponding
//data from whatever file is loaded.
void Read(istream &in, string &ID, string &River, string &Loc,
string &Year, string &Purpose, string &Length, string &ClearG,
string &TorD, string &Material, string &Span, string &Rel, string &Type)
{
  string lane;
  getline(in, ID, ',');
  getline(in, River, ',');
  getline(in, Loc, ',');
  getline(in, Year, ',');
  getline(in, Purpose, ',');
  getline(in, Length, ',');
  getline(in, lane, ',');
  getline(in, ClearG, ',');
  getline(in, TorD, ',');
  getline(in, Material, ',');
  getline(in, Span, ',');
  getline(in, Rel, ',');
  getline(in, Type, '\n');
}

//This is my display function. This will output the header and
//the information in the loaded file.
void Display(ostream &out, string &ID, string &River, string &Loc,
string &Year, string &Purpose, string &Length, string &ClearG,
string &TorD, string &Material, string &Span, string &Rel, string &Type, bool flag)
{
  //This if statement is used to output the header
  if(flag == false)
  {
    out << "\tID River Loc Year Purpose Length Clear-G T-or-D Material Span Rel Type" << endl;
  }

  //This section of code outputs the information from the loaded file
  out << '\t' << ID << " " << River << " " << Loc << " " << Year << " " << Purpose <<
  " " << Length << " " << ClearG << " " << TorD << " " << Material << " " <<
  " " << Span << " " << Rel << " " << Type << endl;
}

//This is my River function. This will output either an error
//or the loaded file's information if the bridge function has found
//the River command.
void River(string recordData, ostream &out, string river)
{
  ifstream in(recordData);

  string ID, River, Loc, Year, Purpose, Length, ClearG, TorD, Material,
  Span, Rel, Type;

  bool found = false; //flag for if the command is found
  bool flag = false; //flag for displaying the header

  Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
  Material, Span, Rel, Type); //Read function

  //displays file's information if the command is found
  while(!in.fail())
  {
    if(River == river)
    {
      found = true;
      Display(out, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
      Material, Span, Rel, Type, flag); //Display function
      flag = true;
    }
    Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
    Material, Span, Rel, Type); //Read function
  }

  //displays error message if command isn't found
  if(!found)
  {
    out << "No bridge found for " << river << endl;
  }
}

//This is my Age function. This will output either an error
//or the loaded file's information if the bridge function has found
//the Age command.
void Age(string recordData, ostream &out, string age)
{
  ifstream in(recordData);

  string ID, River, Loc, Year, Purpose, Length, ClearG, TorD, Material,
  Span, Rel, Type;

  bool found = false; //flag for if the command is found
  bool flag = false; //flag for displaying the header

  Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
  Material, Span, Rel, Type); //Read function

  //displays file's information if the command is found
  while(!in.fail())
  {
    if(Year == age)
    {
      found = true;
      Display(out, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
      Material, Span, Rel, Type, flag); //Display function
      flag = true;
    }
    Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
    Material, Span, Rel, Type); //Read function
  }

  //displays error message if command isn't found
  if(!found)
  {
    out << "No bridge found for " << age << endl;
  }
}

//This is my Purpose function. This will output either an error
//or the loaded file's information if the bridge function has found
//the Purpose command.
void Purpose(string recordData, ostream &out, string purpose)
{
  ifstream in(recordData);

  string ID, River, Loc, Year, Purpose, Length, ClearG, TorD, Material,
  Span, Rel, Type;

  bool found = false; //flag for if the command is found
  bool flag = false; //flag for displaying the header

  Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
  Material, Span, Rel, Type); //Read function

  //displays file's information if the command is found
  while(!in.fail())
  {
    if(Purpose == purpose)
    {
      found = true;
      Display(out, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
      Material, Span, Rel, Type, flag); //Display function
      flag = true;
    }
    Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
    Material, Span, Rel, Type); //Read function
  }

  //displays error message if command isn't found
  if(!found)
  {
    out << "No bridge found for " << purpose << endl;
  }
}

//This is my ID function. This will output either an error
//or the loaded file's information if the bridge function has found
//the ID command.
void ID(string recordData, ostream &out, string id)
{
  ifstream in(recordData);

  string ID, River, Loc, Year, Purpose, Length, ClearG, TorD, Material,
  Span, Rel, Type;

  bool found = false; //flag for if the command is found
  bool flag = false; //flag for displaying the header

  Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
  Material, Span, Rel, Type); //Read function

  //displays file's information if the command is found
  while(!in.fail())
  {
    if(ID == id)
    {
      found = true;
      Display(out, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
      Material, Span, Rel, Type, flag); //Display function
      flag = true;
    }
    Read(in, ID, River, Loc, Year, Purpose, Length, ClearG, TorD,
    Material, Span, Rel, Type); //Read function
  }

  //displays error message if command isn't found
  if(!found)
  {
    out << "No bridge found for " << id << endl;
  }
}

//end of program
