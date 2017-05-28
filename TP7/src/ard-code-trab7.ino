/**
 * Ler caracteres e acender as leds que representam a matriz.
 * Circuito: https://circuits.io/circuits/5073783-lpav-tp7-micael-levi
 *
 * A implementação se baseia em três fatos:
 * 1) Os números dos pinos das leds são menores que 10;
 * 2) Apenas letras minúsculas e alfabéticas serão representadas;
 * 3) O Braille representado tem as seguintes "regras":
 * - As primeiras 10 letras (a..j) só utilizam as duas primeiras linhas
 * - As próximas 10 letras (k..t) possuem a mesma representação que as 10 primeiras
 *   mas com o acréscimo de um ponto no canto inferior esquerdo
 * - As 5 últimas letras (u..z sem o w) possuem a mesma representação que as 10 primeiras
 *   mas com o acréscimo de ambos os pontos inferiores
 * - A letra 'w' tem a mesma representação que a 'j' mas com o acréscimo de um ponto no canto inferior direito
 *
 * A entrada (serial) deve ser uma cadeia de caracteres
 * Exemplos de entradas:
 * abcdefghij
 * klmnopqrst
 * uvwxyz
 *
 * @author Micael Levi
 * @date 28/05/2017
 */



/*** ====[CORES DOS FIOS]==== ***
preto   - cátodo leds cima
vermelho- ánodo leds cima
cinza   - cátodo leds meio
rosa    - ánodo leds meio
marrom  - cátodo leds baixo
roxo    - ánodo leds baixo
turquesa- cátodo buzzer
branco  - ánodo buzzer
*****************************/


#define BUZZER_PIN    13
#define TAM_ARR_NOTAS 8
#define TAM_ARR_PINOS 10

///Armazena a entrada
String inString;

//[letra bases]                          2    3    4    5    6    7
const unsigned arrFrequencias[] = {0,0, 440, 392, 349, 330, 294, 262 };

///Cada caractere (número natural) é o endereço de um pino ligado a uma led
///                                           a    b    c    d    e     f      g    h     i     j
const String arrPinosLeds[TAM_ARR_PINOS] = {"7","75","76","764","74","765","7654","754","65","654"};


void setup()
{
	pinMode(BUZZER_PIN, OUTPUT);

	Serial.begin(9600);
	while(!Serial);
	Serial.println("ESCREVA ALGO :)\n");
}

void loop()
{
	if(Serial.available() > 0){//definir a entrada
		inString = readSerialString();
		Serial.println("lido:{" + inString + "}");

		for(unsigned i=0; i < inString.length(); ++i){
			char charCurr = inString.charAt(i);

			///Converte uma letra em índice (0-9), i.e., 'a' vira 0, 'b' vira 1, etc
			unsigned charAsIndex = charToIndex(charCurr);
			String pinosExtras = "";

			///Tratamento do alfabeto
			if(charCurr >= 'k'){
				if(charCurr == 'w') charAsIndex = TAM_ARR_PINOS - 1;//o índice do 'j'
				else pinosExtras.concat("3");

				if(charCurr >= 'u'){
					pinosExtras.concat("2");
					if(charCurr > 'w') charAsIndex--;
				}
			}

			///Ativa as leds para o caractere lido
			setPinos(HIGH, charAsIndex, pinosExtras);
			delay(100);
			///Desliga o som
			noTone(BUZZER_PIN);
			delay(1900);///espera 2 segundos após a representação do caractere
			///Desativa as leds para o caractere lido
			setPinos(LOW, charAsIndex, pinosExtras);
			delay(550);///espera leds apagarem por completo
		}
	}
}



//=========================[AUXILIARES]=========================//
unsigned charToIndex(char c){ return (c - 'a') % TAM_ARR_PINOS; }
int charToInt(char c){ return c - '0'; }
//==============================================================//


///Retorna a string (minúscula e apenas caracteres válidos) lida da entrada serial
String readSerialString(){
	String strLida="";
	char charCurr;

	while(Serial.available() > 0){
		charCurr = Serial.read();
		if(!isAlpha(charCurr)) continue;
		if(charCurr != '\n') strLida.concat(charCurr);
		delay(100);
	}

	strLida.trim();
	strLida.toLowerCase();
	return strLida;
}

///Recebe um valor HIGH ou LOW para acender/apagar os pinos descritos em arrPinosLeds[indice]
void setPinos(int valor, unsigned indice, String pinosExtras){
	String strPinos = arrPinosLeds[ indice ] + pinosExtras;

	for(unsigned j=0; j < strPinos.length(); ++j){
		char charCurr = strPinos.charAt(j);
		int pino = charToInt(charCurr);

		///A frequência é dada pelo número do pino
		///Toca um som para avisar que um caractere foi representado
		if(valor == HIGH) tone(BUZZER_PIN, arrFrequencias[pino]);

		digitalWrite(pino, valor);
	}
}



/*** ============================[CHEAT SHEET]============================ ***

	~ 10 primeiras letras do alfabeto (bases para as demais combinações)
	"7"    a
	"75"   b
	"76"   c
	"764"  d
	"74"   e
	"765"  f
	"7654" g
	"754"  h
	"65"   i
	"654"  j

	~ acrescenta o '3' no final
	"73"    k
	"753"   l
	"763"   m
	"7643"  n
	"743"   o
	"7653"  p
	"76543" q
	"7543"  r
	"653"   s
	"6543"  t

	~ acrescenta o '2' no final
	"732"   u
	"7532"  v
	"6542"  w (pula a segunda etapa; base='j')
	"7632"  x
	"76432" y
	"7432"  z

*****************************************************************************/
