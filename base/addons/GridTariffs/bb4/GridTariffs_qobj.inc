* Additions to the objective function:


*** Grid tariffs on District heating
* Fixed component and subscribed power (per MW installed)
                 + IOF1000 * SUM(IR, SUM(IAGK_HASORPOT(Y,IA,IGETOH)$RRRAAA(IR,IA),
                         IGR_PRICE_TECH(Y,IR,'GRDSUBS')  * (VGKNACCUMNET(Y,IA,IGETOH)
$ifi %DECOM%==yes   -VDECOM_EXO_ACCUM(Y,IA,IGETOH)$IGDECOMEXOPOT(Y,IA,IGETOH)
+ GKFX(Y,IA,IGETOH)) /(GDATA(IGETOH,'GDFE') *(1$(NOT GEFFRATE(IA,IGETOH))+GEFFRATE(IA,IGETOH)))     ))
* Energy charge winter
                 + SUM(IGR_TIME('GRDECW',IR,IS3,T), SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                   ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDECW')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Energy charge summer
                 + SUM(IGR_TIME('GRDECS',IR,IS3,T), SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                   ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDECS')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Energy charge TOU step 1
                 + SUM(IGR_TIME('GRDTOU1',IR,IS3,T),  SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                   ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDTOU1')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Energy charge TOU step 2
                 + SUM(IGR_TIME('GRDTOU2',IR,IS3,T),  SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                 ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDTOU2')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Energy charge TOU step 3
                 + SUM(IGR_TIME('GRDTOU3',IR,IS3,T),  SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                   ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDTOU3')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Energy charge TOU step 4
                 + SUM(IGR_TIME('GRDTOU4',IR,IS3,T),  SUM(IAGK_HASORPOT(Y,IA,IGETOH)$(RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                 ),IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_TECH(Y,IR,'GRDTOU4')  * VGE_T(Y,IA,IGETOH,IS3,T)))
* Demand charge winter
                 + IOF1000 * SUM((IR,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDCW',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), SUM(IA$(SUM(IGETOH,IAGK_HASORPOT(Y,IA,IGETOH)) AND RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                 ), VGETOH_CAP1(Y,IA,MMM)) *  IGR_PRICE_TECH(Y,IR,'GRDDCW'))/(IGR_MONTHSINSIM/card(MMM))    !! Demand charge winter
* Demand charge summer
                 + IOF1000 * SUM((IR,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDCS',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), SUM(IA$(SUM(IGETOH,IAGK_HASORPOT(Y,IA,IGETOH)) AND RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                 ), VGETOH_CAP1(Y,IA,MMM)) *  IGR_PRICE_TECH(Y,IR,'GRDDCS'))/(IGR_MONTHSINSIM/card(MMM))    !! Demand charge summer
* Demand charge 2 (e.g for spring and fall months)
                 + IOF1000 * SUM((IR,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDC2',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), SUM(IA$(SUM(IGETOH,IAGK_HASORPOT(Y,IA,IGETOH)) AND RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                  ), VGETOH_CAP1(Y,IA,MMM)) *  IGR_PRICE_TECH(Y,IR,'GRDDC2'))/(IGR_MONTHSINSIM/card(MMM))    !! Demand charge 2

* Demand charge TOU
                 + IOF1000 * SUM((IR,MMM),   SUM(IA$(SUM(IGETOH,IAGK_HASORPOT(Y,IA,IGETOH)) AND RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                  ), VGETOH_CAP2(Y,IA,MMM)) *  IGR_PRICE_TECH(Y,IR,'GRDDCTOU'))/(IGR_MONTHSINSIM/card(MMM))
* Demand charge yearly
                 + IOF1000 * SUM(IR,   SUM(IA$(SUM(IGETOH,IAGK_HASORPOT(Y,IA,IGETOH)) AND RRRAAA(IR,IA)
$ifi %INDUSTRY%==yes  AND NOT INDUSTRY_AAA(IA)
$ifi %INDIVUSERS%==yes  AND NOT INDUSTRY_AAA(IA)
                 ), VGETOH_CAPY(Y,IA)) *  IGR_PRICE_TECH(Y,IR,'GRDDCY'))


* Tariffs on user groups
                 + SUM((IGR_TIME('GRDECW',IR,IS3,T),DEUSER),   IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDECW')  * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )
                 + SUM((IGR_TIME('GRDECS',IR,IS3,T),DEUSER),   IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDECS')  * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )
                 + SUM((IGR_TIME('GRDTOU1',IR,IS3,T),DEUSER),  IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDTOU1') * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )
                 + SUM((IGR_TIME('GRDTOU2',IR,IS3,T),DEUSER),  IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDTOU2') * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )
                 + SUM((IGR_TIME('GRDTOU3',IR,IS3,T),DEUSER),  IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDTOU3') * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )
                 + SUM((IGR_TIME('GRDTOU4',IR,IS3,T),DEUSER),  IHOURFRAC*IHOURSINST(IS3,T) * IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDTOU4') * VDENET_T(Y,IR,DEUSER,IS3,T)$(IDE_SUMST(IR,DEUSER) GT 0) )

                 + IOF1000 * SUM((IR,DEUSER,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDCW',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), VDEUSER_CAP1(Y,IR,DEUSER,MMM) *  IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDDCW'))/(IGR_MONTHSINSIM/CARD(MMM))    !! Demand charge winter
                 + IOF1000 * SUM((IR,DEUSER,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDCS',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), VDEUSER_CAP1(Y,IR,DEUSER,MMM) *  IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDDCS'))/(IGR_MONTHSINSIM/CARD(MMM))    !! Demand charge summer
                 + IOF1000 * SUM((IR,DEUSER,MMM)$(SUM((IS3,T)$IGR_TIME('GRDDC2',IR,IS3,T), ISSSTTTMMM(IS3,T,MMM))), VDEUSER_CAP1(Y,IR,DEUSER,MMM) *  IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDDC2'))/(IGR_MONTHSINSIM/CARD(MMM))    !! Demand charge 2
                 + IOF1000 * SUM((IR,DEUSER,MMM),   VDEUSER_CAP2(Y,IR,DEUSER,MMM) *  IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDDCTOU'))/(IGR_MONTHSINSIM/card(MMM))
                 + IOF1000 * SUM((IR,DEUSER),  VDEUSER_CAPY(Y,IR,DEUSER) *  IGR_PRICE_DEUSER(Y,IR,DEUSER,'GRDDCY'))


*Grid tariffs on hydrogen technologies: to be done