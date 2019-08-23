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
setTime(12, 00, 40, 14, 12, 2019);

}


void loop(){
  
bool ret=false;

//Match Minutes Resolution : isintime (Start Hour, Start Minute, End Hour, End Minute)

//Match Seconds Resolution : isintime (Start Hour, Start Minute, Start Second, End Hour, End Minute, End Second)

ret=isintime(12,1,16,30);

//ret=isintime(12,1,50,16,30,0);

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
bool isintime(int shh, int smm,int sss, int ehh, int emm, int ess) {
  unsigned long n=0;
  unsigned long s=0;
  unsigned long e=0;
  
  //Convert Current Time to Secs From Today (Midnight)
  
  n = ((hour() * 3600) + (minute() * 60) + second() );
  
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

bool isintime(int shh, int smm, int ehh, int emm) {
  long n=0;
  long s=0;
  long e=0;  
  
  //Convert Current Time to Minutes From Today (Midnight)
  
  n = ((hour() * 60) + (minute() ));
  
  //Start Secs
  s = ((shh * 60) + (smm ));
  
  //End Secs
  e = ((ehh * 60) + (emm ));

  //If (now) secs are inside start and end secs
  if (n >= s && n <= e) {
    //on period
    return (true);
  } else {
    //off period
    return (false);
  }
}
