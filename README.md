# Arduino-Time-Based-Relay-On-Off
The code checks current time and tells if the time is in between the start time and end time (Eg: 1:00PM to 3:30PM)

If you want to create a Relay that turns on at a specific period, but your power cuts, then you have to use this code which provides timing check even after resuming power.

The code converts current time into minutes or seconds from start of the day (0:00 AM)
and compares the minutes or seconds to the given start time and end time.

If the time maches inside of start and end time, then it returns true.

### NEW Night To Day Time Supported

Note: Using Timelib default hour() minute()

## The Function :



## Minutes scale comparison
```
> bool isintime(int shh, int smm, int ehh, int emm) 
//Match Minutes Resolution : isintime (Start Hour, Start Minute, End Hour, End Minute)
```

## Example:
```

bool relayon = isintime(12,1,16,30);       // (12:01 to 16:30)

```

or

```
bool relayon = isintime(23,30,5,30);  // (23:30 to 5:30)
```


Cheers.
