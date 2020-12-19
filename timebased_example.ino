//Time based actions for Esp / arduino based boards
//Run Relays On desired time.
//Sync time maching at any time
//Make your home appliance run for interval of time, Even if power cuts, it will re-sync and do the job.

//NEW: Now supports reverse time inputs (Like 9:10 PM To 05:00 AM )
//EG: ret=isintime(hour(),minute(),21,10,5,0);


//Just for some boards like esp8266 
#include <TimeLib.h> //Not Required

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

ret=isintime(hour(),minute(),12,1,16,30);


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




//This Now Supports Night to Day Relay Operations Also (EG: 9:00 PM To 05:00 AM Relay Operation)
//Match with Minutes Level
bool isintime(int now_hour, int now_minute, int start_hour, int start_minute, int end_hour, int end_minute) {
  unsigned long now_minutes = 0;
  unsigned long start_minutes = 0;
  unsigned long end_minutes = 0;
  unsigned long end_hour1 = 0;
  unsigned long end_minute1 = 0;
  bool intime1 = false;




  now_minutes = (((now_hour * 60) + (now_minute )));

  //Added Next Day Scadule if End Hour < Start Hour


  if (start_hour > end_hour) {
      
   // Now to 23:59 check
    
    start_minutes = ((start_hour * 60) + (start_minute ));
    
    end_minutes = ((23 * 60) + (60));
    
    
    if (now_minutes >= start_minutes && now_minutes <= end_minutes) {
      //on period
      intime1=true;
    } else {
      //off period
      intime1=false;
    }
    
    
    
    if(!intime1){
    // 0:0 to now check
    start_minutes = 0;
    end_minutes = ((end_hour * 60) + (end_minute));
    
    if (now_minutes >= start_minutes && now_minutes <= end_minutes) {
      //on period
         return (true);
    } else {
      //off period
     return (false);
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


