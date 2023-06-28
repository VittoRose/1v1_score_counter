#include <TM1637.h>

#define     BTTP1   2
#define     BTTM1   3
#define     BTTP2   4
#define     BTTM2   5
#define     DIO1    6
#define     CLK1    7
#define     DIO2    8
#define     CLK2    9
#define     BUZZER  A2

#define     INTERVAL 300

TM1637 disp1(CLK1, DIO1), disp2(CLK2,DIO2);

unsigned long tp1 = 0;
unsigned long tm1 = 0;
unsigned long tp2 = 0;
unsigned long tm2 = 0;
unsigned long t0 = 0;
unsigned long t1 = 0;

int score1 = 0;
int score2 = 0;

void setup(){

    pinMode(BTTP1, INPUT);
    pinMode(BTTM1, INPUT);
    pinMode(BTTP2, INPUT);
    pinMode(BTTM2, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN,LOW);
            pinMode(BUZZER, OUTPUT);
    Serial.begin(9600);

    disp1.init();
    disp2.init();
    disp1.set(BRIGHTEST);
    disp2.set(BRIGHTEST);
    disp1.point(HIGH);
    disp2.point(HIGH);
}

void loop(){
    
    // score 1
    if(digitalRead(BTTP1)){
        if(millis() - tp1 >= INTERVAL){
            score1++;
            tone(BUZZER, 8000);
            delay(50);
            noTone(BUZZER);
            tp1 = millis();
        }   
    }

    if(digitalRead(BTTM1)){
        if(millis() - tm1 >= INTERVAL){
            score1--;
            if(score1 <= 0) score1 = 0;
            tm1 = millis();
        }
        t0 = millis();
        while(digitalRead(BTTM1)){        
            t1 = millis();
            if(t1 - t0 >= 200)    digitalWrite(LED_BUILTIN, HIGH);   
            
            if(t1 - t0 >= 1100)    {
                disp1.clearDisplay();
                digitalWrite(LED_BUILTIN, LOW);    
            }
        }
        digitalWrite(LED_BUILTIN, LOW);
        
        if(t1 - t0 >= 1000){
            score1 = 0;
            t0 = 0;
            t1 = 1;
        }    
    }

    // score 2
    if(digitalRead(BTTP2)){
        if(millis() - tp2 >= INTERVAL){
            score2++;
            tone(BUZZER, 8000);
            delay(50);
            noTone(BUZZER);
            tp2 = millis();
        }   
    }

    if(digitalRead(BTTM2)){
        if(millis() - tm2 >= INTERVAL){
            score2--;
            if(score2 <= 0) score2 = 0;
            tm2 = millis();
            delay(10);
        }
        
        t0 = millis();

        while(digitalRead(BTTM2)){        
            t1 = millis();
            if(t1 - t0 >= 200) digitalWrite(LED_BUILTIN, HIGH);   
            

            if(t1-t0 >= 1100) {
                digitalWrite(LED_BUILTIN, LOW);  
                disp2.clearDisplay();
            }
        }
        digitalWrite(LED_BUILTIN, LOW);  

        
        if(t1 - t0 >= 1000){
            score2 = 0;
            t0 = 0;
            t1 = 1;
        }
        
    }

    scoredisplay(score1, score2);    
}   

void scoredisplay(int score1, int score2){

    int u1 = score1%10;
    int d1 = (score1/10)%10;

    int u2 = score2%10;
    int d2 = (score2/10)%10;
    

    disp1.display(3, u1);
    disp1.display(1, u2);
        
    disp2.display(1, u1);
    disp2.display(3, u2);
    
    disp2.display(2, d2);
    disp1.display(0, d2);

    
    disp1.display(2, d1);
    disp2.display(0, d1);
    
}
