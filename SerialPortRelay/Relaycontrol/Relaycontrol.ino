/*
 MD Harrington  serial communications to control relays , other devices etc 
 
 10/10/2023


*/

char inbyte ;

String checkvalue , portval ;



void switchPins(byte value)
{
 // toggle the last state 
 PORTD = PORTD ^ value;
}

String checkPortValue(int value)
{

  //  create a variable to hold pin status 
    unsigned int portValue ;
    
    portValue = (PIND & (value)) ;
    portval = String(portValue) ;
    return portval  ;


}

void setup() {

      DDRD = 0b00011100 ;  // sets pin d2 ,d3 ,d4 as outout
      
      //Initialize serial and wait for port to open:
     
      Serial.begin(9600);
     
      while (!Serial) {
        ;  // wait for serial port to connect. Needed for native USB port only
      }

  // prints title with ending line break
  Serial.println("Arduino Uno ready to receive data");
}

    void loop() {
    
    // check if we have any serialdata present incomming 
    //  If so then the length be greater than 0 
    if(Serial.available()> 0)
    {
      // read the entire  contents to  null terminating characgter
      inbyte = Serial.read() ;


            switch (inbyte)
            {
              case 'R':
              Serial.println("Red Led ,Relay Switch actioned") ;
              switchPins(0x04) ;
             
              checkvalue = checkPortValue(0x04) ;
             


              Serial.println("The value of register is " + checkvalue ) ;
              break ;

              case 'B':
              Serial.println("Blue Led actioned") ;
              switchPins(0x08) ;

              checkvalue = checkPortValue(0x08) ;
              Serial.println("The value of register is " + checkvalue ) ;
              break ;

              case 'G':
              Serial.println("Green Led actioned") ;
              switchPins(0x10) ; // set pin 
              checkvalue = checkPortValue(0x10) ;
              Serial.println("The value of register is " + checkvalue ) ;
              break ;

            }

    }
  
}
