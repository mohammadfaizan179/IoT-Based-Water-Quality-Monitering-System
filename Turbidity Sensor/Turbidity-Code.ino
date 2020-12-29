int sensorPin = A0;
float volt;
float ntu;
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
    
    volt = 0;
    for(int i=0; i<800; i++)                              // Loop to take 800 readings
    {
        volt += ((float)analogRead(sensorPin)/1023)*5;    // Read the input on analog pin 0 & Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    }
    volt = volt/800;                                      // Taking the Average of 800 Readings
    volt = round_to_dp(volt,1);                           // Calling the "round_to_dp" method to round off the volt reading
    if(volt < 2.5){                                       // If volt is less than 2.5 then run the block  
      ntu = 3000;                                         // Set the Turbidity value to 3000       
    }else{                                                
      ntu = -1120.4*square(volt)+5742.3*volt-4353.8;      // If the volt is above 2.5 then calculate the NTU value by using the equation give in the graph 
    }
    Serial.println("Voltage="+String(volt)+" V --------> Turbidity="+String(ntu)+" NTU");  // Printing results on serial moniter
    delay(1000);                                                                           // Delay of 1 sec      
}
 
float round_to_dp( float in_value, int decimal_place )    // Method to round of the volt value
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}
//##################################################################################################
/*
void setup() {
  Serial.begin(9600); //Baud rate: 9600
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float volt = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //Serial.println(volt); // print out the value you read:
  delay(2000);
  
  float ntu = -1120.4*(volt*volt)+5742.3*volt-4353.9;

  //if((volt>=2.5)&(ntu>=0))
  //{
    Serial.println("Voltage="+String(volt)+" V --------> Turbidity="+String(ntu)+" NTU");  
    delay(500);
  //}
 
}
*/
