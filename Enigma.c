#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

char rotor2[26][2] = {
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
    {'Z', 'C'}};

char rotor3[26][2] = {
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
    {'Z', 'P'}};

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

int incrementsToRotor1 = 0;
int incrementsToRotor2 = 0;
int incrementsToRotor3 = 0;

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

char implementRotorForward(char rotor[26][2], int increment, char charToChange)
{
    for (int i = 0; i < 26; i++)
    {
        char *ref = rotor[i];
        if (ref[0] == charToChange)
        {
            int newRotorIndex = i + increment;
            if (newRotorIndex > 25)
            {
                newRotorIndex -= 26;
            }
            char *refHere = rotor[newRotorIndex];
            // printf("character here (fwd): %c : %c\n", refHere[0], refHere[1]);

            char charNew = refHere[1];
            return charNew;
        }
    }
}

char implementRotorBackward(char rotor[26][2], int increment, char charToChange)
{
    for (int i = 0; i < 26; i++)
    {
        char *ref = rotor[i];
        if (ref[1] == charToChange)
        {
            int newRotorIndex = i - increment;
            if (newRotorIndex < 0)
            {
                newRotorIndex += 26;
            }
            char *refHere = rotor[newRotorIndex];
            // printf("character here (bwd): %c : %c\n", refHere[1], refHere[0]);

            char charNew = refHere[0];
            return charNew;
        }
    }
}

void incrementRotors()
{
    incrementsToRotor1++;
    if (incrementsToRotor1 > 26)
    {
        incrementsToRotor2++;
        incrementsToRotor1 -= 26;
        if (incrementsToRotor2 > 26)
        {
            incrementsToRotor3++;
            incrementsToRotor2 -= 26;
        }
    }
}

char machine(char charToUse)
{
    // rotor1 forward
    charToUse = implementRotorForward(rotor1, incrementsToRotor1, charToUse);
    // printf("letter after rotor fwd: %c\n", charToUse);

    // rotor2 forward
    charToUse = implementRotorForward(rotor2, incrementsToRotor2, charToUse);

    // rotor3 forward
    charToUse = implementRotorForward(rotor3, incrementsToRotor3, charToUse);

    // reflector
    for (int i = 0; i < sizeof(reflector); i++)
    {
        if (reflector[i][0] == charToUse)
        {
            // printf("character here (ref): %c : %c\n", reflector[i][0], reflector[i][1]);
            charToUse = reflector[i][1];
            break;
        }
        else if (reflector[i][1] == charToUse)
        {
            // printf("character here (ref): %c : %c\n", reflector[i][1], reflector[i][0]);
            charToUse = reflector[i][0];
            break;
        }
    }
    // printf("letter after reflector: %c\n", charToUse);

    // rotor3 backwards:
    charToUse = implementRotorBackward(rotor3, incrementsToRotor3, charToUse);

    // rotor2 backwards:
    charToUse = implementRotorBackward(rotor2, incrementsToRotor2, charToUse);

    // rotor1 backwards:
    charToUse = implementRotorBackward(rotor1, incrementsToRotor1, charToUse);
    // printf("letter after rotor bwd: %c\n", charToUse);

    // incrementing rotors
    incrementRotors();
    return (charToUse);
}

int main()
{
    char charToUse = 1;
    // char word[] = {'A', 'L', 'A', 'N', 'T', 'U', 'R', 'I', 'N', 'G'};
    char word[] = {'Q', 'X', 'D', 'X', 'D', 'F', 'B', 'L', 'B', 'J'};
    // char word[] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
    // char word[] = {'G', 'H', 'Q', 'X', 'Z', 'K', 'O', 'M', 'B', 'S'};

    for (int i = 0; i < sizeof(word); i++)
    {
        // printf("Index: %d; Character: %c\n", i, word[i]);
        charToUse = word[i];
        char newChar = machine(charToUse);
        printf("%c", newChar);
        // printf("incrementation: %i %i %i\n", incrementsToRotor1, incrementsToRotor2, incrementsToRotor3);
        // printf("\n\n");
    }
    printf("\n");
}