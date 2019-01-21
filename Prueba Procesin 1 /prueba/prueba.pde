PShape dinos;
PShape dinoseyes;

PShape dinosr;
PShape dinoseyesr;

int posx=0;
int posy=0;
int j=0;
boolean d=false;
void setup(){
   size(1200,800);
   background(255);
     dinos = createShape();
   dinoseyes = createShape();
   dino();
}
void draw(){
   background(255);
  

 // shape(dinos,j,300);
 // shape(dinoseyes,j,300);
if(j>500){
  d=true;
  
  dinos.scale(-1,1);
     dinoseyes.scale(-1,1);
}else if(j<10){
    dinos.scale(1,1);
     dinoseyes.scale(1,1);
  d=false;
}


if(d==true){

   j--;
    

   
   shape(dinos,j+posx,300);
  
 shape(dinoseyes,j+posx,300);
  
  
}else if(d==false){
    j++;
     dinos.scale(1,1);
    shape(dinos,j+posx,300);
  shape(dinoseyes,j+posx,300);
 }
 



}
void dino(){
  // Dino Stand start
 
 dinos.beginShape();
dinos.fill(0, 0, 255);
  dinos.noStroke();
  dinos.vertex(70, 0);
  dinos.vertex(150, 0);
  dinos.vertex(150, 10);
  dinos.vertex(160,10);
  dinos.vertex(160,60);
dinos.vertex(100,60);
dinos.vertex(100,75);
dinos.vertex(130,75);
dinos.vertex(130,85);
dinos.vertex(90,85);
dinos.vertex(90,115);
dinos.vertex(120,115);
dinos.vertex(120,135);
dinos.vertex(110,135);
dinos.vertex(110,125);
dinos.vertex(90,125);
dinos.vertex(90,160);
dinos.vertex(80,160);
dinos.vertex(80,170);
dinos.vertex(70,170);
dinos.vertex(70,180);
dinos.vertex(60,180);
dinos.vertex(60,220);
dinos.vertex(90,220);
dinos.vertex(90,230);
dinos.vertex(50,230);
dinos.vertex(50,200);
dinos.vertex(40,200);
dinos.vertex(40,190);
dinos.vertex(30,190);
dinos.vertex(30,200);
dinos.vertex(20,200);
dinos.vertex(20,210);
dinos.vertex(10,210);
dinos.vertex(10,220);
dinos.vertex(30,220);
dinos.vertex(30,230);
dinos.vertex(0,230);
dinos.vertex(0,190);
dinos.vertex(-10,190);
dinos.vertex(-10,170);
dinos.vertex(-30,170);
dinos.vertex(-30,160);
dinos.vertex(-40,160);
dinos.vertex(-40,150);
dinos.vertex(-50,150);
dinos.vertex(-50,90);
dinos.vertex(-40,90);
dinos.vertex(-40,110);
dinos.vertex(-30,110);
dinos.vertex(-30,120);
dinos.vertex(-20,120);
dinos.vertex(0,120);
dinos.vertex(0,110);
dinos.vertex(20,110);
dinos.vertex(20,100);
dinos.vertex(30,100);
dinos.vertex(30,90);
dinos.vertex(30,10);
dinos.vertex(40,10);
dinos.vertex(40,0);
 dinos.endShape();
 
 // Dino Stand stop
 // dino eyes start 
dinoseyes.beginShape();
dinos.fill(1, 1, 1);
  dinos.noStroke();
dinoseyes.vertex(50,20);
  dinoseyes.vertex(60,20);
  dinoseyes.vertex(60,35);
  dinoseyes.vertex(50,35);
dinoseyes.endShape();
//dino eyes stop



}
  
  
  void keyPressed() {
  if(keyCode==39){
   posx+=10;
    
  }else if(keyCode==37){
    posx-=10;
    dinos.scale(-1,1);
     dinoseyes.scale(-1,1);
 }else if(keyCode==40){
    dinos.scale(-1,1);
     dinoseyes.scale(-1,1);
 }
 
 
}
  
  
