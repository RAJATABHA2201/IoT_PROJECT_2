
#define S0 4//using 4,5,6,7,8 for the RGB colour sensor
#define S1 5
#define S2 6
#define S3 7
#define output_diode 8
#define redpin 9//using pwm pins over in 9,10 and 11 as it will be used for RGB led output
#define bluepin 10
#define greenpin 11
int red_frequency=0;
int blue_frequency=0;
int green_frequency=0;
void setup() {
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(output_diode,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(S0,HIGH);//frequency scaling upto 20%
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(S2,LOW);//red filtered photo diodes to be read
  digitalWrite(S3,LOW);
  red_frequency=pulseIn(output_diode,LOW);//frequency reading from diode
  delay(100);
  
  digitalWrite(S2,HIGH);//green filtered photo diodes to be read
  digitalWrite(S3,HIGH);
  green_frequency=pulseIn(output_diode,LOW);//frequency reading from diode
  delay(100);
   
  digitalWrite(S2,LOW);//blue filtered photo diodes to be read
  digitalWrite(S3,HIGH);
  blue_frequency=pulseIn(output_diode,LOW);//frequency reading from diode
  delay(100);

  if(green_frequency>25&&green_frequency<50)//we are considering only the colour of the plant as green and shades of green as maturity of it.It can be set accordingly on the basis of plant type
  {
      digitalWrite(bluepin,HIGH);//for newly born plants making the blue colour of rgb led on
  }
   if (green_frequency>40&&green_frequency<55)//we are considering only the colour of the plant as green and shades of green as maturity of it.
  {
      digitalWrite(redpin,HIGH);//for matured plants making the red colour of rgb led on
  }
  if (green_frequency>55)//for least green coloured plants
  {
      digitalWrite(greenpin,HIGH);//for least plants making the green colour of rgb led on
  }
}
