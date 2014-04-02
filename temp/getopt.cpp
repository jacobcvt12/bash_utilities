#include <iostream>
#include <getopt.h>

int main(int argc, char* argv[])
{
    int opt, a, b, c;
    while ((opt = getopt(argc, argv, "abc:d")) != EOF)
        switch(opt)
        {
            case 'a': a = 1; std::cout <<" a is enabled"<<a <<std::endl; break;
            case 'b': b = 1; std::cout <<" b is enabled"<<b <<std::endl; break;
            case 'c': c = 1; std::cout <<" value of c is"<<optarg << std::endl; break;
            case '?': std::cerr <<  "usuage is \n -a : for enabling a \n -b : for enabling b \n -c: <value> ";
            default: std::cout<<std::endl; abort();
        }
    
    return 0;
}
