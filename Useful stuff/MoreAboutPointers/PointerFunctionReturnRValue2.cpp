#include <iostream>
int * ptrReturn(int a)
{
	return &a;
}
int main()
{
	int a = 5;
	int b = 4;
	int * pb = &b;

	//ptrReturn(a) = pb; //error "Expression must be a modifiable lvalue"

	//pointer is an object, and the result of a function call is always an rvalue if the return type is an object type.


	//Dereferencing the pointer will give an lvalue denoting the object it points to.
	*ptrReturn(a) = b;//correct


					  //Using a tmp object to contain the rvalue will allow us to use it as lvalue
	int * tmp = ptrReturn(a);
	*tmp = *pb;//also correct

			   //or simply

	*tmp = b;

	std::cout << a;//now couts 5

	//the problem is this code is that the function ptrReturn takes an object of type int, not an reference
	//therefore it creates a new using something called copy-constructor and then returns the address of the new object
	//therefore we change the new object, and not a!
	//this is a great example how 1 symbol can make you search for an error for 20minutes....
	return 0;
}


