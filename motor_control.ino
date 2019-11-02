const int ledPin = 22;

int data;

void setup () {
   Serial1.begin (115200);
   Serial.begin (115200);
   pinMode (ledPin, OUTPUT);
//   getData();
//   delay (15);
//   run_program();

}


void loop(){
   getData();
   delay (15);
   run_program();
}


int getData () {
  
  if (Serial.available ()) 
  {
     data = Serial.read ();
     if (data == '1') {
        digitalWrite (ledPin, HIGH);
     }
     
     else {
       digitalWrite (ledPin, LOW);
     } 

  return data;
  }
}


void run_program() {
  
  if (data == '1') {
   go_home();
   pickup_1();
   go_to_can1();
   go_to_can2();
   go_to_can3();
   go_to_can4();
   go_to_drop();
   go_home();
  }
}
  

void go_home()
{
    Serial1.print ("#1 P700 S4000");
   
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    
   Serial1.print ("#2 P2000 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    Serial1.print ("#3 P2300 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    
  
}

void pickup_1()
{
    Serial1.print ("#1 P700 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    
   Serial1.print ("#2 P600 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    Serial1.print ("#3 P1700 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    hook();
    
  
}

void hook(){
  
    Serial1.print ("#1 P800 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
      
   Serial1.print ("#2 P800 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    
}

void go_to_can1()
{
    // Reset position of Arm 2
      Serial1.print ("#2 P800 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      
      // Move to point 2
      Serial1.print ("#1 P1000 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      //Lower arm 2
      Serial1.print ("#2 P600 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      

      agitate(); 
}


void go_to_can2()
{
    // Reset position of Arm 2
      Serial1.print ("#2 P800 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      
      // Move to point 2
      Serial1.print ("#1 P1300 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      //Lower arm 2
      Serial1.print ("#2 P600 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      

      agitate();
}


void go_to_can3()
{// Reset position of Arm 2
      Serial1.print ("#2 P800 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      
      // Move to point 3
      Serial1.print ("#1 P1500 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      //Lower arm 2
      Serial1.print ("#2 P600 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      

      agitate(); 
}


void go_to_can4()
{// Reset position of Arm 2
      Serial1.print ("#2 P800 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      
      // Move to point 4
      Serial1.print ("#1 P1800 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      //Lower arm 2
      Serial1.print ("#2 P600 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      

      agitate(); 
}

void go_to_drop()
{// Reset position of Arm 2
      Serial1.print ("#2 P800 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      
      // Move to drop point 
      Serial1.print ("#1 P2200 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      //Lower arm 2
      Serial1.print ("#2 P600 S4000");
  
      delay (15);
    
      Serial1.print ("\r");
  
      delay (1500);
      unhook();
      

}



void unhook(){
  
    // Move to drop point
    Serial1.print ("#1 P2100 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
      
   // Drop (Unhook)
   Serial1.print ("#2 P800 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
   // Withdraw arm
    Serial1.print ("#1 P2100 S4000");
  
    delay (15);
    
    Serial1.print ("\r");
  
    delay (1500);
    
    
}


void agitate()
{  int x;
    for (x=0; x<3; x ++){
      Serial1.print ("#3 P1200 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
      
      Serial1.print ("#3 P2000 S4000");
    
      delay (15);
      
      Serial1.print ("\r");
    
      delay (1500);
    }
}






