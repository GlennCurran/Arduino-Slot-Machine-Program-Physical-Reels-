
struct stats {

char[] title; //name of fruit

float prize; // cash value when three of a single fruit are displayed

int freq; //frequency out of 100

};

//config fruits below

int NumberOfFruits = 10;

stats.fruit[] { // fruits can be added/removed here, along with their cash reward and odds

{"cherry",0.6, 30},
{"grape", 1, 20},
{"lemon", 1.2, 12},
{"red seven", 2,10},
{"blue seven", 2.2, 8},
{"black seven", 2.4, 7},
{"single _bar" , 3, 6};
{"double bar" , 3.2, 4};
{"triple bar", 3.4, 2};
{"jackpot" , 5, 1};

};











