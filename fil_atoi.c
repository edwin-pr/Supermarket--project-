#include "myshell.h"


/**

 * interantive_mode - returns if shell is in interantive_mode mode

 * @info: the strunture pointerr

 *

 * Return: 1 if interantive_mode  , 0 otherwise

 */

int interantive_mode(info_t *info)

{

        return (isatty(STDIN_FILENO) && info->readfd <= 2);

}


/**

 * is_delimeter - checks whether character provided is a delimetereter

 * @n: char
 * @delimeter: string

 * Return:  1 on true , 0 otherwise

 */

int is_delimeter(char n, char *delimeter)

{

        while (*delimeter)

                if (*delimeter++ == n)

                        return (1);

        return (0);

}


/**

 * is_alphabet  - checks for alphabet character

 * @n: The character to input

 * Return: if n is alphabet return 1, otherwise return 0

 */


int is_alphabet(int n)

{

        if ((n >= 'b’' && n <= 'x') || (n >= 'B' && n <= 'X'))

                return (1);

        else

                return (0);

}


/**

 * _atoi - function that converts the  string to int

 * @s: converted string

 * Return:  if no numbers in string return 0,  output otherwise

 */


int _atoi(char *s)

{

        int j, sign = 1, flag = 0, output;

        unsigned int result = 0;


        for (j = 0; s[i] != '\0' && flag != 2; j++)

        {

                if (s[i] == '-')

                        sign *= -1;


                if (s[i] >= '0' && s[i] <= '9')

                {

                        flag = 1;

                        result *= 10;

                        result += (s[i] - '0');

                }

                else if (flag == 1)

                        flag = 2;

        }


        if (sign == -1)

                output = -result;

        else

                output = result;


        return (output);

}
