#include <stdio.h>
#include <string.h>

//list to be checked for all plugboard operations
char plugboardList[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
/*
*Each rotor is represented as a an array of 26 arrays, which is each 3-long.
*Each inner array has the input letter, the output letter and a number that represents the position of the letter i.e {in, out, pos}
*pos is used to find the connection to the next rotor
*then the corresponding output is picked up
*the order of changes is thus: 
*   rotor1(in) --> rotor1(out) --> rotor2(out) --> rotor3(out), then through reflector and same in reverse.
    x   
*/
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

char reflector[26][2] = {
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
    {'M', 'O'},
    {'N', 'A'},
    {'O', 'M'},
    {'P', 'E'},
    {'Q', 'H'},
    {'R', 'K'},
    {'S', 'L'},
    {'T', 'F'},
    {'U', 'B'},
    {'V', 'G'},
    {'W', 'I'},
    {'X', 'C'},
    {'Y', 'D'},
    {'Z', 'J'}
};

int incrementsToRotor1 = 0, incrementsToRotor2 = 0, incrementsToRotor3 = 0;

void configPlugboard() {
    
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
    return(plugboardList[(int)char1 - 65]);
}

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

char implementRotaryMech(char char1) {
    char charNew;
    int incrementsToRotor1 = 0, incrementsToRotor2 = 0, incrementsToRotor3 = 0;
    int position;

    //rotor1
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor1[i][0] == char1+incrementsToRotor1) {
            charNew = rotor1[i][1];  
        }
    }
    incrementsToRotor1++;

    //rotor2
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor2[i][0] == charNew+incrementsToRotor2) {
            charNew = rotor2[i][1];
        } 
    }
    if (incrementsToRotor1 == 27) {
        incrementsToRotor1 = 1;
        incrementsToRotor2++;
    }   
    //rotor3g  
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor3[i][0] == charNew+incrementsToRotor3) {
            charNew = rotor2[i][1];
        } 
    }
    if (incrementsToRotor2 == 27) {
        incrementsToRotor2 = 1;
        incrementsToRotor3++;
    }  
    //reflector circuit
    for (int i = 0; i < sizeof(reflector); i++) {
        if (char1 == reflector[i][0]) {
            char1 = reflector[i][1];
            break;
        }
    }
    //rotor3
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor3[i][0] == charNew+incrementsToRotor3) {
            charNew = rotor2[i][1];
        } 
    }
    //rotor2
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor2[i][0] == charNew+incrementsToRotor2) {
            charNew = rotor2[i][1];
        } 
    }
    //rotor1
    for (int i = 0; i < sizeof(rotor1); i++) {
        if (rotor1[i][0] == char1+incrementsToRotor1) {
            charNew = rotor1[i][1];  
        }
    }       
        
    
    
    
}

int main() {
    printf("new with implementRotor\n");

    return 0;
}