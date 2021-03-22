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

#define WRITE_TO_LEETER_FORMAT(format)				\
	{							\
	if (buffer->Pointer_Init >= buffer->Pointer_End)	\
		Print(buffer);					\
								\
	*(buffer->Pointer_Init) = *((*format)++);		\
	*(++buffer->Pointer_Init) = '\0';			\
	(buffer->Length)++;					\
	(buffer->Length_Total)++;				\
								\
	if (buffer->Pointer_Init >= buffer->Pointer_End)	\
		Print(buffer);					\
	}							\


/*
 * Macro 2:
 */

#define WRITE_TO_LEETER(Character)		\
	{							\
	if (buffer->Pointer_Init >= buffer->Pointer_End)	\
		Print(buffer);					\
								\
	*(buffer->Pointer_Init) = Character;			\
	*(++buffer->Pointer_Init) = '\0';			\
	(buffer->Length)++;					\
	(buffer->Length_Total)++;				\
								\
	if (buffer->Pointer_Init >= buffer->Pointer_End)	\
		Print(buffer);					\
	}							\


/*
 * Structure 1:
 */

typedef struct Buffer_{

	char Buffer[SIZE_BUFER];
	char *Pointer_Init;
	char *Pointer_End;
	int Length;
	int Length_Total;

}Buffer;

/*
 * Structure Number 2:
 */

typedef struct Write_ {

        void (*Write)(Buffer *, char **, int);
        void (*Print)(Buffer *);

}Write;


/*
 * Estructura Number 3:
 */

typedef struct to_funct {

	char *Type;
	void (*Pointer_Function)(Write *, Buffer *, va_list);

}To_Funct;

/*
 * Structure Number 4:
 */

typedef struct Flags_{

	char *Number$;
	char *Number;
	char *Signal;

}Flags;

/*
 * Declaration of the function:
 */

void Buffer_Init
(Buffer *);

void WRITE
(Buffer *, char **, int);

void Print
(Buffer *);

void Write_Init
(Write *, void (*Function_Pointer_Write)(Buffer *, char **, int), void (*Function_Pointer_Print)(Buffer *));

int _Printf
(Write *, Buffer *, char **, va_list);

void Type
(Write *, Buffer *, char **, va_list);

int _printf
(char *, ...);


/*
 *  Funciones del formato de printf
 */

void Print_String
(Write *, Buffer *, va_list);

void Print_Character_Porcentaje
(Write *, Buffer *, va_list);

void Print_Character_Character
(Write *, Buffer *, va_list);

#endif
