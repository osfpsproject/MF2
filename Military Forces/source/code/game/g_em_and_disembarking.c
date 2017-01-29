/*
* $Id: g_em_and_disembarking.c,v 1.0 2016-04-22 osfpsproject Exp $
*/

#include "g_local.h"

// Make all vehicles embarkable and disembarkable (removing player's infantry model from terrain when standing next
// to the vehicle and pressing the embark button, and adding the player's infantry model to next to the vehicle when 
// pressing the disembark button and making the vehicle model or the player model controllable)

// Make only the following vehicles em- and disembarkable by multiple infantry players (first one to embark doing so as driver),
// the others doing so as a mere passenger:

// HMMWV (embarkable by 1 driver and 8 additional passengers)

// BMP-3 (embarkable by 1 driver and 6 additional passengers)

// UH-1 (embarkable by 1 pilot and 6 additional passengers)

// Hind (embarkable by 1 pilot and 7 additional passengers)

// PBR-31 (embarkable by 1 captain and 4 additional passengers)

// Skiff (embarkable by 1 captain and 4 additional passengers)
