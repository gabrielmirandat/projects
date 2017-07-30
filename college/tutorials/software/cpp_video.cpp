#C++#
g++ -std=c++11 prog.cpp
const double PI = 3.14;

#string
'read string from user' getLine(cin, string);
cout << string + char*;
string.size();
string.empty();
string.append(string2);
string.compare(string2);
int lastNameIndex = yourName.find("Miranda", 0/*start_index*/);

#vector
vector <int> letteryNumVect(10);	int lotteryNumArray[5] = {4,13,14,24,34};
lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
lotteryNumVect.at(2);
lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
lotteryNumVect.push_back(64);/*insert_final*/
lotteryNumVect.pop_back();/*remove_final*/
lotteryNumVect.begin();/*iterator_fist_position*/
lotteryNumVect.end();/*iterator_last_position*/
lotteryNumVect.front();/*firts_value*/
lotteryNumVect.back();/*last_value*/
lotteryNumVect.empty();/*is_empty*/
lotteryNumVect.size();/*n_elems*/

#file
#include <fstream>
ofstream writer("criado.txt");/*trunc output file stream*/
if(! writer) cout << error;
writer << string << endl;/*writing_in_file*/
writer.close();
ofstream writer("file.txt", ios::app/*append_final*/); //ios::binary, ios::in, ios::out, ios::trunc (default)
ifstream reader("lido.txt");
for(int i=0,!reader.eof(), i++)
reader.get(letter);/*get_char*/

#exceptions
int number=0;
try{if(number!=0)..}
    else throw(number);
catch(int number){..}

#class (attributes: height weight; capabilities: Run Eat)
static int numOfAnimals;/*class_variable*/
int getHeight(){ return height;}/*get_well_encapsulated*/
void setAll(int, int, string);/*prototype_for_after_defined*/
Animal(int, int, string);/*constructor_called whenever object is created*/
~Animal();/*prototype_for_destructor*/
Animal();/*constructor that receive anything*/
static int getNumOfAnimals() {return numOfAnimals;}/*randle_only_static_members*/
int Animal::numOfAnimals = 0;/*setting_static_variable*/
Animal::~Animal(){cout<<"Animal "<< this->name << "destroyed" << endl;}

class Dog : public Animal{}/*Dog has all public's variables and methods from Animal*/
Dog() : Animal(){}/*default constructor just calls superclass constructor*/
void toString();/*to override a superclass method just declare again in the subclass*/
Dog::Dog(int heigh, int weight, string name, string bark) : Animal(height, weight, name){this->sound = bark;}/*subclass constructor just handles
unique variables in constructor and let superclass handles the other that already has. Furthermore, static variable numOfAnimals is incremented*/
spot.Animal::toString();/*it is possible to call superclass version of method even if it is re-defined in subclass*/

#virtual methods and polymorphism
virtual void getClass() {cout << "I'm an Animal" << endl;}
void getClass() {cout << "I'm a Dog" << endl;}
void whatClassAreYou(Animal* animal){animal-> getClass();}/*remembering that a subclass is from it's superclass type too,
if we would do this we need put virtual to call Dog's function version if a Dog is passed as parameter*/
Animal* ptrDog = &spot;
Animal* ptrGShepard = &max;


