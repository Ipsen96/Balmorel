* UC Translated to BB4 by Juan Gea Berm�dez 2018.

PARAMETER UC_TECH_TYPE_VALUE(UC_TECH_TYPE) 'UC technology types';
PARAMETER UC_TECH_GROUP_VALUE(UC_TECH_GROUP)  'UC technology groups';
PARAMETER UC_FUELS_VALUE(UC_FUELS) 'UC fuels';

$ifi not %STEPWISE_RAMPING_UC%==ramp_const_cost $goto STEPWISERAMPING_END

PARAMETER RAMPING_COSTS_UP(UC_TECH_TYPE,UC_TECH_GROUP,UC_FUELS,RAMPING_RATE) 'Ramping up costs for each technology group, tech gype, fuel and ramping rate (Money/MWh)';
PARAMETER RAMPING_COSTS_DOWN(UC_TECH_TYPE,UC_TECH_GROUP,UC_FUELS,RAMPING_RATE) 'Ramping down costs for each technology group, tech gype, fuel and ramping rate (Money/MWh)';
PARAMETER RAMPING_CAPABILITY_UP(UC_TECH_TYPE,UC_TECH_GROUP,UC_FUELS,RAMPING_RATE) 'Ramping up capability for each technology group, tech gype, fuel and ramping rate (% capacity)';
PARAMETER RAMPING_CAPABILITY_DOWN(UC_TECH_TYPE,UC_TECH_GROUP,UC_FUELS,RAMPING_RATE) 'Ramping down capability for each technology group, tech gype, fuel and ramping rate (% capacity)';
$label  STEPWISERAMPING_END

*Unit Commitemnt data
PARAMETER UCON(YYY,AAA,GGG,SSS,TTT)     "Unit commitment (0,1) on electricity generation to be used in future runs";
PARAMETER UCON_STOLOAD(YYY,AAA,GGG,SSS,TTT)     "Unit commitment (0,1) on storage loading to be used in future runs";
PARAMETER UCONMAINT(YYY,AAA,GGG,SSS)    "Unit commitment maintenance (0,1) on electricity generation to be used in future runs";
