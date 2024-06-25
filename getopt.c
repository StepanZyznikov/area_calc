#include "getopt.h"
#include "stddef.h"
#include "stdio.h"

int get_flags(int argc, char *argv[])
{
    int flag = 0;
	const char* short_options = "hriRI";

	const struct option long_options[] = {
		{"help",          no_argument,       &flag, 1},
		{"root",          no_argument,       &flag, 2},
		{"iterations",    no_argument,       &flag, 3},
        {"test-root",     required_argument, &flag, 4},
		{"test-integral", required_argument, &flag, 5},
		{NULL, 0, NULL, 0}
	};

    char c;
	while ((c = getopt_long(argc, argv, short_options, long_options, NULL)) !=-1)
    {
        if (c == 'h')
            flag = 1;
        if (c == 'r')
            flag = 2;
        if (c == 'i')
            flag = 3;
        if (c == 'R')
            flag = 4;
        if (c == 'I')
            flag = 5;
    }
    return flag;
}  