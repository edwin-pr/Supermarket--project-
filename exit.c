#include "myshell.h"


/**

 * _exit - exits the shell

 * @info: the Structure with arguments

 * Return: exit if given exit status,  

 * (0) if info.argv[0] != "exit"

 */

int _exit(info_t *info)

{

        int check;


        if (info->argv[1]) /* If there is an exit arguement */

        {

                check = _erratoi(info->argv[1]);

                if (check == -1)

                {

                        info->status = 2;

                        print_error(info, "error occurred: ");

                        _eputs(info->argv[1]);

                        _eputchar('\n');

                        return (1);

                }

                info->error_no = _erratoi(info->argv[1]);

                return (-2);

        }

        info->error_no = -1;

        return (-2);

}


/**

 * _cd -   changes  current directory

 * @info: the structure with arguments

 * Return: 0 on success

 */

int _cd(info_t *info)

{

        char *s, *dir, buffer[1024];

        int chdir_var;


        s = getcwd(buffer, 1024);

        if (!s)

                _puts("TODO: >>getcwd failure emsg here<<\n");

        if (!info->argv[1])

        {

                dir = _getenv(info, "HOME=");

                if (!dir)

                        chdir_var = /* TODO: what exactly could this be ? */

                                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");

                else

                        chdir_var = chdir(dir);

        }

        else if (_strcmp(info->argv[1], "-") == 0)

        {

                if (!_getenv(info, "OLDPWD="))

                {

                        _puts(s);

                        _putchar('\n');

                        return (1);

                }

                _puts(_getenv(info, "OLDPWD=")), _putchar('\n');

                chdir_var = /* TODO: what exactly could this be ? */

                        chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");

        }

        else

                chdir_var = chdir(info->argv[1]);

        if (chdir_var == -1)

        {

                print_error(info, "cd error  ");

                _eputs(info->argv[1]), _eputchar('\n');

        }

        else

        {

                _setenv(info, "OLDPWD", _getenv(info, "PWD="));

                _setenv(info, "PWD", getcwd(buffer, 1024));

        }

        return (0);

}


/**

 * _help - help to  change the current directory

 * @info: Structure with arguments

 * Return: Always 0 on success

 */

int _help(info_t *info)

{

        char **double_args;


        double_args = info->argv;

        _puts("help call works. Function not yet implemented \n");

        if (0)

                _puts(*double_args); /* temp att_unused workaround */

        return (0);

}
