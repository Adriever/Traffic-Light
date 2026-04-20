#define rightButton 3 
#define leftButton 13
#define rightRed 2
#define rightYellow 1 
#define rightGreen 0
#define leftRed 12
#define leftYellow 11
#define leftGreen 10
#define yellowBlinkTime 200
#define whiteLed 6
#define whiteButton 7
 
boolean trafficRight = true;
int flowTime = 5000;       // amount of time to let traffic flow
int changeDelay = 2000;     // amount of time between color changes
 
void setup()
{
   pinMode(rightButton, INPUT);
   pinMode(leftButton, INPUT);
   pinMode(rightRed, OUTPUT);
   pinMode(rightYellow, OUTPUT);
   pinMode(rightGreen, OUTPUT);
   pinMode(leftRed, OUTPUT);
   pinMode(leftYellow, OUTPUT);
   pinMode(leftGreen, OUTPUT);
   digitalWrite(rightRed, LOW);
   digitalWrite(rightYellow, LOW);
   digitalWrite(rightGreen, HIGH); 
   digitalWrite(leftRed, HIGH);
   digitalWrite(leftYellow, LOW);
   digitalWrite(leftGreen, LOW);
}
 
void loop()
{
   if ( digitalRead(rightButton) == HIGH )
   {
      if ( trafficRight != true ) 
      {
         trafficRight = true;
         delay(flowTime);    // give time for traffic to flow 
         digitalWrite(leftGreen, LOW);// to yellow to red
         digitalWrite(leftYellow, HIGH);
         delay(changeDelay);
         digitalWrite(leftYellow, LOW);
         digitalWrite(leftRed, HIGH);
         delay(changeDelay); 
         for ( int a = 0; a < 5; a++ ) // blink yellow light
         {
             digitalWrite(rightYellow, LOW);
             delay(yellowBlinkTime);
             digitalWrite(rightYellow, HIGH);
             delay(yellowBlinkTime);
        }
       digitalWrite(rightYellow, LOW);
       digitalWrite(rightRed, LOW); // to green
       digitalWrite(rightGreen, HIGH); 
       }
   }
   if ( digitalRead(leftButton) == HIGH )
   {
   if ( trafficRight == true ) 
   {
      trafficRight = false;
      delay(flowTime);     // give time for traffic to flow 
      digitalWrite(rightGreen, LOW); 
      digitalWrite(rightYellow, HIGH);
      delay(changeDelay);
      digitalWrite(rightYellow, LOW);
      digitalWrite(rightRed, HIGH);
      delay(changeDelay); 
      for ( int a = 0 ; a < 5 ; a++ ) // blink yellow light 
      {
         digitalWrite(leftYellow, LOW);
         delay(yellowBlinkTime);
         digitalWrite(leftYellow, HIGH);
         delay(yellowBlinkTime);
      } 
      digitalWrite(leftYellow, LOW); 
      digitalWrite(leftRed, LOW);
      digitalWrite(leftGreen, HIGH); 
      }
   }
   if ( digitalRead(whiteButton) == HIGH)
   {
      if ( trafficRight == true ) 
   {
      trafficRight = false;
      delay(flowTime);     // give time for traffic to flow 
      digitalWrite(rightGreen, LOW); 
      digitalWrite(rightYellow, HIGH);
      delay(changeDelay);
      digitalWrite(rightYellow, LOW);
      digitalWrite(rightRed, HIGH);
      delay (500);
      digitalWrite(whiteLed, HIGH);
      delay(8000);
      digitalWrite(whiteLed, LOW);
      delay (500);
      delay(changeDelay); 
      for ( int a = 0 ; a < 5 ; a++ ) // blink yellow light 
      {
         digitalWrite(leftYellow, LOW);
         delay(yellowBlinkTime);
         digitalWrite(leftYellow, HIGH);
         delay(yellowBlinkTime);
      } 
      digitalWrite(leftYellow, LOW); 
      digitalWrite(leftRed, LOW);
      digitalWrite(leftGreen, HIGH); 
      }
      else
      {
      trafficRight = true;
         delay(flowTime);    // give time for traffic to flow 
         digitalWrite(leftGreen, LOW);// to yellow to red
         digitalWrite(leftYellow, HIGH);
         delay(changeDelay);
         digitalWrite(leftYellow, LOW);
         digitalWrite(leftRed, HIGH);
         delay (500);
         digitalWrite(whiteLed, HIGH);
         delay(8000);
         digitalWrite(whiteLed, LOW);
         delay (500);
         delay(changeDelay); 
         for ( int a = 0; a < 5; a++ ) // blink yellow light
         {
             digitalWrite(rightYellow, LOW);
             delay(yellowBlinkTime);
             digitalWrite(rightYellow, HIGH);
             delay(yellowBlinkTime);
        }
       digitalWrite(rightYellow, LOW);
       digitalWrite(rightRed, LOW); // to green
       digitalWrite(rightGreen, HIGH); 
   }
   }
}