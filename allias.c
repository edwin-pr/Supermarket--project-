#include "myshell.h"

/**

 * _allias_history  - displays the history alias

 * @info:  this structure with arguments.

 *  Return: 0 success

 */

int _allias_history (info_t *info)

{

        print_list(info->history);

        return  (0);

}


/**

 * _allias_unset - sets alias to string_value

 * @info: parameter structure

 * @string_value:  string_value alias

 *

 * Return: 0 success,1 otherwise.

 */

int _allias_unset(info_t *info, char *string_value)

{

        char *v, s;

        int val;


        v =strchr(string_value, '=');

        if (!v)

                return  (1);

        s= *v;

        * v= 0;

        val = delete_node_at_index(&(info->alias),

                get_node_index(info->alias, node_starts_with(info->alias, string_value, -1)));

        *v = s;

        return  (val);

}


/**

 * allias_set - sets alias to string_value

 * @info: parameter structure

 * @string_value: string_value alias

 * Return: 0 on success ,1 otherwise

 */

int allias_set(info_t *info, char *string_value)

{

        char *v;


        p =strchr(string_value, '=');

        if (!v)

                return  (1);

        if (!*++v)

                return  (_allias_unset(info, string_value));


        _allias_unset(info, string_value);

        return  (add_node_end(&(info->alias), string_value, 0) == NULL);

}


/**

 * _alias_print - prints an alias string_value

 * @node: alias node

 * Return : 0 on success , 1 otherwise

 */

int _alias_print(list_t *node)

{

        char *v = NULL, *b = NULL;


        if (node)

        {

                v =strchr(node->string_value, '=');

                for (b = node->string_value; b<= v; b++)

                _putchar(*b);

                _putchar('\'');

                _puts(v + 1);

                _puts("'\n");

                return  (0);

        }

        return  (1);

}


/**

 * _alias - checks the alias builtin 

 * @info: the  arguments used to maintain function prototype.

 *  Return : 0 on success

 */

int _alias(info_t *info)

{

        int i = 0;

        char *v = NULL;

        list_t *node = NULL;


        if (info->argc == 1)

        {

                node = info->alias;

                while (node)

                {

                        _alias_print(node);

                        node = node->next;

                }

                return  (0);

        }

        for (i = 1; info->argv[i]; i++)

        {

                v =strchr(info->argv[i], '=');

                if (v)

                        allias_set(info, info->argv[i]);

                else

                        _alias_print(node_starts_with(info->alias, info->argv[i], '='));

        }


        return  (0);

}
