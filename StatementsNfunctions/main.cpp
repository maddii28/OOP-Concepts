#include <iostream> 

int Main(int argc, char **argv) { //1st function
    int firstNumber = 12;
    int secondNumber = 9;
    int sum = firstNumber + secondNumber;

    std::cout << "The sum of two numbers is : " << sum << std::endl;

    return 0;
}

int addNumbers(int first_param, int second_param){  //2nd Function Taking parameters and calculating sum 

    int result = first_param + second_param;

    return result;
}

int main(){  //3rd function 
    int first_number {13};
    int second_number {7};

    std::cout << "First number :" << first_number << std::endl;
    std::cout << "Second number :" << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl;

    sum = addNumbers(25,7);
    std::cout << "Sum : " << sum << std::endl;

    sum = addNumbers(30,54);
    std::cout << "Sum : " << sum << std::endl;

    std::cout << "Sum : " << addNumbers(3,4) << std::endl; // another way of printing using function call 


    return 0;  

}
