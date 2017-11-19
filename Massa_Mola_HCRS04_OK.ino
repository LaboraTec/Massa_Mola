/**OSCILADOR MASSA MOLA
   CRIADO POR: CAMILA FERNANDES CARDOZO, UNISINOS.
   2017/2
*/

#define Echo 12 //denomina a porta digital 12 de Echo
#define Trig 13  //denomina a porta digital 13 de Trig
unsigned long t, tempo, starttime;// declara t como unsigned long
float d;

void setup() {  // instruções executadas somente na inicialização do programa.
  Serial.begin(115200); // inicializa a comunicação serial com a placa Arduino numa velocidade de 9600 bits/s
  pinMode(Trig, OUTPUT); //define o pino Trig como uma saída de dados
  pinMode(Echo, INPUT); // define o pino Echo como uma entrada de dados
  starttime = millis(); //guarda o transcorrido na inicialização do programa
}

void loop() { // instruções que serão executadas repetidas vezes
  digitalWrite(Trig, LOW);  //coloca o pino Trig no estado 0
  delayMicroseconds(2); //espera 2 microssegundos
  digitalWrite(Trig,  HIGH); //coloca a porta digital Trig no estado 1
  delayMicroseconds(10); // espera 10 microssegundos
  digitalWrite(Trig, LOW); // retorna o pino Trig para 0
  t = pulseIn(Echo, HIGH); // coleta o tempo em que o pino Echo esteve no estado 1, em microssegundos
  d = ((343 * t) / 20000); // calcula  a distâcia entre objeto e sensor
  tempo = millis() - starttime; //guarda o instante da última aquisição
  Serial.print(tempo); // escreve na serial o valor guardado em tempo
  Serial.print(','); //insere um separador
  Serial.println(d); //escreve na serial a distância entre sensor e objeto

  delay(100); // aguarda 100 milissegundos e recomeça o loop

}


