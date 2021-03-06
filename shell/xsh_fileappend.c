/**
 * File: xsh_fileappend.c
 * Description: File append command for tempfs
 * Author: Owen Royall-Kahin
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <tempfs.h>

/**
 * Shell command (fileappend).
 * @param nargs  number of arguments in args array
 * @param args   array of arguments
 * @return OK for success, SYSERR for syntax error
 */
shellcmd xsh_fileappend(int nargs, char *args[])
{


    /* Output help, if '--help' argument was supplied */
    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
    {
        printf("Usage: %s filename [\"data\"]\n\n", args[0]);
        printf("Description:\n");
        printf("\tAdds to the end of a file in tempfs.\n");
        printf("Options:\n");
        printf("\t--help\tdisplay this help and exit\n");
        return OK;
    }

    /* Check for correct number of arguments */
    if (nargs < 3)
    {
        fprintf(stderr, "%s: too few arguments\n", args[0]);
        fprintf(stderr, "Try '%s --help' for more information\n",
                args[0]);
        return SYSERR;
    }
    if (nargs > 3)
    {
        fprintf(stderr, "%s: too many arguments\n", args[0]);
        fprintf(stderr, "Try '%s --help' for more information\n",
                args[0]);
        return SYSERR;
    }
    
    fileappend(args[1], args[2]);

    return OK;
}
