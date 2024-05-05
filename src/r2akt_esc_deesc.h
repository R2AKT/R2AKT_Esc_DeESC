 /******************************************************************************
 *
 *    FILE NAME : r2akt_esc_deesc.h
 *       AUTHOR : Sergey Dorozhkin (R2AKT)
 *         DATE : 05-may-2024
 *      VERSION : 0.0.1
 * MODIFICATION : 1
 *      PURPOSE : ESC-DeESC data (exclude 0xC0 from data range)
 *          URL : https://github.com/R2AKT/r2akt_esc-deesc
 *
 ******************************************************************************/

#ifndef R2AKT_ESC_DEESC_H
	#define R2AKT_ESC_DEESC_H

	#include <limits.h>
	#include <stdlib.h>
	#include <stdint.h>

 /****************************************************************************/
	#define _FEND 0xC0
	#define _FESC 0xDB
	#define _TFEND 0xDC  
	#define _TFESC 0xDD

 /****************************************************************************/

	#ifdef __cplusplus
		extern "C" {
	#endif 
 /****************************************************************************/
	size_t _ESCBuff (uint8_t *ESCBuff , const uint8_t *UnESCBuff, size_t size);
	size_t _DeESCBuff (uint8_t *DeESCBuff, const uint8_t *ESCBuff, size_t size);

	#ifdef __cplusplus
		}           /* closing brace for extern "C" */
	#endif

#endif /* R2AKT_ESC_DEESC_H */
 /************************************************************* END OF FILE ***/