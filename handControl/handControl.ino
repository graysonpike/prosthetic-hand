#include <Servo.h>

Servo thumb;  
Servo index;
Servo middle;
Servo ring;
Servo pinkie;

int ans = 20;   
int thumb_up = 20;
int thumb_down = 110;
int index_down = 35;
int index_up = 170;
int middle_down = 40;
int middle_up = 170;
int ring_down = 165;
int ring_up = 20;
int pinkie_down = 20;
int pinkie_up = 170;

int pin_thumb = 9;
int pin_index = 10;
int pin_middle = 11;
int pin_ring = 5;
int pin_pinkie = 6;

bool is_thumb_up = true;
bool is_index_up = true;
bool is_middle_up = true;
bool is_ring_up = true;
bool is_pinkie_up = true;


void manual() {
if (Serial.available() > 0) {
   ans = Serial.parseInt();

   if(ans == 1) { is_thumb_up = !is_thumb_up; Serial.println("Toggle thumb"); }
   if(ans == 2) { is_index_up = !is_index_up;}
   if(ans == 3) {is_middle_up = !is_middle_up;}
   if(ans == 4) {is_ring_up = !is_ring_up;}
   if(ans == 5) {is_pinkie_up = !is_pinkie_up;}
  
  }

   if(is_thumb_up){
    thumb.write(thumb_up);
   } else {
    thumb.write(thumb_down);
   }

   if(is_index_up){
    index.write(index_up);
   } else {
    index.write(index_down);
   }

   if(is_middle_up){
    middle.write(middle_up);
   } else {
    middle.write(middle_down);
   }

   if(is_ring_up){
    ring.write(ring_up);
   } else {
    ring.write(ring_down);
   }

   if(is_pinkie_up){
    pinkie.write(pinkie_up);
   } else {
    pinkie.write(pinkie_down);
   }
}


void cascade() {
  thumb.write(thumb_down);
  delay(100);
  index.write(index_down);
  delay(100);
  middle.write(middle_down);
  delay(100);
  ring.write(ring_down);
  delay(100);
  pinkie.write(pinkie_down);
  delay(100);

  delay(1000);

  thumb.write(thumb_up);
  delay(100);
  index.write(index_up);
  delay(100);
  middle.write(middle_up);
  delay(100);
  ring.write(ring_up);
  delay(100);
  pinkie.write(pinkie_up);
  delay(100);

  delay(1000);
}

void hookem() {
  thumb.write(thumb_down);
  delay(15);
  middle.write(middle_down);
  ring.write(ring_down);
  delay(2000);
  middle.write(middle_up);
  ring.write(ring_up);
  thumb.write(thumb_up);
}

void smooth_cascade() {
  pinkie.write(pinkie_down);
  delay(150);
  ring.write(ring_down);
  delay(150);
  middle.write(middle_down);
  delay(150);
  index.write(index_down);
  thumb.write(thumb_down);
  pinkie.write(pinkie_up);
  delay(150);
  ring.write(ring_up);
  delay(150);
  middle.write(middle_up);
  delay(150);
  index.write(index_up);
  thumb.write(thumb_up);
}

void run_all() {
  cascade();
  delay(1000);
  hookem();
  delay(1000);
  smooth_cascade();
  delay(1000);
}
  
void setup() {
  thumb.attach(pin_thumb);
  index.attach(pin_index);
  middle.attach(pin_middle);
  ring.attach(pin_ring);
  pinkie.attach(pin_pinkie);
  
  Serial.begin(9600);
}

void loop() {
  //manual();
  run_all();
  delay(15000);
}

