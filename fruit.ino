#include <LiquidCrystal.h> 
#include "config.h"
float credit = 5;
float pot = 0;


int reel_1; // fruits 1-10 , current position of reels
int reel_2;
int reel_3; 

int reel1; // fruits 1-10 , desitined position of reels 
int reel2;
int reel3;

bool held_1 = false; // reels are "unheld" by default
bool held_2 = false;
bool held_3 = false;

bool hold_flag = false; //does the player have an opportunity to hold the reels?
bool a = true; // while looping

int fruitList[99] = {}; // stores 100 of the possible outcomes of a single reel
int x = 0; 
int m;
int k;
int id = 0;
 


int randn = analogRead(16);
int sensor_1 = analogRead(15);
int sensor_2 = analogRead(14);
int sensor_3 = analogRead(13);

LiquidCrystal lcd(24, 26, 28, 30, 32, 36);


void setup() {

  pinMode(2, INPUT); // reel 1 
  pinMode(3, INPUT); // reel 2
  pinMode(4, INPUT); // reel 3
  pinMode(5, INPUT); // start reel 
  pinMode(6, OUTPUT);  // LED 1
  pinMode(7, OUTPUT); // LED 2
  pinMode(8, OUTPUT); // LED3
  pinMode(9, OUTPUT); // LED start reel
  pinMode(10, OUTPUT); // motor A
  pinMode(11, OUTPUT); // motor B 
  pinMode(12, OUTPUT); // motor C

}

for (k = 0; fruit[k].title != NULL; k++) { //counts the number of fruits specified in the config header
  NumberOfFruits++;
};

while (id != NumberOfFruits) {     //build fruitlist array from stats sctructure found in config header
   for (m = 0; fruit[id].freq > m; m++) {
       fruitList[x] = id;
       x++;
    }

id++;

};

void loop() {


  display();


  if (hold_flag == true) {

    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
     while (a == true;) { // there's probably a better way to write while loops

  if (digitalRead(2)== HIGH) { //"hold" the selected reel
    toggle("heeld_1", true); 
  } else{
    toggle("heeld_1", false); 
  }
  
  if (digitalRead(3)== HIGH) {
    toggle("heeld_2", true); 
  }else{
    toggle("heeld_2", false); 
  } 
  
  if (digitalRead(4)== HIGH) {
   toggle("heeld_3", true);  
  }else{
    toggle("heeld_3", false); 
  }
  
 if (digitalRead(5)== HIGH) {
  spin();
  }
      
     };
    
  } else {

    if (digitalRead(5)== HIGH) {
  spin();
    
  };

};



void toggle(String reel, boolean flag) {
  int led;

  
  if (reel == "heeld_1") {   //toggle the power of the LED inside the button that is pressed
    led = 6; 
  } else if (reel == "heeld_2") {
    led = 7; 
  } else if (reel == "heeld_3") {
    led = 8; 
  } 
    
  if (flag == false) {
    flag = true;
    digitalWrite(led,LOW);
  } else {
    flag == false;  
    digitalWrite(led,HIGH);
  }

}


void win(int amount){
  
  lcd.print("Three ");
  lcd.print(fruit[reel_1].title); //get name of the fruit that has appeared on all three reels and print it
  lcd.print("'s!!!");
  lcd.print(" You've won £");
  lcd.print(amount);
  lcd.print(" !");
  
  delay(3000);

  pot = pot + amount;

  display();
  
}


void display() {
  
  lcd.print("Credit: £");
  lcd.print(credit);
  lcd.print(" Pot: ");
  lcd.print(pot);
  lcd.print(" ");
}


void step(int PluggedReel){ //increments reel value, 10 max

  PluggedReel++; //probably need to do something to do with pointers here
  
  if (PluggedReel > 9) {
    PluggedReel = 0;
  }
  
};




void spin() {

  credit = credit - 0.10f;
  display(); 

  if (held_1 = false) {
    digitalWrite(10,HIGH);
  } 
  if (held_2 = false) {
    digitalWrite(11,HIGH);
  } 
  if (held_3 = false) {
    digitalWrite(12,HIGH);
  }


  randomSeed(randn);   //randomiser for the outcome of each reel
  int reel1 = fruitList[random(99)];
  randomSeed(randn);
  int reel2 = fruitList[random(99)];
  randomSeed(randn);
  int reel3 = fruitList[random(99)];
  randomSeed(randn);

  delay(random(200,1500));
  
  if (held_1 == false) {
    

    while (reel_1 =! reel1 ) { //each reel lands on the fruit that the randomiser has given
      while (sensor_1 > 300) {
           //do nothing
      } else {
       step(reel_1);
       step(reel_2);
       step(reel_3);
    }
    
  }

  };
 digitalWrite(10,LOW);
  randomSeed(randn);
  delay(random(200,1500));

         while (reel_2 =! reel2 ) {
      while (sensor_2 > 300) {
           //do nothing
      } else {
       step(reel_2);
       step(reel_3);
    }
    
  };
  
 digitalWrite(11,LOW);
  randomSeed(randn);
  delay(random(200,1500));

     while (reel_3 =! reel3 ) { 
      while (sensor_3 > 300) {
           //do nothing
      } else {
       step(reel_3);
    }
    
  };

digitalWrite(12,LOW);
int i;

while (i = 0; NumberOfFruits > i; ; i++) {

if (reel2 == i && reel2 == i && reel3 == i){

   win(fruit[i].prize);
  
                 }

            }
   
       };
       
if (reel_flag == false) { //toggle reel flag

  reel_flag = true; 
  
} else  {
  reel_flag = false;
       }

  };


};

