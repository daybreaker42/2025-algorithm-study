import sys
from datetime import datetime, timedelta

# Days in each month (non-leap year)
month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def month_to_days(month):
    """Convert month to days"""
    days = 0
    for i in range(month - 1):
        days += month_days[i]
    return days

def time_to_minutes(ymd, time):
    """Convert 'YYYY-MM-DD HH:MM' to minutes"""
    month = int(ymd[5:7])
    day = int(ymd[8:10])
    hour = int(time[0:2])
    minute = int(time[3:5])
    
    return month_to_days(month) * 1440 + (day - 1) * 1440 + hour * 60 + minute

inp = sys.stdin.readline().split()
len_inp = int(inp[0])
duration_str = inp[1]
fine_per_minute = int(inp[2])

# Parse allowed duration
allowed_duration_minutes = 0
allowed_duration_minutes += int(duration_str[0:3]) * 1440  # Days
allowed_duration_minutes += int(duration_str[4:6]) * 60    # Hours
allowed_duration_minutes += int(duration_str[7:9])         # Minutes

rentals = {}  # {part: {name: rental_start_time}}
fine_reports = {}

for _ in range(len_inp):
    ymd, time, part, name = sys.stdin.readline().split()
    current_time = time_to_minutes(ymd, time)
    
    if part in rentals and name in rentals[part]:
        rental_start_time = rentals[part][name]
        rental_duration_minutes = current_time - rental_start_time
        
        if rental_duration_minutes > allowed_duration_minutes:
            if name not in fine_reports:
                fine_reports[name] = 0
            fine_reports[name] += (rental_duration_minutes - allowed_duration_minutes) * fine_per_minute
            
        del rentals[part][name]
        if not rentals[part]:
            del rentals[part]
    else:
        if part not in rentals:
            rentals[part] = {}
        rentals[part][name] = current_time

if not fine_reports:
    print(-1)
else:
    for user, fine in sorted(fine_reports.items()):
        print(f"{user} {fine}")
