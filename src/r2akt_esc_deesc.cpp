 /******************************************************************************
 *
 *    FILE NAME : r2akt_esc-deesc.cpp
 *       AUTHOR : Sergey Dorozhkin (R2AKT)
 *         DATE : 05-may-2024
 *      VERSION : 0.0.1
 * MODIFICATION : 1
 *      PURPOSE : ESC-DeESC data (exclude 0xC0 from data range)
 *          URL : https://github.com/R2AKT/r2akt_esc-deesc
 *
 ******************************************************************************/
#include "r2akt_esc_deesc.h"

size_t ESCData (uint8_t *ESCBuff, const uint8_t *UnESCBuff, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (UnESCBuff[i] == _FEND) {
            ESCBuff[count++] = _FESC;
            ESCBuff[count++] = _TFEND;
        } else if (UnESCBuff[i] == _FESC) {
            ESCBuff[count++] = _FESC;
            ESCBuff[count++] = _TFESC;
        } else {
            ESCBuff[count++] = UnESCBuff[i];
        }
    }
    return count;
}
 /******************************************************************************/
size_t DeESCData (uint8_t *DeESCBuff, const uint8_t *ESCBuff, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if ((ESCBuff[i] == _FESC) && (ESCBuff[i+1] == _TFEND)) {
            DeESCBuff[count++] = _FEND;
            i++;
        } else if ((ESCBuff[i] == _FESC) && (ESCBuff[i+1] == _TFESC)) {
            DeESCBuff[count++] = _FESC;
            i++;
        } else {
            DeESCBuff[count++] = ESCBuff[i];
        }
    }
    return count;
}
/************************************************************** END OF FILE ***/
