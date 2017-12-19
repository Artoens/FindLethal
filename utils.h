//utils.h
//
//Library of routins 
//source: "ECAM-C3BE-2017-Mini-Projet-Example"

#include <stdio.h>

#ifndef FINDLETHAL_UTILS
#define FINDLETHAL_UTILS

// Function trimming the string 
//from all blanc characters before and after the chain 
char *trim (char *str);

// Function reading a line of a text file opened before
//and returning a char*
char* readString (FILE* file);

// Function reading a line of a text file opened before
//and returninf an int
int readInt (FILE* file);

#endif