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
*   rotor1(in) --> rotor1(out) --> rotor2(out)[based on same number] --> rotor3(out)[based on same number]
*/
char rotor1[][] = {
    {A, f, 1},
    {B, p, 2},
    {C, q, 3},
    {D, j, 4},
    {E, h, 5},
    {F, y, 6},
    {G, k, 7},
    {H, o, 8},
    {I, u, 9},
    {J, l, 10},
    {K, n, 11},
    {L, m, 12},
    {M, d, 13},
    {N, a, 14},
    {O, w, 15},
    {P, x, 16},
    {Q, g, 17},
    {R, s, 18},
    {S, z, 19},
    {T, i, 20},
    {U, v, 21},
    {V, c, 22},
    {W, b, 23},
    {X, r, 24},
    {Y, t, 25},
    {Z, e, 26},
}

char rotor2[][] = {
    {A, y, 1},
    {B, v, 2},
    {C, u, 3},
    {D, p, 4},
    {E, n, 5},
    {F, b, 6},
    {G, g, 7},
    {H, w, 8},
    {I, j, 9},
    {J, x, 10},
    {K, k, 11},
    {L, z, 12},
    {M, r, 13},
    {N, i, 14},
    {O, o, 15},
    {P, a, 16},
    {Q, q, 17},
    {R, l, 18},
    {S, f, 19},
    {T, d, 20},
    {U, s, 21},
    {V, h, 22},
    {W, m, 23},
    {X, t, 24},
    {Y, e, 25},
    {Z, c, 26},
}

char rotor3[][] = {
    {A, t, 1},
    {B, v, 2},
    {C, h, 3},
    {D, x, 4},
    {E, r, 5},
    {F, j, 6},
    {G, g, 7},
    {H, w, 8},
    {I, s, 9},
    {J, i, 10},
    {K, y, 11},
    {L, k, 12},
    {M, a, 13},
    {N, l, 14},
    {O, b, 15},
    {P, c, 16},
    {Q, f, 17},
    {R, m, 18},
    {S, n, 19},
    {T, q, 20},
    {U, d, 21},
    {V, u, 22},
    {W, o, 23},
    {X, z, 24},
    {Y, e, 25},
    {Z, p, 26},
}


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
    return 0;
}