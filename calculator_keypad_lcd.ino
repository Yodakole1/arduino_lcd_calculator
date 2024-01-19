#include <Keypad.h>
#include <LiquidCrystal.h>


const int dim = 4;
char dugmici[dim][dim]={
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte pinovi_vrsta[dim]= {13,10,9,8};
byte pinovi_kolona[dim] = {7,6, A0, A1};

Keypad key = Keypad(makeKeymap(dugmici),pinovi_vrsta,pinovi_kolona,dim,dim);

boolean rezultat = false;
long  rez = 0;
int broj = 0;
int broj2=-1;
char znak = ' ';
char taster;
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Calculator");
  lcd.setCursor(0,0);
  delay(2000);
  lcd.clear();
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);

}


void loop() {
  taster = key.getKey();
  if (taster!=NO_KEY) {
    Pritisnut_taster();
  }

  if (rezultat==true) {
    Racunanje();
  }
}


void ispis(){
  if (broj2==-1) {
    lcd.setCursor(0,0);
    lcd.print(znak);
    lcd.print(broj);
  } else  {
    lcd.setCursor(0,0);
    lcd.print(broj2);
    lcd.print(znak);
    lcd.print(broj);
  }
  
  }

long  Racunanje(){
  rez=0;
  if (znak=='+') {
    rez = broj2+broj;
    ispis();
    lcd.print("=");
    lcd.print(rez);
    delay(9000);
    lcd.clear();
    cancel();
  }
  if (znak=='-') {
    rez=broj2-broj;
    ispis();
    lcd.print("=");
    lcd.print(rez);
    delay(9000);
    lcd.clear();
    cancel();
  } 
  if (znak=='/') {
    rez= broj2/broj;
    ispis();
    lcd.print("=");
    lcd.print(rez);
    delay(9000);
    lcd.clear();
    cancel();
  } 
  if (znak=='*') {
    rez = broj2 * broj;
    ispis();
    lcd.print("=");
    lcd.print(rez);
    delay(9000);
    lcd.clear();
    cancel();
  }
  rezultat=false;
}

void cancel(){
  rez=broj=0;
  broj2=-1;
  znak=' ';
  rezultat=false;
  lcd.clear();
  lcd.print("Calc is ready");
  delay(800);
  lcd.clear();

}

void Pritisnut_taster() {
  if (taster=='C') {
    cancel();
  }
  
  if (taster == '1') {
    if (broj==0) {
      broj=1;
    } else {
      broj = (broj*10)+1;
    }
  }

  if (taster=='2') {
    if (broj==0) {
      broj=2;
    } else {
      broj = (broj*10)+2;
    }
  }

  if (taster=='3') {
    if (broj==0) {
      broj=3;
    } else {
      broj = (broj*10)+3;
    }
  }

  if (taster=='4') {
    if (broj==0) {
      broj=4;
    } else {
      broj = (broj*10)+4;
    }
  }

  if (taster=='5') {
    if (broj==0) {
      broj=5;
    } else {
      broj = (broj*10)+5;
    }
  }

  if (taster=='6') {
    if (broj==0) {
      broj=6;
    } else {
      broj = (broj*10)+6;
    }
  }

  if (taster=='7') {
    if (broj==0) {
      broj=7;
    } else {
      broj = (broj*10)+7;
    }
  }


  if (taster=='8') {
    if (broj==0) {
      broj=8;
    } else {
      broj = (broj*10)+8;
    }
  }

  if (taster=='9') {
    if (broj==0) {
      broj=9;
    } else {
      broj = (broj*10)+9;
    }
  }

  if (taster=='#') {
    rezultat = true;
  }

  if (taster == 'A' || taster == 'B' || taster == '*' || taster == 'D') {
    
    if (taster == 'A') {
      znak='+';
      broj2=0;
      broj2=broj;
      broj=0;
    }

    if (taster == '*') {
      znak='*';
      broj2=0;
      broj2=broj;
      broj=0;
    }

    if (taster == 'D') {
      znak='/';
      broj2=0;
      broj2=broj;
      broj=0;
    }

    if (taster == 'B') {
     broj2=0;
     znak='-';
     broj2=broj;
     broj=0;
    }
  }

  delay(150);
  ispis();
}


