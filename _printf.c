#include "Holberton.h"


int _Printf
(Write *write, Buffer *buffer, char **format, va_list List_Argument)
{
	if (!(*format) || !(**format))
              return (buffer->Length_Total);
	else
	{
		write->Write(buffer, format, 0);
		(void)List_Argument;
//              return (_Printf(write, buffer, format, List_Argument));
		return 0;
	}
}

int _printf(char *format, ...)
{
        /* Inicializamos variables */

        Buffer buffer;
        Write write;
        va_list Lista_Arguments;

        /* Inicializamos las funciones de write y el Buffer */

        Write_Init(&write, WRITE, Print);
        Buffer_Init(&buffer);

        va_start(Lista_Arguments, format);
        _Printf(&write, &buffer, &format, Lista_Arguments);
        va_end(Lista_Arguments);

	write.Print(&buffer);

	return (buffer.Length_Total);
}

int main(void)
{
        char s[] = "Hola como estas espero que muy bien :3";
        char *format = s;

        _printf(format);
}
