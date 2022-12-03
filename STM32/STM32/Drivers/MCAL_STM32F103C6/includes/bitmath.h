#ifndef BITMATH_H
#define BITMATH_H

#define CLR_BIT(reg, bit) (reg &= ~(1 << bit))
#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define TOGl_BIT(reg, bit) (reg ^= (1 << bit))
#define GET_BIT(reg, bit) ((reg & (1 << bit)) >> bit)

#endif
