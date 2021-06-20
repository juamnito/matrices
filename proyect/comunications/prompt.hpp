#ifndef STD
#define STD

    #include <string>

#endif

class Prompt {
    public:
        std :: string normalString;
        std :: string mathString;

        Prompt( ){
            normalString = "> ";
            mathString = "$ ";
        }
};
