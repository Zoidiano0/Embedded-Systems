import processing.serial.*;
  
 String inBuffer="0,0"; 
Serial myPort;
int lf = 10;    // Linefeed in ASCII

float Analog0 ;
float Analog1 ;



int windowWidth = 400;
int windowHeight = 300;
float maxTemp = 500; //Maximum temperature expect to read
float[] readings = new float[windowWidth]; // initialized to zeroes













void setup(){
 size(1200,800);
 background(123);
  myPort = new Serial(this, "/dev/ttyACM0",9600);
   stroke(255,0,0);  // stroke will be red on dots plotted
  
  myPort.bufferUntil(lf); 
}

void draw(){
  background(255);
  fill(10,20,150);
  rect(0,0,120,300);
fill(150,20,50);
  rect(0,300,120,-map(Analog0,0,1024,0,300));

  
  readings[windowWidth - 1] = map(Analog1,0,1023,0,800); // Put a random number in the last value of the array
  
  // Map the element so it fits in our graph
  readings[windowWidth - 1] = map(readings[windowWidth - 1], 0, maxTemp, 0, height);
  
  // Plot all the points
  for (int i = 0; i < windowWidth - 1; i++)
  {
    if (readings[i] != 0) // Don't plot anything at zero, as that's the default value in the array
    {
      ellipse(i, height - readings[i], 3, 3);
    }
    readings[i] = readings[i + 1]; // Shift the readings to the left so can put the newest reading in
  }  
  
  
}

void serialEvent(Serial p) { 
  inBuffer = p.readString(); 
  println(inBuffer);
   println("Impresion cambios ");
   String[] datos = (splitTokens(inBuffer, " "));
      println("Strings");
      println(float(datos[0]));
      println(float(datos[1]));
      println("Int");
      Analog0 =float(datos[0]);
      Analog1 =float(datos[1]);
    
    
    
    
} 
