//
//  dfa.c
//  Double_Recognizer
//
//  Created by Thong Tran on 11/13/17.
//  Copyright © 2017 Thong Tran. All rights reserved.
//

#include "dfa.h"

//Intinial DFA Table
void InitialDFA(State * dfa){
    
    //State 1
    
    //A temp pointer to initialize each Node
    Node * temp = NULL;
    
    dfa[0].name = '1';
    dfa[0].accepting = false;
    temp = dfa[0].head;
    //3 because 1 only has 3 non-dead edges
    for(int i = 0; i < 3; ++i)
    {
        //Create new node
        temp = (Node *)malloc(sizeof(Node));
        //Move the temp pointer to the next spot
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
    temp2 = dfa[1].head;
    
    //Only 3 non-dead edges
    for(int i = 0; i < 3; ++i)
    {
        temp2 = (Node *)malloc(sizeof(Node));
        
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
    temp2->symbol = "Ee"; //fix this
    temp2->next = NULL;
    
    
    
    //State 3
    
    Node * temp3 = NULL;
    
    dfa[2].name = '3';
    dfa[2].accepting = false;
    temp3 = dfa[2].head;
    
    //Only 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp3 = (Node *)malloc(sizeof(Node));
        
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
    
    Node * temp4 = NULL;
    
    dfa[3].name = '4';
    dfa[3].accepting = false;
    temp4 = dfa[3].head;
    
    //4 has only 1 non-dead node
    temp4 = (Node *)malloc(sizeof(Node));
    temp4 = temp4->next;
    
    //temp4->next = NULL;
    temp4 = NULL;
    temp4 = dfa[3].head;
    
    //Node going to 5
    temp4->index = 4;
    temp4->symbol = "0123456789";
    temp4->next = NULL;
    
    
    //State 5
    
    Node * temp5;
    dfa[4].name = '5';
    dfa[4].accepting = true;
    
    //State 5 has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp5 = (Node *)malloc(sizeof(Node));
        
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
    temp6 = dfa[5].head;
    
    //State 6 has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp6 = (Node *)malloc(sizeof(Node));
        
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
    
    Node * temp7 = NULL;
    
    dfa[6].name = '7';
    dfa[6].accepting = true;
    temp7 = dfa[6].head;
    
    
    //State 7 has 1 non-dead node
    temp7 = (Node *)malloc(sizeof(Node));
    
    //temp7->next = NULL;
    temp7 = NULL;
    
    temp7 = dfa[6].head;
    
    //Node going back to g
    temp7->index = 6;
    temp7->symbol = "0123456789";
    temp7->next = NULL;
    

    //State 8
    
    Node * temp8 = NULL;
    dfa[7].name = '8';
    dfa[7].accepting = false;
    temp8 = dfa[7].head;
    
    //State 8 has 1 non-dead node
    temp8 = (Node *)malloc(sizeof(Node));
    
    //temp8->next = NULL;
    temp8 = NULL;
    
    temp8 = dfa[7].head;
    
    temp8->index = 7;
    temp8->symbol = "0123456789";
    temp8->next = NULL;
    
    
    //State 9
    
    Node * temp9 = NULL;
    dfa[8].name = '9';
    dfa[8].accepting = true;
    temp9 = dfa[8].head;
    
    //State 9 has 2 non-dead edges
    for(int i = 0; i < 2; ++i)
    {
        temp9 = (Node *)malloc(sizeof(Node));
        
        temp = temp->next;
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
    
    
}

