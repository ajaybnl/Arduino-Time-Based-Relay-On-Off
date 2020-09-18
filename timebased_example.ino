//Time based actions for arduino based boards
//Made by ajaybnl 

//Create Relay which operates on desired time.
//Sync time maching at any time
//Make your home appliance run for interval of time. Even if power cuts, it will re-sync and do the job.





//Just for some boards like esp8266 
#include <TimeLib.h>

void setup(){

Serial.begin(9600);

//Read time from RTC / NTP in your code
// Add code later


//Set Dummy Time
//setTime(12, 00, 40, 14, 12, 2019);

}


void loop(){
  
bool ret=false;

//Match Minutes Resolution : isintime (hour(),minute(),Start Hour, Start Minute, End Hour, End Minute)

//Match Seconds Resolution : isintime (hour(),minute(),second(),Start Hour, Start Minute, Start Second, End Hour, End Minute, End Second)

ret=isintime(hour(),minute(),12,1,16,30);

//ret=isintime(hour(),minute(),second(),12,1,50,16,30,0);

Serial.print("Current Time: ");
Serial.print(hour());
Serial.print(":");
Serial.print(minute());
Serial.print(":");
Serial.println(second());
Serial.println();
Serial.println();

if(ret){
Serial.println("The time is Between 12:01 and 16:30");
}else{
Serial.println("The time is not Between 12:01 and 16:30 ");
}
Serial.println();
Serial.println();
delay(2000);


}

//Match with Seconds
bool isintime(int now_hour,int now_minutes,int now_seconds,int shh, int smm,int sss, int ehh, int emm, int ess) {
  unsigned long n=0;
  unsigned long s=0;
  unsigned long e=0;
  
  //Convert Current Time to Secs From Today (Midnight)
  
  n = ((now_hour * 3600) + (now_minutes * 60) + now_seconds );
  
  //Start Secs
  s = ((shh * 3600) + (smm * 60) + sss);
  
  //End Secs
  e = ((ehh * 3600) + (emm * 60) + ess);

  //If (now) secs are inside start and end secs
  if (n >= s && n <= e) {
    //on period
    return (true);
  } else {
    //off period
    return (false);
  }
}



//Match with Minutes only


bool isintime(int now_hour,int now_minute,int start_hour, int start_minute, int end_hour, int end_minute) {
  unsigned long now_minutes = 0;
  unsigned long start_minutes = 0;
  unsigned long end_minutes = 0;
  unsigned long end_hour1 = 0;
  unsigned long end_minute1 = 0;
  bool intime1 = false;

  now_minutes = (((now_hour * 60) + (now_minute)));

//Added Next Day Scadule if End Hour < Start Hour
  
  if(start_hour>end_hour) {        
    //if end hour is next day
    // from start_hour to 00:00
    start_minutes = ((start_hour * 60) + (start_minute ));
    end_minutes = ((24 * 60));
    if (now_minutes >= start_minutes && now_minutes <= end_minutes) {
      //on period
      intime1 = true;
    } else {
      //off period
      intime1 = false;
    }

    // from 00:00 to end_hour
    if (!intime1) {
      start_minutes = ((start_minute ));
      end_minutes = ((end_hour * 60));
      if (now_minutes >= start_minutes && now_minutes <= end_minutes) {
        //on period
        intime1 = true;
      } else {
        //off period
        intime1 = false;
      }
    }

    return (intime1);
    
  } else {
    //same day operation
    start_minutes = ((start_hour * 60) + (start_minute ));
    end_minutes = ((end_hour * 60) + (end_minute ));
    if (now_minutes >= start_minutes && now_minutes <= end_minutes) {
      //on period
      return (true);
    } else {
      //off period
      return (false);
    }
  }

}

