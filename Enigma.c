#include <stdio.h>
#include <string.h>

//list to be checked for all plugboard operations
char plugboardList[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char rotor1[26][2] = {
    {'A', 'F'},
    {'B', 'P'},
    {'C', 'Q'},
    {'D', 'J'},
    {'E', 'H'},
    {'F', 'Y'},
    {'G', 'K'},
    {'H', 'O'},
    {'I', 'U'},
    {'J', 'L'},
    {'K', 'N'},
    {'L', 'M'},
    {'M', 'D'},
    {'N', 'A'},
    {'O', 'W'},
    {'P', 'X'},
    {'Q', 'G'},
    {'R', 'S'},
    {'S', 'Z'},
    {'T', 'I'},
    {'U', 'V'},
    {'V', 'C'},
    {'W', 'B'},
    {'X', 'R'},
    {'Y', 'T'},
    {'Z', 'E'}
};

char rotor2[26][3] = {
    {'A', 'Y'},
    {'B', 'V'},
    {'C', 'U'},
    {'D', 'P'},
    {'E', 'N'},
    {'F', 'B'},
    {'G', 'G'},
    {'H', 'W'},
    {'I', 'J'},
    {'J', 'X'},
    {'K', 'Z'},
    {'L', 'K'},
    {'M', 'R'},
    {'N', 'I'},
    {'O', 'A'},
    {'P', 'O'},
    {'Q', 'L'},
    {'R', 'Q'},
    {'S', 'F'},
    {'T', 'D'},
    {'U', 'S'},
    {'V', 'H'},
    {'W', 'M'},
    {'X', 'T'},
    {'Y', 'E'},
    {'Z', 'C'}
};

char rotor3[26][3] = {
    {'A', 'T'},
    {'B', 'V'},
    {'C', 'H'},
    {'D', 'X'},
    {'E', 'R'},
    {'F', 'J'},
    {'G', 'G'},
    {'H', 'W'},
    {'I', 'S'},
    {'J', 'I'},
    {'K', 'Y'},
    {'L', 'K'},
    {'M', 'A'},
    {'N', 'L'},
    {'O', 'B'},
    {'P', 'C'},
    {'Q', 'F'},
    {'R', 'M'},
    {'S', 'N'},
    {'T', 'Q'},
    {'U', 'D'},
    {'V', 'U'},
    {'W', 'O'},
    {'X', 'Z'},
    {'Y', 'E'},
    {'Z', 'P'}
};

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

int incrementsToRotor1 = 0, incrementsToRotor2 = 0, incrementsToRotor3 = 0;

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

//----working boundary----

char implementRotorForward(char rotor[26][2], int increment, char charToChange) {
    
    for (int i = 0; i < sizeof(rotor); i++) {
        if (rotor[i][0] == charToChange) {
            charToChange = rotor1[i + increment][1];
        }
    }
    return charToChange;
}  

char implementRotorBackward(char rotor[26][2], int increment, char charToChange) {

    for (int i = 0; i < sizeof(rotor); i++) {
        if (rotor[i][1] == charToChange) {
            charToChange = rotor1[i - increment][0];
        }
    }
    return charToChange;
}  

int main() { 

    char charToUse;

    printf("Enter letter to change here: ");
    scanf("%c", &charToUse);

    printf("%c is entered.\n", charToUse);

    //rotor1 forward
    charToUse = implementRotorForward(rotor1, incrementsToRotor1, charToUse);
    incrementsToRotor1++;
    if (incrementsToRotor1 == 27) {
        incrementsToRotor1 = 1;
    }

    //reflector
    for (int i = 0; i < sizeof(reflector); i++) {
        if (reflector[0] == charToUse) {
            charToUse = reflector[1];
        } else if (reflector[1] == charToUse) {
            charToUse = reflector[0];
        }
        
        
    }

    //rotor1 backwards:
    charToUse = implementRotorBackward(rotor1, incrementsToRotor1, charToUse);

    //output
    printf("output is:\n%c\n", charToUse);

    return 0;
}