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

#define SIZE_BUFER 2


/*
 * Macro.
 */

#define WRITE_TO_LEETER(format)\
	{		       \
	if (buffer->Pointer_Init == buffer->Pointer_End)	\
		Print(buffer);					\
								\
        *(buffer->Pointer_Init) = *((*format)++);		\
        *(++buffer->Pointer_Init) = '\0';			\
        (buffer->Length)++;					\
								\
        if (buffer->Pointer_Init == buffer->Pointer_End)	\
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
 * Structure Number 3:
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
(Buffer *buffer);

void WRITE
(Buffer *buffer, char **format, int Length);

void Print
(Buffer *buffe);

void Write_Init
(Write *write, void (*Function_Pointer_Write)(Buffer *, char **, int), void (*Function_Pointer_Print)(Buffer *));

int _Printf
(Write *write, Buffer *buffer, char **format, va_list List_Argument);

#endif
