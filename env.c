
#include "myshell.h"


/**

 * _env - prints current environment

 * @info: structure with arguments

 * Return: 0 on success

 */

int _env(info_t *info)

{

        print_list_str(info->env);

        return (0);

}


/**

 * _get_env - function that gets the value of an environment variable

 * @info: structure with arguments.

 * @name: env name

 * Return: the value on success

 */

char *_get_env(info_t *info, const char *name)

{

        list_t *node = info->env;

        char *q;


        while (node)

        {

                q = starts_with(node->str, name);

                if (q && *q)

                        return (q);

                node = node->next;

        }

        return (NULL);

}


/**

 * _set_env - sets  a new environment variable

 * @info: structure arguments.

 *  Return: Always 0 on success

 */

int _set_env(info_t *info)

{

        if (info->argc != 3)

        {

                _eputs("check the amount of args well\n");

                return (1);

        }

        if (_setenv(info, info->argv[1], info->argv[2]))

                return (0);

        return (1);

}


/**

 * _unset_env - unset an environment variable

 * @info: structure arguments

 * Return: Always 0 on success

 */

int _unset_env(info_t *info)

{

        int i;


        if (info->argc == 1)

        {

                _eputs("less arguements.\n");

                return (1);

        }

        for (i = 1; i <= info->argc; i++)

                _unsetenv(info, info->argv[i]);


        return (0);

}


/**

 * _env_list - creates env linked list

 * @info: structure arguments

 * Return: Always 0 on success

 */

int _env_list(info_t *info)

{

        list_t *node = NULL;

        size_t i;


        for (i = 0; environ[i]; i++)

                add_node_end(&node, environ[i], 0);

        info->env = node;

        return (0);

}
