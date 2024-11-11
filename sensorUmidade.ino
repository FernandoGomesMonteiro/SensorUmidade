// Defina o pino do sensor
int sensorPin = A0;  // Pino analógico onde o sensor está conectado
int sensorValue = 0;  // Variável para armazenar o valor lido do sensor

void setup() {
  // Inicializa a comunicação serial para exibir os valores no monitor serial
  Serial.begin(9600);
  delay(2000); // Aguarda 2 segundos para a estabilização do sensor
}

void loop() {
  // Lê o valor do sensor (0-1023, onde 0 é solo muito seco e 1023 é solo completamente molhado)
  sensorValue = analogRead(sensorPin);
  
  // Exibe o valor no monitor serial
  Serial.print("Valor do Sensor: ");
  Serial.println(sensorValue);
  
  // Exibe o estado da umidade do solo baseado no valor lido
  if (sensorValue < 300) {
    Serial.println("Solo muito seco.");
  } else if (sensorValue >= 300 && sensorValue < 700) {
    Serial.println("Solo com umidade média.");
  } else {
    Serial.println("Solo muito úmido.");
  }

  // Aguarda 1 segundo antes de fazer a próxima leitura
  delay(3000);
}
