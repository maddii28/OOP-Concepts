// Task 1
// Who are you? What is this program called?
/*
Name: Maddhav Suneja
Program: Pointer tutorial 
*/

// I have stopped using cerr in your started code because CLion makes
// a mess with it.

#include <iostream>   // needed for task 2
#include <vector>     // needed for task 27
using namespace std;  // needed for task 2

// Task 16 Complex definition


// Task 17 PlainOldClass definition


// Task 18 PlainOldClass2 definition


// Task 28 Colour definition
class Colour {  
public:       
    Colour(const string& name, unsigned r, unsigned g, unsigned b)       
        : name(name), r(r), g(g), b(b) {}       
    void display() const { 
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
    }   
private:       
    string name;      // what we call this colour       
    unsigned r, g, b; // red/green/blue values for displaying  
};

// Task 29 SpeakerSystem definition
class SpeakerSystem {
   public:
       void vibrateSpeakerCones(unsigned signal) const {
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

// Task 29 Amplifier definition
class Amplifier {
   public:
     void attachSpeakers( SpeakerSystem& spkrs)  //const SpeakerSystem was the problem
     {
        if(attachedSpeakers) {
            cout << "already have speakers attached!\n";
        } else {
            attachedSpeakers = &spkrs;
        }
   }
   
   void detachSpeakers() { // should there be an "error" message if not attached?
      attachedSpeakers = nullptr; 
   } 
  
   void playMusic( ) const {
      if (attachedSpeakers) {
         attachedSpeakers -> vibrateSpeakerCones(440); 
      } else {
         cout << "No speakers attached\n";
      } 
   }
     private:
       SpeakerSystem* attachedSpeakers = nullptr;
};
// Task 30 Person Definition
class Person {  
public:       
    Person(const string& name) : name(name) {}
    void movesInWith(Person& newRoomate) {
        if (this == &newRoomate){
            cout << "cannot room with";
        }
        else if (newRoomate.roomie!=nullptr){
            cout << "Choice already has a rooomate";
        }
        else if (roomie!= nullptr){
            cout << "Choice already ahs a roomate";
        }
        else {
        roomie = &newRoomate;        // now I have a new roomie            
        newRoomate.roomie = this;    // and now they do too   
        }
      
    }       
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }  
private:
    Person* roomie;       
    string name;  
};           




int main() {
    cout << "Task 1\n";

    // Task 2
    cout << "Task 2\n";
    int x;  
    x = 10;   
    cout << "x = " << x << endl;


    // Task 3 
    cout << "Task 3\n";
    // Using the debugger, set a breakpoint in main and run to
    // it. Observe the value of x. // x = 1 is the garbage value 
    // [No new code] 

    // Task 4
    cout << "Task 4\n";
    // Using the debugger, step forward observing the value of x
    // [No new code] // x = 10 is the asssigned value 

    // Task 5
    cout << "Task 5\n";
    // Watch window. Xcode equivalent? Gdb equivalent?
    // Activity: see x's value
    // [No new code]

    // Task 6
    cout << "Task 6\n";
    // Watch window to see the address of x
    // [No new code]

    // Task 7
    cout << "Task 7\n";
    // Watch window to see the value stored at the address of x
    // [No new code]
    
    // Task 8
    cout << "Task 8\n";
    int* p;  
    p = &x;  
    cout << "p = " << p << endl; // derefrencing a pointer  -- p points to x as it has x's address)

    
    // Task 9
    cout << "Task 9\n";
    // Using the value you observe in &x, write a line of code to
    // directly assign that value to p. E.g. p = 0x0012fed4;
    // What happens? Should have a compiler error.
    /* p = 0x000000016fdff2ec; 
    incompatible integer since you can't assign an integer to point conversion
    */

    
    // Task 10
    cout << "Task 10\n";
    // Run earlier print statement for "p = ". Observe the watch
    // window.
    cout << "p points to where " << *p << " is stored\n"; 
    cout << "*p contains " << *p << endl; // get the value of stored where the pointer points

    
    // Task 11
    cout << "Task 11\n";
    *p = -2763;  
    cout << "p points to where " << *p << " is stored\n"; 
    cout << "*p now contains " << *p << endl;  // changed to -2763 since it refers to same memory
    cout << "x now contains " << x << endl;

    
    // Task 12
    cout << "Task 12\n";
    int y(13);      
    cout << "y contains " << y << endl;      
    p = &y;      
    cout << "p now points to where " << *p << " is stored\n";      
    cout << "*p now contains " << *p << endl;      
    *p = 980;      
    cout << "p points to where " << *p << " is stored\n";      
    cout << "*p now contains " << *p << endl;      
    cout << "y now contains " << y << endl;

    
    // Task 13
    cout << "Task 13\n";
    int* q;      
    q = p;      
    cout << "q points to where " << *q << " is stored\n";      
    cout << "*q contains " << *q << endl;

    
    // Task 14
    cout << "Task 14\n";
    double d(33.44);      
    double* pD(&d);      
    *pD = *p;      
    *pD = 73.2343;      
    *p  = *pD;      
    *q  = *p;      
    //pD  = p; -- a int* can't be cast on double*
    //p   = pD; -- a double* can't be cast on int*


    
    // Task 15
    cout << "Task 15!!!\n"; // Yes, this is a VERY IMPORTANT task!
    // Const and pointers.
    int joe = 24;  
    const int sal = 19;    
    int*  pI;  
    pI = &joe;  
    *pI = 234;  
    //pI = &sal;  assigning to 'int *' from 'const int *' discards qualifiers
    *pI = 7623;    

    const int* pcI;
    pcI = &joe;  
    //*pcI = 234;   since it's constant, you can't re-initialize it 
    pcI = &sal;  
    //*pcI = 7623;    since it's constant, you can't re-initialize it 

    //int* const cpI; must be initialized bfr declared 
    int* const cpI(&joe);
    //int* const cpI(&sal); type mismatch btw const integ and integ
    //cpI = &joe;  cannot assign to variable 'cpI' with const-qualified type 'int *const' since joe is int
    *cpI = 234;  
    //cpI = &sal;  constant pointer so you can't modify
    *cpI = 7623;    

    //const int* const cpcI;  not intialized it at the declaration
    const int* const cpcI(&joe); 
    //const int* const cpcI(&sal); cannot not modify
    //cpcI = &joe;  can't assign it's const
    // *cpcI = 234;  can't assign since its const
    //  cpcI = &sal;  can't assign since its const
    // *cpcI = 7623; can't assign since its const

    
    // Task 16
    cout << "Task 16\n";
    // Pointers to user-defined types.  Add the type for struct Complex above.
    struct Complex {
     double real;
     double img;
     };

    Complex c = {11.23,45.67};      
    Complex* pC(&c);
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;  precedence issue
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl; // this is the clumsy way
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl; //arrow operator was invented for pointers to struc n class

    
    // Task 17
    cout << "Task 17\n";
    class PlainOldClass {
      public:
         PlainOldClass() : x(-72) {}
         int getX() const { return x; }
         void setX( int val )  { x = val; }
      private:
         int x;
};

    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    // What is this code doing?
    /* ppoc->getX() uses the pointer ppoc to access the getX() method of poc, which returns the value of x.
    ppoc->setX(2837) sets poc.x to 2837 using the pointer ppoc. */
    

    // Task 18
    cout << "Task 18\n";
    // Test the changes to PlainOldClass
    class PlainOldClassV2 {  
    public:
       PlainOldClassV2() : x(-72) {}
       int getX() const { return x; }
       void setX( int x )  { this ->x = x; } // It helps distinguish btw parameter and the member variable
    private:
       int x;
};
    
    // Task 19
    cout << "Task 19\n";
    // creating and modifying an item on the heap. Use the debugger to
    // observe.
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
    *pDyn = 17;

    cout << "The " << *pDyn
     << " is stored at address " << pDyn
     << " which is in the heap\n";
    // Task 20
    cout << "Task 20\n";
    // What happens to pDyn in the following? With most compilers it
    // is unchanged.  Visual Studio actually changes it. (I should
    // check if that is just in debug mode.)
    cout << pDyn << endl;  
    delete pDyn;  
    cout << pDyn << endl;

    // Task 21
    cout << "Task 21\n";
    pDyn = nullptr; // practicing after a heap is deleted
    double* pDouble = nullptr; //easy to spot errors
    

    // Task 22
    cout << "Task 22\n";
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;    It crashes since can't dereference a null ptr  
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    
    // Task 23
    cout << "Task 23\n";
    // Question. Can <code>this</code> be nullptr?
    //It can never be since it points to the object that method is invoked on

    // Task 24
    cout << "Task 24\n";
    double* pTest = new double(12);      
    delete pTest;      
    pTest = nullptr;      
    delete pTest; // safe so you can delete a null ptr



    // Task 25
    cout << "Task 25\n";
    short* pShrt = new short(5);      
    delete pShrt;      
    //delete pShrt; can't delete a pointer again
    

    // Task 26
    cout << "Task 26\n";
    long jumper = 12238743;     
    //delete jumper;  cannot delete something that is not heap
    long* ptrTolong = &jumper; 
    //delete ptrTolong;       can't do this 
    Complex cmplx; 
    ptrTolong = nullptr;     
    //delete cmplx;       cannot delete something that is not heap
    

    // Task 27
    cout << "Task 27\n";
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
}      
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        cout << complV[ ndx ]->real << endl;         
        cout << complV[ ndx ]->img  << endl;      
}      
    // release the heap space pointed at by the pointers in the vector      
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        delete complV[ndx];
}      
    // clear the vector      
    complV.clear();


    // Task 28 Use the Colour class
    cout << "Task 28\n";
    // Add Colour class above main
    vector<Colour*> colours;         
    string inputName;       
    unsigned inputR, inputG, inputB;
    // fill vector with Colours from the file       
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));      
        }         
    // display all the Colours in the vector:       
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {            
        colours[ndx]->display();            
        cout << endl;      
        }
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) { 
        delete colours[ndx];
    }
colours.clear();


    

    // Task 29 Use SpeakerSystem and Amplifier classes
    cout << "Task 29\n";
    // Add SpeakerSystem and Amplifier classes above main


    // Task 30 Use the Person class
    cout << "Task 30\n";
    // Add Person class above main
    // write code to model two people in this world       
    Person joeBob("Joe Bob");
    Person billyJane("Billy Jane");         

    // now model these two becoming roommates       
    joeBob.movesInWith(billyJane);         

    // did this work out?       
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

    
}
