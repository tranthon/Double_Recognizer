# Double_Recognizer
A program that using DFA to recognize if the input is a double number or a floating point number

Example of accepted and rejected inputs:

/*
   pass : 
    x = 0.5 ;
    x = .5 ;
    x = .5e+4 ;
    x = .5e4 ;
    x = .5E4 ;
    x = .5E-4 ;
    x = +.5E-4 ;
    x = -.5E-4 ;
    x = -2.E-4 ;
    x = 23. ; 
    x = 23.e2 ;  
  */
  //////////////////////////////////

  // fail :
  //  x = -.E-4 ; // flaw
  //  x = -2.f-4 ; // this gives -6, for our purposes, f not legit modifier
  //  x =-2-4 ; // gvies -6
  //  x = 2.3-e4 ;  // no
  //  x = ++3 ; // no
  //  x = +-3 ; // it tolerated this but we won't
  //  x = 23.e+ ; // no
  //  x = 3.e+-2 ; // no

