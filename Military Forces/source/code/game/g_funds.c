/*
 * $Id: g_funds.c,v 1.0 2016-04-22 11:21:38 osfpsproject Exp $
*/

#include "g_local.h"

// Declaring prices of:

// Coalition vehicles

// Multipurpose aircraft:
F-16 Falcon: 		$  78 000 000 
Saab JAS 39 Gripen: $  70 000 000
Harrier GR-7: 		$  25 000 000
F-14 Tomcat:		$  38 000 000
F-18 Hornet:		$  29 000 000
F-22 Raptor:		$ 150 000 000

// Strategic bombers 
B-2 Spirit:		$ 737 000 000

// Recon vehicles:
BRDM-2:			$   1 200 000

// Armoured personnel carriers:
Up-armoured HMMWV:	$     150 000

// Tanks:
M1A1i Abrams:		$  13 000 000

// Artillery:
M110 howitzer: 		$   6 500 000

// Anti-aircraft
AN/TWQ-1 (HMMWV-AA)	$     950 000
 
// Attack helicopters:
UH-1:			$   4 700 000 

// Aircraft (ROV, fighter aircraft):
spitfire Mk5b		$     200 000

// Aircraft (ROV, ground-attack aircraft):
p51d			$     700 000

// Aircraft (ROV, kamikaze aircraft):
none

// Recon ships
PBR31			$   1 500 000

// Rebel vehicles

// Multipurpose aircraft:
F-105 TEST:		$   2 100 000
F-5 Tiger:		$   2 100 000
F-15E Eagle:	$  30 000 000
SU-27 TEST		$  30 000 000
YF-23:			$ 150 000 000
A-10 Thunderbolt II:	$  19 000 000

// Strategic bombers
B17G: 			$   3 200 000

// Recon vehicles:
FAV:			$     150 000

// Armoured personnel carriers:
BMP-3			$   3 200 000 

// Tanks:
Panzer III:		$   1 200 000
M4 Sherman:		$     600 000

// Artillery:
M270 MLRS:  		$   4 700 000

// Anti-aircraft
ZSU-23:			$   2 500 000

// Attack helicopters:
Mi-24 (hind)		$  16 000 000

// Aircraft (ROV, fighter aircraft):
bf109g			$     200 000

// Aircraft (ROV, ground-attack aircraft):
fw190a8			$     700 000

// Aircraft (ROV, kamikaze aircraft):
Sopwith camel:		$      50 000
Fokker Dr.1:		$      50 000

// Recon ships
Skiff			$       5 000

//References:
//Most indicative prices were gathered from http://nation-creation.wikia.com/wiki/Modern_Day_Military_Pricing_List
//and from prices listed at wikipedia; whenever I did not found exact data, I took an indicative price from a comparitive vehicle 
//For the WW2 vehicles, some extra calculations were done:
//P-51d Mustang: $50,985 in 1945 makes $677 484 today (www.dollartimes.com/inflation/inflation.php?&year=1945)
//Spitfire Mk 5b $12 604 in 1945 makes $167 480 today
//Bf-109g: 42900 reichsmark in 1945 makes $180 180 (conversion rate= 4,2 in 1945) makes $ 2 394 217 today; figure not used in game for game balance issues
//fw190a8: 56 600 reichsmark in 1945 makes $237 720 (conversion rate= 4,2 in 1945) makes $ 3 158 804 today; figure not used in game for game balance issues
//B17g: $ 238 329 in 1945, makes $ 3 166 897 today
//Fokker Dr.1 & Sopwith Camel: $ 13 495 is about the cost for a reproduction today (see Airdrome Aeroplanes)
//M4 Sherman: $44,556 in 1945 makes $597 956 today (see http://ww2-weapons.com/m4-sherman/)
//Panzer III: around 70 000 reichsmark in 1945 probably (82,500 RM for StuG), so about $3 906 648 today; note that I listed it for less than half that, for gameplay reasons
