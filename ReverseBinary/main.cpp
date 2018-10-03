#include<iostream>
#include<iostream>
#include<bitset>
// Function Declaration
unsigned long Reverse(unsigned long input);

int main() {

unsigned long input;

std::cin >> input;
std::cout << Reverse(input);

return 0;
}

//Function Syntax
unsigned long Reverse(unsigned long input)
{
	unsigned long output = 0;
	while (input)
	{
		//Bitwise Left Shift to make space + Assignment.
		std::cout << "\nOutput before shift :"  << std::bitset<4>(output);
		output <<= 1;
		std::cout << "\nOutput after Left Shift: " << std::bitset<4>(output);
		std::cout << "\nPress Enter to Continue";
		std::cin.ignore();
		/* <input AND 1>  get the last bit of input.
		<output OR 0> store the bits in inverted order in output.	*/
		output |= input & 1;
		std::cout << "\nOutput after OR : " << std::bitset<4>(output);
		std::cout << "\nPress Enter to Continue";
		std::cin.ignore();
		/* Bitwise Right Shift to get a new low bit. */
		input >>= 1;
		std::cout << "\nInput after Right Shift : " << std::bitset<4>(input);
		std::cout << "\nPress Enter to Continue";
		std::cin.ignore();
	}
	return output;
}
