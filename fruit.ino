#include <LiquidCrystal.h> 
float credit = 0;
float pot = 0;


int reel_1; // fruits 1-10
int reel_2;
int reel_3; 

bool held_1 = false;
bool held_2 = false;
bool held_3 = false;

int fruit[] = { //60 possibilities
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  5,
  5,
  5,
  5,
  5,
  5,
  6,
  6,
  6,
  6,
  6,
  6,
  7,
  7,
  7,
  7,
  8,
  8,
  8,
  8,
  9,
};

int sensor_1 = analogRead(15);
int sensor_2 = analogRead(14);
int sensor_3 = analogRead(13);

LiquidCrystal lcd(24, 26, 28, 30, 32, 36);


void setup() {

  pinMode(2, INPUT); // reel 1 
  pinMode(3, INPUT); // reel 2
  pinMode(4, INPUT); // reel 3
  pinMode(5, INPUT); // start reel 
  pinMode(6, INPUT);  // LED 1
  pinMode(7, INPUT); // LED 2
  pinMode(8, INPUT); // LED3
  pinMode(9, INPUT); // LED start reel
  pinMode(10, OUTPUT); // motor A
  pinMode(11, OUTPUT); // motor B 
  pinMode(12, OUTPUT); // motor C

}

void loop() {

  display();
  
  if (digitalRead(2)== HIGH) {
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

}


void toggle(String reel, boolean flag) {
  int led;

  
  if (reel == "heeld_1") {
    led = 14; 
  } else if (reel == "heeld_2") {
    led = 15; 
  } else if (reel == "heeld_3") {
    led = 16; 
  } 
    
  if (flag = false) {
    flag = true;
    digitalWrite(led,HIGH);
  } else {
    flag = false;
    digitalWrite(led,LOW);
  }

}


void win(int amount){

  lcd.print("You've won £");
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


void step(int reel){

  reel = reel +1;
  
  if (reel > 9) {
    reel = 0;
  }
  return;
}




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

  randomSeed(10);
  int reel1 = fruit[random(20)];
  randomSeed(10);
  int reel2 = fruit[random(20)];
  randomSeed(10);
  int reel3 = fruit[random(20)];
  randomSeed(10);
  delay(random(200,1500));
  
  if (held_1 == false) {
    

    if (reel_1 =! reel1 ) {
      if (sensor_1 < 300) {
           step(reel_1);
      } else {
      digitalWrite(10,LOW);
        return;      
      }
    }
  }

  randomSeed(10);
  delay(random(200,1500));
    
    
   if (held_2 == false) {
    
    if (reel_2 =! reel2) {
      if (sensor_2 < 300){
        step(reel_2);
      }
      else {
        digitalWrite(11,LOW);
      
        return;
      
      }
    }
  }
 
  randomSeed(10);
  delay(random(200,1500));

  if (held_3 == false) { 
    if (reel_3 =! reel3) {
      if (sensor_3 < 300) {
        step(reel_3);
      }
    else {
      digitalWrite(12,LOW);
      return;  
    }
   }
  }


if (reel1 == 0 && reel2 == 0 && reel3 == 0) {
  win(1);
}

else if (reel1 == 1 && reel2 == 1 && reel3 == 3) {
  win(1.4);
}


else if (reel1 == 2 && reel2 == 2 && reel3 == 2) {
  win(1.6);
}

else if (reel1 == 3 && reel2 == 3 && reel3 == 3) {
  win(2);
}

else if (reel1 == 4 && reel2 == 4 && reel3 == 4) {
  win(2.4);
}

else if (reel1 == 5 && reel2 == 5 && reel3 == 5) {
  win(3);
}

else if (reel1 == 6 && reel2 == 6 && reel3 == 6) {
  win(3.2);
}

else if (reel1 == 7 && reel2 == 7 && reel3 == 7) {
  win(3.6);
}


else if (reel1 == 8 && reel2 == 8 && reel3 == 8) {
  win(4);
}


else if (reel1 == 9 && reel2 == 9 && reel3 == 9) {
  win(5);
  } 
  else {
    return 0;
  }
}

