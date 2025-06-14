/**
 * @file data.h
 * @brief [brief]
 *
 * [desc]
 *
 * @author Kristaps Ruments
 * @date June 16 2025
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h> // for uint*_t types


/**
 * @brief [brief]
 *
 * [desc]
 *
 * @param [param]
 * @param [param]
 *
 * @return [return].
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief [brief]
 *
 * [desc]
 *
 * @param [param]
 * @param [param]
 *
 * @return [return].
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
