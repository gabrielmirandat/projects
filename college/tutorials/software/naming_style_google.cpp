#General Naming Rules
Names should be descriptive; eschew abbreviation (evitar abreviacoes).
'ok'
int price_count_reader;    // No abbreviation.
int num_errors;            // "num" is a widespread convention.
int num_dns_connections;   // Most people know what "DNS" stands for.
'not ok'
int n;                     // Meaningless.
int nerr;                  // Ambiguous abbreviation.
int n_comp_conns;          // Ambiguous abbreviation.
int wgc_connections;       // Only your group knows what this stands for.
int pc_reader;             // Lots of things can be abbreviated "pc".
int cstmr_id;              // Deletes internal letters.

#File Names
Filenames should be all lowercase and can include underscores (_) or dashes (-).
C++ files should end in .cc and header files should end in .h.
'ok'
    my_useful_class.cc
    my-useful-class.cc
    myusefulclass.cc
    myusefulclass_test.cc // _unittest and _regtest are deprecated.

#Type Names
Type names start with a capital letter and have a capital letter for each new word,
with no underscores: MyExcitingClass, MyExcitingEnum.
The names of all types — classes, structs, type aliases, enums, and type template 
parameters — have the same naming convention.
'ok'
// classes and structs
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// typedefs
typedef hash_map<UrlTableProperties *, string> PropertiesMap;

// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, string>;

// enums
enum UrlTableErrors { ...
  
#Variable Names
The names of variables and data members are all lowercase, with underscores between words.
Data members of classes (but not structs) additionally have trailing underscores (à direita da variável). 
For instance: a_local_variable, a_struct_data_member, a_class_data_member_.
'ok'
string table_name;  // OK - uses underscore.
string tablename;   // OK - all lowercase.

class TableInfo {
  ...
 private:
  string table_name_;  // OK - underscore at end.
  string tablename_;   // OK.
  static Pool<TableInfo>* pool_;  // OK.
};

'not ok'
string tableName;   // Bad - mixed case.

#Constant Names
Variables declared constexpr or const, and whose value is fixed for the duration of the program, 
are named with a leading "k" followed by mixed case. 
'ok'
const int kDaysInAWeek = 7;

#Function Names
Regular functions have mixed case; "cheap" functions may use lower case with underscores.
Ordinarily, functions should start with a capital letter and have a capital letter for each new word.
Such names should not have underscores. Prefer to capitalize acronyms as single words (i.e. StartRpc(), not StartRPC()).
The same naming rule applies to class- and namespace-scope.
Functions that are very cheap to call may instead follow the style for variable names (all lower-case, with 
underscores between words).
A canonical example is an inline method that just returns one of the class member variables.
'ok'
AddTableEntry()
DeleteUrl()
OpenFileOrDie()

class MyClass {
 public:
  ...
  bool is_empty() const { return num_entries_ == 0; }

 private:
  int num_entries_;
};

#Namespace Names
Namespace names are all lower-case. Top-level namespace names are based on the project name.

#Enumerator Names
Enumerators should be named either like constants or like macros: either kEnumName or ENUM_NAME.
'ok'
enum UrlTableErrors {
  kOK = 0,
  kErrorOutOfMemory,
  kErrorMalformedInput,
};
enum AlternateUrlTableErrors {
  OK = 0,
  OUT_OF_MEMORY = 1,
  MALFORMED_INPUT = 2,
};

#Macro Names
You're not really going to define a macro, are you?

