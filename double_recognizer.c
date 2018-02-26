//
//  double_recognizer.c
//  Double_Recognizer using DFA Transition Table
//
//  Created by Thong Tran on 11/13/17.
//  Copyright © 2017 Thong Tran. All rights reserved.
//

/*
 DFA Table
          0-9     +/-     .       e/E
   1      2        3      4       dead
 A 2      2     dead      9       6
   3      2     dead      4       dead
   4      5     dead   dead       dead
 A 5      5     dead   dead       6
   6      6,7      8   dead       dead
 A 7      7     dead   dead       dead
   8      7     dead   dead       dead
 A 9      9     dead   dead       6
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct State State;
typedef struct Node Node;

typedef struct State
{
    char name;
    bool accepting;
    Node * head;
    
}State;

typedef struct Node
{
    int index;
    char * symbol;
    Node * next;
}Node;

int main(int argc,  char * argv[])
{
    
    State * dfa = malloc(sizeof(State[9]));
    for(int i = 0; i < 9; ++i)
    {
        dfa[i].name = 'a';
        dfa[i].accepting = false;
        dfa[i].head = NULL;
        
    }
    
    printf("\nWelcome to Double Recognizer using DFA\n");
    printf("(A for Accept, R for Reject)\n\n");
    
    //State 1
    
    //A temp pointer to initialize each Node
    Node * temp = NULL;
    
    dfa[0].name = '1';
    dfa[0].accepting = false;
    dfa[0].head = (Node *)malloc(sizeof(Node));
    temp = dfa[0].head;
    //3 because 1 only has 3 non-dead edges
    for(int i = 1; i < 3; ++i)
    {
        //Create new node
        
        temp->next = (Node *)malloc(sizeof(Node));
        //Move the temp pointer to the next spot
        temp->index = 0;
        temp->symbol = NULL;
        
        temp = temp->next;
    }
    //Cap off the list
    temp = NULL;
    //Point the temp back at the head
    temp = dfa[0].head;
    //Node going to 2
    temp->index = 1;
    temp->symbol = "0123456789";
    temp = temp->next;
    //Node going to 3
    temp->index = 2;
    temp->symbol = "+-";
    temp = temp->next;
    //Node going to 4
    temp->index = 3;
    temp->symbol = ".";
    temp->next = NULL;
    
    //State 2
    Node * temp2 = NULL;
    
    dfa[1].name = '2';
    dfa[1].accepting = true;
    dfa[1].head = (Node *)malloc(sizeof(Node));
    temp2 = dfa[1].head;
    
    //Only 3 non-dead edges
    for(int i = 1; i < 3; ++i){
        temp2->next = (Node *)malloc(sizeof(Node));
        temp2->index = 0;
        temp2->symbol = NULL;
        temp2 = temp2->next;
    }
    temp2 = NULL;
    temp2 = dfa[1].head;
    
    //Node going to 2
    temp2->index = 1;
    temp2->symbol = "0123456789";
    temp2 = temp2->next;
    //Node going to 9
    temp2->index = 8;
    temp2->symbol = ".";
    temp2 = temp2->next;
    //Node going to 6
    temp2->index = 5;
    temp2->symbol = "Ee";
    temp2->next = NULL;
    
    
    //State 3
    Node * temp3 = NULL;
    
    dfa[2].name = '3';
    dfa[2].accepting = false;
    dfa[2].head = (Node *)malloc(sizeof(Node));
    temp3 = dfa[2].head;
    
    //Only 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        
        temp3->next = (Node *)malloc(sizeof(Node));
        temp3->index = 0;
        temp3->symbol = NULL;
        temp3 = temp3->next;
        
    }
    
    temp3 = NULL;
    
    temp3 = dfa[2].head;
    
    //Node going to 2
    temp3->index = 1;
    temp3->symbol = "0123456789";
    temp3 = temp3->next;
    //Node going to 4
    temp3->index = 3;
    temp3->symbol = ".";
    temp3->next = NULL;
    
    
    //State 4
    //  Node * temp4 = NULL;
    
    dfa[3].name = '4';
    dfa[3].accepting = false;
    dfa[3].head = (Node *)malloc(sizeof(Node));
    
    //Node going to 5
    dfa[3].head->index = 4;
    dfa[3].head->symbol = "0123456789";
    dfa[3].head->next = NULL;
    
    //State 5
    Node * temp5;
    dfa[4].name = '5';
    dfa[4].accepting = true;
    dfa[4].head = (Node *)malloc(sizeof(Node));
    
    temp5 = dfa[4].head;
    
    //State 5 has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp5->next = (Node *)malloc(sizeof(Node));
        temp5->index = 0;
        temp5->symbol = NULL;
        temp5 = temp5->next;
    }
    
    temp5 = NULL;
    
    temp5 = dfa[4].head;
    
    //Node going back to 5
    temp5->index = 4;
    temp5->symbol = "0123456789";
    temp5 = temp5->next;
    
    //Node going to 6
    temp5->index = 5;
    temp5->symbol = "Ee"; //fix this!
    temp5->next = NULL;
    
    
    //State 6
    Node * temp6 = NULL;
    dfa[5].name = '6';
    dfa[5].accepting = false;
    dfa[5].head = (Node *)malloc(sizeof(Node));
    
    temp6 = dfa[5].head;
    
    //State 6 has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp6->next = (Node *)malloc(sizeof(Node));
        temp6->index = 0;
        temp6->symbol = NULL;
        temp6 = temp6->next;
    }
    
    temp6 = NULL;
    
    temp6 = dfa[5].head;
    
    //Node going to 7
    temp6->index = 6;
    temp6->symbol = "0123456789";
    temp6 = temp6->next;
    
    //Node going to 8
    temp6->index = 7;
    temp6->symbol  = "+-";
    temp6->next = NULL;
    
    
    //State 7
    
    dfa[6].name = '7';
    dfa[6].accepting = true;
    dfa[6].head = (Node *)malloc(sizeof(Node));
    
    //Node going back to g
    dfa[6].head->index = 6;
    dfa[6].head->symbol = "0123456789";
    dfa[6].head->next = NULL;
    
    
    //State 8
    dfa[7].name = '8';
    dfa[7].accepting = false;
    dfa[7].head = (Node *)malloc(sizeof(Node));
    
    dfa[7].head->index = 6;
    dfa[7].head->symbol = "0123456789";
    dfa[7].head->next = NULL;
    
    
    //State 9
    Node * temp9 = NULL;
    dfa[8].name = '9';
    dfa[8].accepting = true;
    dfa[8].head = (Node *)malloc(sizeof(Node));
    temp9 = dfa[8].head;
    
    //State 9 has 2 non-dead edges
    for(int i = 1; i < 2; ++i)
    {
        temp9->next = (Node *)malloc(sizeof(Node));
        temp9->index = 0;
        temp9->symbol = NULL;
        temp9 = temp->next;
    }
    
    temp9 = NULL;
    temp9 = dfa[8].head;
    
    //Node going back to 9
    temp9->index = 8;
    temp9->symbol = "0123456789";
    temp9 = temp9->next;
    
    //Node going to 6
    temp9->index = 5;
    temp9->symbol = "eE";
    temp9->next = NULL;
    
    //Open the txt file.
    if(argc == 2){
        //Grab the file name from argv[1]
        char tempName[100];
        strcpy(tempName, argv[1]);
        FILE *file = fopen(tempName,"r");
        
        
        if(file != NULL){
            char line[256];
            //read line by line
            while(fgets(line, sizeof line, file) != NULL) {
                //Index number indicating current state
                int currState = 0;
                //Make sure we aren't dead
                bool dead = false;
                int i = 0;
                printf("\n%s", line);
                Node * holdState = dfa[currState].head;
                //While we haven't hit the dead state an there are more chars
                while(!dead && line[i] != '\n'){
                    //Go to the beginning of the list of edges for current state
                    if(holdState != NULL){
                        //If 9 should follow this node
                        if(strchr((*holdState).symbol, line[i])){
                            //Move to the new state after consuming
                            currState = (*holdState).index;
                            ++i;
                            holdState = dfa[currState].head;
                        }
                        else{
                            //Shouldn't follow node, go to next node
                            holdState = (*holdState).next;
                        }
                    }
                    else
                        //End of an node list, hit dead state
                        dead = true;
                }
                
                //If the current state is accepting and we aren't dead
                if(dfa[currState].accepting && !dead)
                    printf("-> A\n");
                else
                    printf("-> R\n");
                
            }
            fclose(file);
        }
        else{
            perror(tempName);//if file didn't open
        }
    }else{
        printf("Can not open the file!\n");
    }
    
    return 0;
}


