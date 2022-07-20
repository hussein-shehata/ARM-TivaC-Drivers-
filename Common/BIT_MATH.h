/********************************/
/* Author	: Abdelrhman Samir	*/
/* Version	: 1					*/
/* Date		: 15 AUG 2020		*/
/********************************/

#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(REG , BITNUM) REG |= 1<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1 )



#endif /* MACROS_H_ */
