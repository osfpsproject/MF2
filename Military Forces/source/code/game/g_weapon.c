/*
 * $Id: g_weapon.c,v 1.4 2015-04-23 osfpsproject Exp $
*/

// Copyright (C) 1999-2000 Id Software, Inc.
//
// g_weapon.c 
// perform the server side effects of a weapon firing

#include "g_local.h"
#include "g_entity.h"

/*
================
G_BounceProjectile
================
*/
// might later be of use for MFQ3
void G_BounceProjectile( vec3_t start, vec3_t impact, vec3_t dir, vec3_t endout ) 
{
	vec3_t v, newv;
	float dot;

	VectorSubtract( impact, start, v );
	dot = DotProduct( v, dir );
	VectorMA( v, -2*dot, dir, newv );

	VectorNormalize(newv);
	VectorMA(impact, 8192, newv, endout);
}


/*
======================
SnapVectorTowards

Round a vector to integers for more efficient network
transmission, but make sure that it rounds towards a given point
rather than blindly truncating.  This prevents it from truncating 
into a wall.
======================
*/
void SnapVectorTowards( vec3_t v, vec3_t to ) 
{
	int		i;

	for ( i = 0 ; i < 3 ; i++ ) 
	{
		if ( to[i] <= v[i] ) 
			v[i] = (int)v[i];
		else 
			v[i] = (int)v[i] + 1;
	}
}

/*
===============
LogAccuracyHit
===============
*/
bool LogAccuracyHit( GameEntity* target, GameEntity* attacker )
{
	if( !target->takedamage_ ) 
		return false;

	if ( target == attacker ) 
		return false;

	if( !target->client_ ) 
		return false;

	if( !attacker->client_ ) 
		return false;

	if( target->client_->ps_.stats[STAT_HEALTH] <= 0 ) 
		return false;

	if ( OnSameTeam( target, attacker ) ) 
		return false;

	return true;
}


/*
===============
FireWeapon
===============
*/
void FireWeapon( GameEntity *ent ) 
{
	ent->client_->accuracy_shots_++;

	// fire the specific weapon
	switch( availableWeapons[ent->s.weaponIndex].type ) 
	{
	case WI_AAM_7KG:
	case WI_AAM_11KG:
	case WI_AAM_23KG:
	case WI_AAM_39KG:
	case WI_AAM_40KG:
	case WI_SAM_3KG:
		fire_antiair( ent );
		break;
	case WI_ASM_8KG:
	case WI_ASM_9KG:
	case WI_ASM_57KG:
	case WI_ASM_66KG:
		fire_antiground( ent );
		break;
	case WI_SSM_0_6KG:
	case WI_SSM_0_7KG:
	case WI_SSM_90KG:
		fire_ffar( ent );
		break;
	case WI_BMB_227KG:
	case WI_BMB_460KG:
	case WI_BMB_940KG:
	case WI_ICB_ANM50:
	case WI_GBMB_GBU15:
	case WI_GBMB_GBU31:
	case WI_GBMB_BLU107:
		fire_ironbomb( ent );
		break;
	case WI_R_1X7_62MM:
	fire rifle( ent );
		break;
	case WI_AR_1X5_45MM:
	case WI_AR_1X5_56MM:
	case WI_SMG_1X5_7MM:
	case WI_MG_1X7_62MM:
	case WI_MG_1X12_7MM:
	case WI_MG_1X14_5MM:
	case WI_MG_2X7_62MM:
	case WI_MG_2X7_92MM:
	case WI_MG_1X13MM:
	case WI_MG_2X13MM:
	case WI_MG_4X12_7MM:
	case WI_MG_8X7_62MM:
	fire_machinegun( ent );
		break;
	case WI_ACN_1X20MM
	WI_ACN_1X25MM
	WI_ACN_1X27MM
	WI_ACN_1X30MM
	WI_ACN_2X20MM
	WI_ACN_2X23MM
		fire_autocannon(ent, true);
		if( availableVehicles[ent->client_->vehicle_].caps & HC_DUALGUNS ) 
			fire_autocannon(ent, true);
		break;
	case WI_CNN_1X50MM:
	case WI_CNN_1X75MM:
	case WI_CNN_1X100MM:
	case WI_CNN_1X120MM:
	case WI_HOW_1X203MM:
		fire_maingun( ent );
		break;
	case WI_DROPTANK_SMALL:
	case WI_DROPTANK_PAIR:
		drop_fueltank( ent );
		if( availableWeapons[ent->s.weaponIndex].flags & WF_FIRE_IN_PAIRS )
			drop_fueltank( ent );
		break;
	case WI_HEALTHCRATE:
	case WI_AMMOCRATE:
	case WI_VEHICLE_REPAIRCRATE:
	case WI_VEHICLE_AMMOCRATE:
		drop_crate( ent );
		break;
	case WI_ACN_4X23MM:
		// No client flak firing yet
		break;
	case WI_NB_B82:
		fire_nukebomb ( ent );
		break;
	default:
// FIXME		G_Error( "Bad ent->s.weapon" );
		break;
	}
}

