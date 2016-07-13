#include "Arduino.h"

String inBytes;
String RPM;



void setup()
{
  Serial.begin(9600);
  while(!Serial)
  {
    ;
  }
  Serial.write("VECALIVE\n");
}

void loop()
{
  if(Serial.available() > 0)
  {
    inBytes = Serial.readString();

    if(inBytes.startsWith("VECHELLO"))
    {
      Serial.write("VECACK\n");
    }

    if(inBytes.startsWith("VECRPM"))
    {
      RPM = inBytes.substring(6);
      String lResponse = "VEC Set RPM to ";
      lResponse += RPM;
      lResponse += " %\n";
      Serial.println(lResponse);
    }

    if(inBytes.startsWith("VECCHKRPM"))
    {
      String lResponse = "VEC Current RPM: ";
      lResponse += RPM;
      lResponse += " %\n";
      Serial.println(lResponse);
    }

    Serial.println("VEC waiting...");
  }

}

bool SetRPM(int pRpm)
{
	return false;
}
