#pragma once
#include "cls_date.h"

using namespace std;

class cls_period
{
public:
	cls_date start, end;

	static bool is_two_periods_overlap(cls_period period1, cls_period period2)
	{
		return !(cls_date::is_date1_before_date2(period1.end, period2.start) || cls_date::is_date1_before_date2(period2.end, period1.start));
	}

	bool is_two_periods_overlap(cls_period period2)
	{
		return is_two_periods_overlap(*this, period2);
	}

	static short get_period_length(cls_period period, bool include_end_day = false)
	{
		return cls_date::get_diff_in_days_between_two_dates(period.start, period.end, include_end_day);
	}

	short get_period_length(bool include_end_day = false)
	{
		return get_period_length(*this, include_end_day);
	}

	static bool is_date_within_period(cls_date date, cls_period period)
	{
		return !(cls_date::is_date1_after_date2(period.start, date) || cls_date::is_date1_before_date2(period.end, date));
	}

	bool is_date_within_period(cls_date date)
	{
		return is_date_within_period(date, *this);
	}
};