/*
===============
FireWeapon_GI
===============
*/
void FireWeapon_GI( GameEntity *ent ) 
{
	if(ent->s.eType != ET_MISC_VEHICLE)
		ent->client_->accuracy_shots_++;

	// fire the specific weapon
	switch( availableWeapons[ent->s.weaponIndex].type )
	{
	case WI_AAM_7KG:
	case WI_AAM_11KG:
	case WI_AAM_23KG:
	case WI_AAM_39KG:
	case WI_AAM_40KG:
	case WI_SAM_3KG:
		LaunchMissile_GI( ent );
		break;
	case WI_ACN_4X23MM:
		fire_flak_GI ( ent );
		break;
	case WI_ASM_8KG:
	case WI_ASM_9KG:
	case WI_ASM_57KG:
	case WI_ASM_66KG:
	case WI_SSM_0_6KG:
	case WI_SSM_0_7KG:
	case WI_SSM_90KG:
	case WI_SSM_0_6KG:
	case WI_SSM_0_7KG:
	case WI_SSM_90KG:
	case WI_BMB_227KG:
	case WI_BMB_460KG:
	case WI_BMB_940KG:
	case WI_ICB_ANM50:
	case WI_GBMB_GBU15:
	case WI_GBMB_GBU31:
	case WI_GBMB_BLU107:
	case WI_CNN_1X50MM:
	case WI_CNN_1X75MM:
	case WI_CNN_1X100MM:
	case WI_CNN_1X120MM:
	case WI_HOW_1X203MM:
	case WI_DROPTANK_SMALL:
	case WI_DROPTANK_PAIR:
	case WI_NB_B82:
		break;
	case WI_ACN_1X20MM:
	case WI_ACN_1X25MM:
	case WI_ACN_1X27MM:
	case WI_ACN_1X30MM:
	case WI_ACN_2X20MM:
	case WI_ACN_2X23MM:
	case WI_ACN_4X23MM:
		fire_autocannon_GI(ent);
		break;
	case WI_R_1X7_62MM:
		fire rifle( ent );
		break;
	case WI_AR_1X5_45MM:
	case WI_AR_1X5_56MM:
	case WI_SMG_1X5_7MM:
	case WI_MG_1X7_62MM:
	case WI_MG_1X12_7MM:
	case WI_MG_1X14_5MM:
	case WI_MG_2X7_62MM:
	case WI_MG_2X7_92MM:
	case WI_MG_1X13MM:
	case WI_MG_2X13MM:
	case WI_MG_4X12_7MM:
	case WI_MG_8X7_62MM:
		fire_machinegun( ent );
	default:
// FIXME		G_Error( "Bad ent->s.weapon" );
		break;
	}
}
