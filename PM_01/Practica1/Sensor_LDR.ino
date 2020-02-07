//Totalmente creado por LPZ ELECTRONICS para: YouTube (www.youtube.com/antoniolr95), Taringa y http://antoniolr95.blogspot.com


#define LED 9     //El LED esta conectado en el pin 9 
#define LDR 0     //El LDR esta conectador en el pin A0
#define POT 2 // Potenciometro en pin A2

int luz = 0;       
int valor_sensor = 0;       
int valor_limite = 0;  //Este valor hara que el LED cambie de estado a una determinada luminosidad (podeis con distintos valores para ajustar la sensibilidad)
int valor = 0;
int mo = 0;
int mp = 0;

void setup() {      //Configuracion de los pin como entrada o salida 
  Serial.begin(9600);    
  pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(POT,INPUT);
}

void loop ()  //Configuracion de los valores del LDR
{
  valor_sensor = analogRead(LDR);
  valor_limite = analogRead(POT); 
  luz = (5.0 * valor_sensor * 100.0)/1024.0; //Para entender esta formula visitar: http://programarfacil.com/podcast/48-sensor-de-temperatura-en-arduino/
  valor = (5.0 * valor_limite * 100.0)/1024.0;
  mo = map(luz,360,480,0,100);
  mp = map(valor,0,500,0,100);
  Serial.print(luz);  
  Serial.println(" Luz");      
  Serial.print(valor);
  Serial.println("Valor Limite ");
  Serial.print(mo);  
  Serial.println(" %luz");   
  Serial.print(mp);  
  Serial.println(" %pot");   
  delay(500);                       
  
  if (luz <= valor)   //Si el valor de luz es menor o igual que el valor limite
  {
    digitalWrite (LED, LOW);  //El led se apaga
  }
  if (luz > valor)   //Si es mayor que el valor limite
  {
    digitalWrite (LED, HIGH);  //El led se eniende
  }
}
