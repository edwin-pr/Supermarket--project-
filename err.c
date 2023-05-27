
#include "myshell.h"


/**

 * _eputstring - prints an inputed string in shell

 * @string_value: string being printed

 * Return: nothing on success

 */

void _eputstring(char *string_value)

{

        int i = 0;


        if (!string_value)

                return;

        while (string_value[i] != '\0')

        {

                _eputcharacter(string_value[i]);

                i++;

        }

}


/**

 * _eputcharacter - it writes the char c to stderr function

 * @c: The char printed

 * Return: On success 1.

 * otherwise -1 , and errno is set.

 */

int _eputcharacter(char c)

{

        static int i;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)

        {

                write(2, buf, i);

                i = 0;

        }

        if (c != BUF_FLUSH)

                buf[i++] = c;

        return (1);

}


/**

 * _putfiledescriptor - writes the character c to given filedescriptor

 * @c: The character to print

 * @filedescriptor: The filedescriptor written

 * Return: On success 1.

 * otherwise, -1 , and errno is set.

 */

int _putfiledescriptor(char c, int filedescriptor)

{

        static int i;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)

        {

                write(filedescriptor, buf, i);

                i = 0;

        }

        if (c != BUF_FLUSH)

                buf[i++] = c;

        return (1);

}


/**

 * _putsfiledescriptor - prints an input string_value

 * @string_value: the string_value to be printed

 * @filedescriptor: the filedescriptor written

 * Return: the number of chars put

 */

int _putsfiledescriptor(char *string_value, int filedescriptor)

{

        int i = 0;


        if (!string_value)

                return (0);

        while (*string_value)

        {

                i += _putfiledescriptor(*string_value++, filedescriptor);

        }

        return (i);

}
