#include <stdio.h>
#include <string.h>

#include "rotor.h"

//list to be checked for all plugboard operations
char plugboardList[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char reflector[13][2] = {
    {'A', 'N'},
    {'B', 'U'},
    {'C', 'X'},
    {'D', 'Y'},
    {'E', 'P'},
    {'F', 'T'},
    {'G', 'V'},
    {'H', 'Q'},
    {'I', 'W'},
    {'J', 'Z'},
    {'K', 'R'},
    {'L', 'S'},
    {'M', 'O'}
};

void configPlugboard() {
    
    /*
     * takes command line input and changes the global plugboardList array
     * switches the desired letters' positions in plugboardList array
    */

    //fully functioning
    char change1;
    char change2;

    printf("Enter the letter to change followed by the letter to be changed to: ");
    scanf("%c %c", &change1, &change2);

    //change value of index int(var)
    plugboardList[(int)change1 - 65] = change2;
    plugboardList[(int)change2 - 65] = change1;     
}

char implementPlugboard(char char1) {
    /*
     * ciphers 'char1' and returns the value.
     * uses plugboardList as 26-letter cipher.
    */

    return(plugboardList[(int)char1 - 65]);
}

char implementRotorForward(struct Rotor rotor, char charToChange) {
    
    for (int i = 0; i < sizeof(rotor.mapping); i++) {
        if (rotor.mapping[i][0] == charToChange) {
            char charNew = rotor.mapping[i + rotor.rotations++][1];
            return charNew;
        }
    }
    return '-';   
}  

char implementRotorBackward(struct Rotor rotor, char charToChange) {

    for (int i = 0; i < sizeof(rotor.mapping); i++) {
        if (rotor.mapping[i][1] == charToChange) {  
            char charNew = rotor.mapping[i + rotor.rotations++][0];
            return charNew;
        }
    }
    return '-';
}

int main() { 

    char charToUse;

    printf("Enter letter to change here: ");
    scanf("%c", &charToUse);

    //rotor1 forward
    charToUse = implementRotorForward(rotor1, charToUse);
    printf("char after rotor1 forward %c\n", charToUse);
     
    //reflector
    for (int i = 0; i < sizeof(reflector); i++) {

        if (reflector[i][0] == charToUse) {
            charToUse = reflector[i][1];
            break;
        } else if (reflector[i][1] == charToUse) {
            charToUse = reflector[i][0];
            break;
        }
        
    }
    printf("char after reflector %c\n", charToUse);

//----working boundary----
  
    //rotor1 backwards:
    charToUse = implementRotorForward(rotor1, charToUse);
    printf("char after rotor1 backward %c\n", charToUse);

    //output
    printf("output is:\n%c\n", charToUse);

    return 0;
}