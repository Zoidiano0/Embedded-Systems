  int x=0;
  int y=0;
void setup(){

  
  size(1200,800);
  background(25,60,120);
}


void draw(){
  text(x,50,50);
  text(y,50,75);

  if(x>=635){
x=635;
  }else if(y>=330){
  y=330;
  
  }else if(x <=-80){
  x=-80;
  }else if(y<=-80){
  y=-80;
  }

  skull();
  bordes();
}

void keyPressed(){
  background(25,60,120);
//background(0);
//println(key);
//textSize(20);
//text(keyCode,100,50);
switch(keyCode){
 case 38:
 y-=5;
 break;
 case 40:
 y+=5;
 break;
 case 37:
 x-=5;
 break;
 case 39:
 x+=5;
 break;
  
}


}


void skull(){

  beginShape();
  fill(135,20,23);
  vertex(100+x,200+y);
  vertex(150+x,200+y);
  vertex(150+x,150+y);
  vertex(200+x,150+y);
  vertex(200+x,100+y);
  vertex(450+x,100+y);
  vertex(450+x,150+y);
  vertex(500+x,150+y);
  vertex(500+x,200+y);
  vertex(550+x,200+y);
  vertex(550+x,300+y);
  vertex(450+x,300+y);
  vertex(450+x,250+y);
  vertex(200+x,250+y);
  vertex(200+x,300+y);
  vertex(100+x,300+y);
  vertex(100+x,200+y);
  endShape();
  beginShape();
  fill(230,187,131);
  vertex(150+x,300+y);
  vertex(150+x,400+y);
  vertex(200+x,400+y);
  vertex(200+x,450+y);
  vertex(450+x,450+y);
  vertex(450+x,400+y);
  vertex(500+x,400+y);
  vertex(500+x,300+y);
  vertex(450+x,300+y);
  vertex(450+x,250+y);
  vertex(200+x,250+y);
  vertex(200+x,300+y);
  vertex(150+x,300+y);
  endShape();
  fill(0);
  rect(250+x,250+y,50,100);
  fill(0);
  rect(350+x,250+y,50,100);
  



}

void bordes(){
  fill(0);
  rect(0,0,20,800);
  fill(0);
  rect(1185,0,20,800);
  fill(0);
  rect(0,0,1200,20);
  fill(0);
  rect(0,780,1200,20);

}
