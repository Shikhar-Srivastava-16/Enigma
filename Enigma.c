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
*   rotor1(in) --> rotor1(out) --> rotor2(out)[based on same number] --> rotor3(out)[based on same number], then through reflector and same in reverse.
*/
char rotor1[26][3] = {
    {'A', 'F', 1},
    {'B', 'P', 2},
    {'C', 'Q', 3},
    {'D', 'J', 4},
    {'E', 'H', 5},
    {'F', 'Y', 6},
    {'G', 'K', 7},
    {'H', 'O', 8},
    {'I', 'U', 9},
    {'J', 'L', 10},
    {'K', 'N', 11},
    {'L', 'M', 12},
    {'M', 'D', 13},
    {'N', 'A', 14},
    {'O', 'W', 15},
    {'P', 'X', 16},
    {'Q', 'G', 17},
    {'R', 'S', 18},
    {'S', 'Z', 19},
    {'T', 'I', 20},
    {'U', 'V', 21},
    {'V', 'C', 22},
    {'W', 'B', 23},
    {'X', 'R', 24},
    {'Y', 'T', 25},
    {'Z', 'E', 26}
};

char rotor2[26][3] = {
    {'A', 'Y', 1},
    {'B', 'V', 2},
    {'C', 'U', 3},
    {'D', 'P', 4},
    {'E', 'N', 5},
    {'F', 'B', 6},
    {'G', 'G', 7},
    {'H', 'W', 8},
    {'I', 'J', 9},
    {'J', 'X', 10},
    {'K', 'K', 11},
    {'L', 'Z', 12},
    {'M', 'R', 13},
    {'N', 'I', 14},
    {'O', 'O', 15},
    {'P', 'A', 16},
    {'Q', 'Q', 17},
    {'R', 'L', 18},
    {'S', 'F', 19},
    {'T', 'D', 20},
    {'U', 'S', 21},
    {'V', 'H', 22},
    {'W', 'M', 23},
    {'X', 'T', 24},
    {'Y', 'E', 25},
    {'Z', 'C', 26}
};

char rotor3[26][3] = {
    {'A', 'T', 1},
    {'B', 'V', 2},
    {'C', 'H', 3},
    {'D', 'X', 4},
    {'E', 'R', 5},
    {'F', 'J', 6},
    {'G', 'G', 7},
    {'H', 'W', 8},
    {'I', 'S', 9},
    {'J', 'I', 10},
    {'K', 'Y', 11},
    {'L', 'K', 12},
    {'M', 'A', 13},
    {'N', 'L', 14},
    {'O', 'B', 15},
    {'P', 'C', 16},
    {'Q', 'F', 17},
    {'R', 'M', 18},
    {'S', 'N', 19},
    {'T', 'Q', 20},
    {'U', 'D', 21},
    {'V', 'U', 22},
    {'W', 'O', 23},
    {'X', 'Z', 24},
    {'Y', 'E', 25},
    {'Z', 'P', 26}
};

char reflector[26][2] = {
    {'A', 'G'},
    {'B', 'T'},
    {'C', 'Z'},
    {'D', 'P'},
    {'E', 'K'},
    {'F', 'X'},
    {'G', 'W'},
    {'H', 'D'},
    {'I', 'J'},
    {'J', 'R'},
    {'K', 'Q'},
    {'L', 'Y'},
    {'M', 'S'},
    {'N', 'V'},
    {'O', 'B'},
    {'P', 'L'},
    {'Q', 'A'},
    {'R', 'C'},
    {'S', 'F'},
    {'T', 'M'},
    {'U', 'U'},
    {'V', 'H'},
    {'W', 'N'},
    {'X', 'I'},
    {'Y', 'O'},
    {'Z', 'E'}
};

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



int main() {
    printf("new\n");
    return 0;
}