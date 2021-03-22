#include "holberton.h"

/**
 * Write_Number - Function that converts an int type to a char type.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @Solve_Number: Number that will be entered into the buffer.
 * @Number_Power_Of_10: Number that increases in increments of 10 and decreases
 *                     in the same way to be able to convert the number digit
 *                     by digit into a numeric character
 * Return: Returns the division of Solve_Number by Number_Power_Of_10.
 */


int Write_Number(Write *write, Buffer *buffer, int Solve_Number,
		  int Number_Power_Of_10)
{
	if (Solve_Number / Number_Power_Of_10 < 10)
	{
		WRITE_TO_LEETER((Solve_Number / Number_Power_Of_10) + '0');

		if (Number_Power_Of_10 > 9)
			Number_Power_Of_10 /= 10;
		return (Solve_Number / Number_Power_Of_10);
	}
	else
	{
		int Number;

		Number = Write_Number(write, buffer, Solve_Number,
				      Number_Power_Of_10 * 10);

		WRITE_TO_LEETER((Number % 10) + '0');


		if (Number_Power_Of_10 > 9)
			Number_Power_Of_10 /= 10;

		return (Solve_Number / Number_Power_Of_10);
	}

}

/**
 * Print_Number - Function that calls the recursive function Write Number
 *               to be able to convert a number in type int to type char.
 * @buffer: Data structure that handles the 1024 buffer.
 * @write: data structure that contains two function pointers, one to write
 *         to the buffer and the other to print the buffer.
 * @List_Argument: List of arguments passed to the _printf function.
 */

void Print_Number(Write *write, Buffer *buffer, va_list List_Argument)
{
	int Solve_Number = va_arg(List_Argument, int);

	if (Solve_Number < 0)
	{
		WRITE_TO_LEETER('-');
		Solve_Number *= (-1);
	}
	Write_Number(write, buffer, Solve_Number, 1);
}
