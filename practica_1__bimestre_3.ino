/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Eliezer Denilson Gaitán Corado
 * Carnet: 2018450
 * Proyecto: Uso de interrupciones externas- Bimestre III
*/

//Directivas de preprocesador
#define btn_rising  2     //pin 2 utilizado para una interrupción externa por rising
#define btn_falling 3     //pih 3 utilizado para una interrupción externa por falling
#define a 10
#define b 9
#define c 6
#define d 7
#define e 8
#define f 11
#define g 12
#define a2 A0
#define b2 A1 
#define c2 A4
#define d2 A3
#define e2 A2
#define f2 4
#define g2 5
//Funciones ISR 
/*
 * ISR = interrupt services routine
 * Estas son las funciones que van a ser llamadas al dispararse una interrupcion externa
 * 
 * NOTA: las funciones deben de ser sin retorno y sin parametros
*/
void funcion_ISR_falling(void);
void funcion_ISR_rising(void);
void contador(void);
//Variables
volatile static bool f_print=false; // variable para mostrar en texto en el loop
volatile static int i=0; // variable que cuenta de 0 - 255;
void setup() {  
  Serial.begin(19200); //Inicio la comunicación serial
  pinMode(btn_rising, INPUT);  //pin 2 como entrada
  pinMode(btn_falling, INPUT); //pin 3 como entrada
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
 
 pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(g2,OUTPUT);                 }
void loop() {
 contador(); 
if(f_print)      {
  f_print = false; //limpio la variable
  Serial.println(i); //imprimo el valor de I
}          }
//Funciones de ISR
void funcion_ISR_rising(void)
{
  f_print = true;
  //aumentar el valor de la variable
  i++; 
  //Serial.println(i);
}
void funcion_ISR_falling(void)    {
  f_print = true;
  //disminuir el valor de una variable
  i--;   }
  //nos ayudara a que el valor se reicie cuando llegue al numero 50
void contador (void){
  if ( i >51){
    i = 0;        }
  if( i ==-1){
    i = 50;       }  
  //numeros de los displays
  //numeros del 1 al 10 
  if (i==0){
digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);
  digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);              }   
     if (i==1){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                 }  
    if (i==2){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,HIGH);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,LOW);
    digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);             }  
 if (i==3){
     digitalWrite(a2, LOW);
     digitalWrite(b2, LOW);
     digitalWrite(c2, LOW);
     digitalWrite(d2, LOW);
     digitalWrite(e2, HIGH);
     digitalWrite(f2, HIGH);
     digitalWrite(g2, LOW);
 digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                    }  
if (i==4){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                } 
if (i==5){
     digitalWrite(a2,LOW);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW); 
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                  }  
if (i==6){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                   }
  if (i==7){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);              } 
     if (i==8){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);             }  
if (i==9){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);                   }
if (i==10){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);  
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);                 }   
     //numeros del 11 al 20
     if (i==11){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);  
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);             }  
    if (i==12){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,HIGH);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,LOW); 
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);                } 
 if (i==13){
     digitalWrite(a2, LOW);
     digitalWrite(b2, LOW);
     digitalWrite(c2, LOW);
     digitalWrite(d2, LOW);
     digitalWrite(e2, HIGH);
     digitalWrite(f2, HIGH);
     digitalWrite(g2, LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);             }  
if (i==14){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
      digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);              }  
if (i==15){
     digitalWrite(a2,LOW);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
        digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);              }  
if (i==16){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW); 
        digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);              }
if (i==17){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);  
        digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);            }  
     if (i==18){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);         }  
if (i==19){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
      digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);         }
       if (i==20){
digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);          }    
     //numeros del 21 al 30
     if (i==21){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
          digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);          } 
    if (i==22){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,HIGH);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,LOW);     
       digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);        } 
 if (i==23){
     digitalWrite(a2, LOW);
     digitalWrite(b2, LOW);
     digitalWrite(c2, LOW);
     digitalWrite(d2, LOW);
     digitalWrite(e2, HIGH);
     digitalWrite(f2, HIGH);
     digitalWrite(g2, LOW); 
          digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);         } 
if (i==24){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);  
          digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);         }  
if (i==25){
     digitalWrite(a2,LOW);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);          } 
if (i==26){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);               }     
if (i==27){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);            }  
     if (i==28){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);            }  
if (i==29){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);               }
  if (i==30){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);           }  
     //numeros del 31 al 40
     if (i==31){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);         }  
    if (i==32){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,HIGH);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);         }  
 if (i==33){
     digitalWrite(a2, LOW);
     digitalWrite(b2, LOW);
     digitalWrite(c2, LOW);
     digitalWrite(d2, LOW);
     digitalWrite(e2, HIGH);
     digitalWrite(f2, HIGH);
     digitalWrite(g2, LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);          }
if (i==34){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);     }  
if (i==35){
     digitalWrite(a2,LOW);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);        }  
if (i==36){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);    }
if (i==37){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);            } 
     if (i==38){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);           }  
if (i==39){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a, LOW);
     digitalWrite(b, LOW);
     digitalWrite(c, LOW);
     digitalWrite(d, LOW);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);       }  
if (i==40){
digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);           }  
     //numeros del 41 al 50
       if (i==41){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);      }  
    if (i==42){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,HIGH);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);           }  
 if (i==43){
     digitalWrite(a2, LOW);
     digitalWrite(b2, LOW);
     digitalWrite(c2, LOW);
     digitalWrite(d2, LOW);
     digitalWrite(e2, HIGH);
     digitalWrite(f2, HIGH);
     digitalWrite(g2, LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);            }  
if (i==44){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);        }  
if (i==45){
     digitalWrite(a2,LOW);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);           }  
if (i==46){
     digitalWrite(a2,HIGH);
     digitalWrite(b2,HIGH);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);           }
if (i==47){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,HIGH);
     digitalWrite(g2,HIGH);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);            }  
     if (i==48){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);                  }
if (i==49){
     digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,HIGH);
     digitalWrite(e2,HIGH);
     digitalWrite(f2,LOW);
     digitalWrite(g2,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);                 }  
  if (i==50){
digitalWrite(a2,LOW);
     digitalWrite(b2,LOW);
     digitalWrite(c2,LOW);
     digitalWrite(d2,LOW);
     digitalWrite(e2,LOW);
     digitalWrite(f2,LOW);
     digitalWrite(g2,HIGH);
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);               }
}   
