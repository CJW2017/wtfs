/*
 * macro_utils.h - define some useful macros.
 *
 * Copyright (C) 2015 Chaos Shen
 *
 * This file is part of wtfs, What the fxck filesystem.  You may take
 * the letter 'f' from, at your option, either 'fxck' or 'filesystem'.
 *
 * wtfs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * wtfs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wtfs.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef WTFS_MACRO_UTILS_H_
#define WTFS_MACRO_UTILS_H_

/* for strrchr() */
#ifdef __KERNEL__
# include <linux/string.h>
#else
# include <string.h>
#endif /* __KERNEL__ */

/* filename without path */
#define __FILENAME__\
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/* int types */
typedef __u8 wtfs8_t;
typedef __le16 wtfs16_t;
typedef __le32 wtfs32_t;
typedef __le64 wtfs64_t;

/* int type converters */
#ifdef __KERNEL__
# define wtfs16_to_cpu le16_to_cpu
# define wtfs32_to_cpu le32_to_cpu
# define wtfs64_to_cpu le64_to_cpu
# define cpu_to_wtfs16 cpu_to_le16
# define cpu_to_wtfs32 cpu_to_le32
# define cpu_to_wtfs64 cpu_to_le64
#else
# define wtfs16_to_cpu le16toh
# define wtfs32_to_cpu le32toh
# define wtfs64_to_cpu le64toh
# define cpu_to_wtfs16 htole16
# define cpu_to_wtfs32 htole32
# define cpu_to_wtfs64 htole64
#endif /* __KERNEL__ */

/* bitwise operations */
#define wtfs_set_bit(nr, addr)\
	set_bit((nr), (volatile unsigned long *)(addr))
#define wtfs_clear_bit(nr, addr)\
	clear_bit((nr), (volatile unsigned long *)(addr))
#define wtfs_test_bit(nr, addr)\
	test_bit((nr), (const volatile unsigned long *)(addr))
#define wtfs_find_first_zero_bit(addr, size)\
	find_first_zero_bit((const unsigned long *)(addr), (size))

/* int comparators */
#define wtfs_min(a, b) min((uint64_t)(a), (uint64_t)(b))
#define wtfs_max(a, b) max((uint64_t)(a), (uint64_t)(b))
#define wtfs_min3(a, b, c) min3((uint64_t)(a), (uint64_t)(b), (uint64_t)(c))
#define wtfs_max3(a, b, c) max3((uint64_t)(a), (uint64_t)(b), (uint64_t)(c))

#ifndef is_power_of_2
# define is_power_of_2(n) ((n) != 0 && ((n) & ((n) - 1)) == 0)
#endif /* is_power_of_2 */

#endif /* WTFS_MACRO_UTILS_H_ */
