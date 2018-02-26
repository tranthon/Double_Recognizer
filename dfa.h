//
//  dfa.h
//  Double_Recognizer
//
//  Created by Thong Tran on 11/13/17.
//  Copyright © 2017 Thong Tran. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct State State;

//Represents the connections between states
typedef struct Node
{
    int index;
    char * symbol;
    Node * next;// = NULL;
}Node;

//Represents the states
typedef struct State
{
    char name;
    bool accepting;
    Node * head;// = NULL;
    
}State;



//Creates the state dfa
//Input: A State array by reference
//Output: N/A
void InitialDFA(State * dfa);
