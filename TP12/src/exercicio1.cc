/**
 * Exercício 1: Editor Gráfico
 * @author Micael Levi
 * @date 23/06/2017
 */

#include <stdio.h>
#include <stdlib.h>

/******************************/
char** matrizImagem = NULL;
unsigned qtdLinhas = 0, qtdColunas = 0;

bool linhaInvalida(unsigned i){ return  i >= qtdLinhas; }
bool colunaInvalida(unsigned j){ return j >= qtdColunas;}
bool imagemNaoCriada(){ return matrizImagem == NULL; }
/******************************/



/**
 * I <M> <N>
 * Cria uma nova imagem com M linhas e N colunas
 * como todos os pixels zerados.
 */
void criarImagem(){
	int linhas, colunas;
	if( scanf("%d %d", &linhas, &colunas) != 2 ) return;
	if(linhas <= 0 || colunas <= 0) return;

	qtdLinhas = linhas;
	qtdColunas= colunas;
	matrizImagem = (char**) malloc(sizeof(char*) * qtdLinhas);
	for(unsigned i=0; i < qtdLinhas; ++i){
		matrizImagem[i] = (char*) malloc(sizeof(char)*qtdColunas);
		for(unsigned j=0; j < qtdColunas; ++j) matrizImagem[i][j] = '0';
	}
}



/**
 * C
 * Coloca todos os pixels da imagem com o valor 0.
 * O tamanho permanece.
 */
void zerarPixels(){
	if(imagemNaoCriada()) return;

	for(unsigned i=0; i < qtdLinhas; ++i)
		for(unsigned j=0; j < qtdColunas; ++j)
			matrizImagem[i][j] = '0';
}

/**
 * L <X> <Y> <C>
 * Colore o pixel (X,Y) com a cor C.
 */
void colorirPixel(){
	unsigned x, y;
	char c;
	if( scanf("%u %u %c", &x, &y, &c) != 3 ) return;
	if(imagemNaoCriada()) return;

	--x; --y;
	if(linhaInvalida(x) || colunaInvalida(y)) return;

	matrizImagem[x][y] = c;
}

/**
 * V <X> <Y1> <Y2> <C>
 * Desenha um segmento vertical com a cor C na coluna X,
 * entre as linhas Y1 e Y2 (inclusive).
 */
void desenharSegVertical(){
	unsigned x, y1, y2;
	char c;
	if( scanf("%u %u %u %c", &x, &y1, &y2, &c) != 4 ) return;
	if(imagemNaoCriada()) return;

	--x; --y1; --y2;
	if(linhaInvalida(y1) || linhaInvalida(y2) || colunaInvalida(x)) return;

	for(unsigned i=y1; i <= y2; ++i) matrizImagem[i][x] = c;
}

/**
 * H <X1> <X2> <Y> <C>
 * Desenha um segmento horizontal com a cor C na linha Y,
 * entre as colunas X1 e X2 (inclusive).
 */
void desenharSegHorizontal(){
	unsigned x1, x2, y;
	char c;
	if( scanf("%u %u %u %c", &x1, &x2, &y, &c) != 4 ) return;
	if(imagemNaoCriada()) return;

	--x1; --x2; --y;
	if(linhaInvalida(y) || colunaInvalida(x1)  || colunaInvalida(x1)) return;

	for(unsigned j=x1; j <= x2; ++j) matrizImagem[y][j] = c;
}

/**
 * K <X1> <Y1> <X2> <Y2> <C>
 * Desenha um retângulo preenchido com a cor C,
 * onde (X1,Y1) é o canto superior esquerdo, e
 * (X2,Y2) é o canto inferior direito.
 */
void desenharRetangulo(){
	unsigned x1, y1, x2, y2;
	char c;
	if( scanf("%u %u %u %u %c", &x1, &y1, &x2, &y2, &c) != 5 ) return;
	if(imagemNaoCriada()) return;

	--x1;--y1;--x2;--y2;
	if(linhaInvalida(x1) || linhaInvalida(x2) || colunaInvalida(y1) || colunaInvalida(y2)) return;

	for(unsigned i=x1; i <= x2; ++i){
		for(unsigned j=y1; j <= y2; ++j)
			matrizImagem[i][j] = c;
	}
}

///Auxiliar Recursivo
void colorir(unsigned linha, unsigned coluna, char c){
	if(linhaInvalida(linha)
	|| colunaInvalida(coluna)
	|| matrizImagem[linha][coluna] != '0') return;

	matrizImagem[linha][coluna] = c;
	colorir(linha-1,coluna, c);//norte
	colorir(linha+1,coluna, c);//sul
	colorir(linha,coluna+1, c);//leste
	colorir(linha,coluna-1, c);//oeste
}

/**
 * F <X> <Y> <C>
 * Inicialmente, o pixel (X,Y) é colorido com a cor C.
 * Em seguida, preenche-se com a mesma cor C todos os outros
 * pixels de tenham a cor zero e que compartilhan um lado
 * comum com o pixel (X,Y).
 */
void preencherFluxo(){
	unsigned x, y;
	char c;
	if( scanf("%u %u %c", &x, &y, &c) != 3 ) return;
	if(imagemNaoCriada()) return;

	--x; --y;
	if(linhaInvalida(x) || colunaInvalida(y)) return;

	matrizImagem[x][y] = '0';
	colorir(x,y,c);
}

/**
 * S
 * Escrever na tela o conteúdo da imagem atual.
 */
void mostrarImagem(){
	if(imagemNaoCriada()) return;

	for(unsigned i=0; i < qtdLinhas; ++i){
		for(unsigned j=0; j < qtdColunas; ++j)
			printf("%c", matrizImagem[i][j]);
		printf("\n");
	}
}

/**
 * X
 * Terminar a sessão.
 */
void terminar(){
	if(!imagemNaoCriada()){
		for(unsigned i=0; i < qtdLinhas; ++i) free(matrizImagem[i]);
		free(matrizImagem);
		matrizImagem = NULL;
	}

	exit(0);
}



void commandHandler(char command){
	switch(command){
		case 'I': criarImagem(); break;
		case 'C': zerarPixels(); break;
		case 'L': colorirPixel(); break;
		case 'V': desenharSegVertical(); break;
		case 'H': desenharSegHorizontal(); break;
		case 'K': desenharRetangulo(); break;
		case 'F': preencherFluxo(); break;
		case 'S': mostrarImagem(); break;
		case 'X': terminar(); break;
		default: break;
	}
}


main()
{
	char cmd;
	while( scanf("%c", &cmd) )
		commandHandler(cmd);
}
