int main() {
    int x= 17, p = 43
    //1. How can we define a pointer that cannot modify what it points at?
    const int* p = &x;
    //2. how can we define a pointer that can only ever point at one item which it was set to point to initially
    int* const q = &x;
    q = &y; //how can we prevent that from compiling:

    // 3. What kind of pointer can point at a constant item?
    const int z = 100;
    // z= 200; // not allowed, of course:

    //int*r = &z; It is going to give an compilation error since you can't keep an address of a constant in an integer
    const int* r = &z;
    //*r = 300; //how can we prevent that from compiling?

} // main

