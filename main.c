/* 
 * File:   main.c
 * Author: Jared Keirle
 *
 * Created on April 22, 2016, 10:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/*
 * 
 */
int main(int argc, char** argv) {
    //An int to store the number that was entered
    int num;
    
    //Apparently this is necessary for scan...
    setbuf(stdout, NULL);

    //Ask for a number
    printf("Enter the number to play the game of threes on:\n");
    
    //WHY DO YOU NEED TO PRESS ENTER TWICE?????????????????? I DON'T KNOW
    scanf ("%d", &num);
    
    printf("Starting the game of threes with the number \"%d\"\n", num);
    
    while (num > 1){
        //There's no strings in c... thats fun
        //Determine if we are adding, subtracting, or doing nothing
        char numberChange[3];
        memcpy(numberChange, ((num % 3 > 0) ? ((num % 3 == 1) ? "- 1" : "+ 1") : "+ 0"), 3);
        
        int newNum;
        
        if (strcmp(numberChange, "+ 0") == 0){
            newNum = num / 3;
        } else if (strcmp(numberChange, "- 1") == 0){
            newNum = (num - 1) / 3;
        } else if (strcmp(numberChange, "+ 1") == 0){
            newNum = (num + 1) / 3;
        }
        
        printf("(%d %s) / 3 = %d\n", num, numberChange, newNum);
        
        num = newNum;
    }
    return (EXIT_SUCCESS);
}


