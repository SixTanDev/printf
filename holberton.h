#ifndef __Holberton__
#define __Holberton__

/*
 * Library.
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define SIZE_BUFER 1024

/*
 * Macro 1:
 */

#define WRITE_TO_LEETER_FORMAT(format)					      \
	{								      \
		if (buffer->Pointer_Init == buffer->Pointer_End ||	      \
		    ((size_t)(buffer->Pointer_Init - buffer->Buffer) == 500)) \
			Print(buffer);					      \
									      \
		*(buffer->Pointer_Init) = *((*format)++);		      \
		*(++buffer->Pointer_Init) = '\0';			      \
		(buffer->Length_Total)++;				      \
									      \
		if (buffer->Pointer_Init == buffer->Pointer_End ||	      \
		    ((size_t)(buffer->Pointer_Init - buffer->Buffer) == 500)) \
			Print(buffer);					      \
	}								      \

/*
 * Macro 2:
 */

#define WRITE_TO_LEETER(Character)					      \
	{								      \
		if (buffer->Pointer_Init == buffer->Pointer_End ||	      \
		    ((size_t)(buffer->Pointer_Init - buffer->Buffer) == 500)) \
			Print(buffer);					      \
									      \
		*(buffer->Pointer_Init) = Character;			      \
		*(++buffer->Pointer_Init) = '\0';			      \
		(buffer->Length_Total)++;				      \
									      \
		if (buffer->Pointer_Init == buffer->Pointer_End ||	      \
		    ((size_t)(buffer->Pointer_Init - buffer->Buffer) == 500)) \
			Print(buffer);					      \
	}								      \


/**
 * struct Buffer_ - We create the necessary structure to handle
 *                  the buffer
 * @Buffer: Array containing the total length of the buffer.
 * @Pointer_Init: Pointer that points to the next free buffer position.
 * @Pointer_End: Points to the final position + 1 of the buffer.
 * @Length_Total: Saves the total characters printed by the buffer.
 * Description: With this buffer we can solve point five of the
 *              holberton project that says that we have to create a
 *              1024 buffer and call write the least amount of times.
 */

typedef struct Buffer_
{

	char Buffer[SIZE_BUFER];
	char *Pointer_Init;
	char *Pointer_End;
	int Length_Total;

} Buffer;

/**
 * struct Write_ - We create the necessary structure to handle
 *                 writing, over-writting and printing of the buffer.
 * @Write: Pointer to the function to write to the buffer.
 * @Print: Pointer to the function to print to the buffer
 * Description: This structure controls the printing and writing of the buffer.
 */

typedef struct Write_
{

	void (*Write)(Buffer *, char **, int);
	void (*Print)(Buffer *);

} Write;

/**
 * struct to_funct - This script will serve to identify the corresponding
 *                   function of% Type in format
 * @Type: It will save the type of character that handles the _printf.
 * @Pointer_Function: Function pointer that corresponds to the function
 *                    that is assigned to Type
 * Description: This structure handles the% Type to form, that is, it answers
 *              the question, what function does% c,% d,% i etc. correspond to?
 */

typedef struct to_funct
{

	char *Type;
	void (*Pointer_Function)(Write *, Buffer *, va_list);

} To_Funct;

/*
 * Structure Number 4:
 *
 *
 *typedef struct Flags_{
 *
 *	char *Number$;
 *	char *Number;
 *	char *Signal;
 *
 *}Flags;
 */



/*
 * Declaration of the function:
 */

void Buffer_Init
(Buffer *);

void WRITE
(Buffer *, char **, int);

void Print
(Buffer *);

void Write_Init(Write *,
		void (*Function_Pointer_Write)(Buffer *, char **, int),
		void (*Function_Pointer_Print)(Buffer *));

int _Printf
(Write *, Buffer *, char **, va_list);

void Type
(Write *, Buffer *, char **, va_list);

int _printf
(const char *, ...);


/*
 *  Funciones del formato de printf
 */

void Print_String
(Write *, Buffer *, va_list);

void Print_Character_Porcentaje
(Write *, Buffer *, va_list);

void Print_Character
(Write *, Buffer *, va_list);

void Print_Number
(Write *write, Buffer *buffer, va_list List_Argument);

#endif
