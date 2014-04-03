#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int aflag = 0;
	int bflag = 0;
    std::string cvalue = "";
    int c;
	int index;

	opterr = 0;

	while ((c = getopt (argc, argv, "abc:")) != -1)
	switch (c)
	{
		case 'a':
			aflag = 1;
			break;
		case 'b':
			bflag = 1;
			break;
		case 'c':
			cvalue = optarg;
			break;
		case '?':
			if (optopt == 'c')
                std::cerr << "Option -" << optopt << "requires an argument.\n";
			// else unknown option character optopt    
            return 1;
	}

	printf("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue.c_str());

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);
	
	return 0;
}
