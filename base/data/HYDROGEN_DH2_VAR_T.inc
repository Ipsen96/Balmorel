PARAMETER HYDROGEN_DH2_VAR_T(CCCRRRAAA,SSS,TTT)               
* No variation                                                
;                                                             
*HYDROGEN_DH2_VAR_T(RRR,SSS,TTT)=0;                           
HYDROGEN_DH2_VAR_T(RRR,SSS,TTT)$SUM(Y,HYDROGEN_DH2(Y,RRR)) =1;