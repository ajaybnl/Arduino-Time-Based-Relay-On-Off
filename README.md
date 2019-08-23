# Arduino-Time-Based-Relay-On-Off
The code checks current time and tells if the time is in the ON period (Eg: 1:00PM to 3:30PM)

If you want to create a Relay that turns on at a specific period, but your power cuts, then you have to use this code which provides timing check even after power cut.

The code converts current time into minutes or seconds from start of the day (0:00 AM)
and compares the minutes or seconds to the given start time and end time.

If the time maches inside of start and end time, then it returns true.

<b>The Function :</b>




//Seconds scale comparison
bool isintime(int shh, int smm,int sss, int ehh, int emm, int ess) 
//Match Seconds Resolution : isintime (Start Hour, Start Minute, Start Second, End Hour, End Minute, End Second)




//Minutes scale comparison
bool isintime(int shh, int smm, int ehh, int emm) 
//Match Minutes Resolution : isintime (Start Hour, Start Minute, End Hour, End Minute)


Example:

ret=isintime(12,1,16,30);       // (12:01 to 16:30)
or
ret=isintime(12,1,50,16,30,0);  // (12:01:50 to 16:30:00)


Cheers.

Have a look on my other Arduino Sketches : http://github.com/ajaybnl
