//--------------------------------------------------------------------------------------------------
//
//	UnitConversion: A compile-time c++14 unit conversion library with no dependencies
//
//--------------------------------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------------------------------------------
//
// Copyright (c) 2016 Nic Holthaus
//
//--------------------------------------------------------------------------------------------------
//
// ATTRIBUTION:
// Parts of this work have been adapted from:
// http://stackoverflow.com/questions/35069778/create-comparison-trait-for-template-classes-whose-parameters-are-in-a-different
// http://stackoverflow.com/questions/28253399/check-traits-for-all-variadic-template-arguments/28253503
// http://stackoverflow.com/questions/36321295/rational-approximation-of-square-root-of-stdratio-at-compile-time?noredirect=1#comment60266601_36321295
// https://github.com/swatanabe/cppnow17-units
//
//--------------------------------------------------------------------------------------------------
//
/// @file	units/time.h
/// @brief	units representing time values
//
//--------------------------------------------------------------------------------------------------

#pragma once

#ifndef units_time_h__
#define units_time_h__

#include <units/core.h>

/**
 * @def			UNIT_ADD_WITH_PLURAL_TAG(namespaceName, nameSingular, namePlural, abbreviation, definition)
 * @brief		Like `UNIT_ADD`, but the abbreviated unit is plural, e.g. `5_min` would have type `unit<mins>`
 * @sa			`UNIT_ADD`
 */
#define UNIT_ADD_WITH_PLURAL_TAG(namespaceName, nameSingular, namePlural, abbreviation, /*definition*/...) \
	UNIT_ADD_UNIT_TAGS(namespaceName, nameSingular, namePlural, abbreviation##s, __VA_ARGS__) \
	UNIT_ADD_UNIT_DEFINITION(namespaceName, nameSingular) \
	UNIT_ADD_NAME(namespaceName, nameSingular, abbreviation) \
	UNIT_ADD_IO(namespaceName, nameSingular, abbreviation) \
	UNIT_ADD_LITERALS(namespaceName, nameSingular, abbreviation)

namespace units
{
	/**
	 * @namespace	units::time
	 * @brief		namespace for unit types and containers representing time values
	 * @details		The SI unit for time is `seconds`, and the corresponding `dimension` dimension is
	 *				`time_unit`.
	 * @anchor		timeContainers
	 * @sa			See unit for more information on unit type containers.
	 */
	UNIT_ADD_WITH_METRIC_PREFIXES(time, second, seconds, s, conversion_factor<std::ratio<1>, units::dimension::time>)
	UNIT_ADD_WITH_PLURAL_TAG(time, minute, minutes, min, conversion_factor<std::ratio<60>, second<int>>)
	UNIT_ADD(time, hour, hours, hr, conversion_factor<std::ratio<60>, minute<int>>)
	UNIT_ADD(time, day, days, d, conversion_factor<std::ratio<24>, hour<int>>)
	UNIT_ADD(time, week, weeks, wk, conversion_factor<std::ratio<7>, day<int>>)
	UNIT_ADD(time, year, years, yr, conversion_factor<std::ratio<365>, day<int>>)
	UNIT_ADD(time, julian_year, julian_years, a_j, conversion_factor<std::ratio<31557600>, second<int>>)
	UNIT_ADD(time, gregorian_year, gregorian_years, a_g, conversion_factor<std::ratio<31556952>, second<int>>)

	UNIT_ADD_DIMENSION_TRAIT(time)
} // namespace units

#endif // units_time_h__
