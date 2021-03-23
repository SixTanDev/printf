# _Printf function similar to the printf function that appears in language C

It is a function where you can enter an unlimited number of arguments, the arguments can be of any type (the basic ones: char, int, float and double) with their respective pointers to each type.

The first argument of the function is the one that will be sent to the stdout of the environment that called it, in this case it can be the screen or the file; if we are in an operating system like linux we use the operator **>, >>** to redirect the output of the stout.

To improve the different types of data we apply the **%** character together with a **special character**, in the table below these special characters are shown. there may be spaces between the **%** character and the **special character**, such as.

> _printf("hello %s this is the %s of lov%c\n", *Pointer_String, Array, Character);

> hello world this is the equation of love

There can be a space between% and the special character.

* Where **Number** contain the number 4.

> _printf("Number: [%"Space Character" d]", Number);

> Number: [4]

***Note: This function does not take into account The Width Option of the C language printf

| Special Character | Descripction                                                                 |
| ----------------- | ---------------------------------------------------------------------------- |
| c                 | Print a singlecharacter                                                      |
| d                 | Print adecimal (base 10) number                                              |
| i                 | Print aninteger in base 10                                                   |
| s                 | Print astring of characters                                                  |
| %                 | Print a percent sign (\%also works)                                          |

### requirements 📋

_Linux distribution_
_C compiler_

### Instalation 🔧

_Clone repository_

```
git clone https://github.com/epg01/printf.git
```

The code is compiled with the ```gcc 4.8.4``` compiler using the ```-Wall -Werror -Wextra``` and ```-pedantic``` flags, therefore to get the executable file use the following command.

>> gcc -Wall -Werror -Wextra -pedantic *.c -o printf
>> ./printf   to execute the program
 
### Code examples⌨️

_Explain what these tests verify and why_

```
int main()
{
    char Caracter = 'Y';
    char *Nme = "Holberton";
    int Nmber = 10

    _printf("%c, ", Caracter);
    _printf("%s, ", Nme);
    _printf("%i.\\n", Nmber);

}

OUTPUT: 
Y,Holberton, 10

This function print diferent types of variables, like char, int, or even character string.
in case the variable type is different, the format must correspond to the type of variable put in the function.
