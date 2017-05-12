/**
 * Exercício 1: Problema do Labirinto
 * @author Micael Levi
 * @date 05/05/2017
 */

#include <stdio.h>
#include <stdlib.h>

#define VISITADO 2
#define PAREDE 1

// --------------------- //
struct Coordenada** labirinto;
unsigned m, n;
// --------------------- //


struct Coordenada {
	unsigned short lin, col;
	unsigned short valor;
	Coordenada(unsigned short l, unsigned short c, unsigned short val){
		lin = l;
		col = c;
		valor = val;
	}
	bool foiVisitado(){ return valor == VISITADO; }
	void marcarVisitado(){ valor = VISITADO; }
	bool ehParede(){ return valor == PAREDE; }
	bool ehSaida(int m, int n){ return (lin == m-1) && (col == n-1); }
	void print(){ printf("%hu %hu\n", lin+1, col+1); }
};


bool coordenadaInvalida(int i, int j){ return (i < 0) || (j < 0) || (i >= m) || (j >= n); }

bool calcularLabirinto(int i, int j){
	if(coordenadaInvalida(i,j)) return false;
	Coordenada& c = labirinto[i][j];
	if(c.ehParede() || c.foiVisitado()) return false;
	if(c.ehSaida(m,n)){ c.print(); return true; }

	c.marcarVisitado();
	if(
		calcularLabirinto(i-1, j) || // N
		calcularLabirinto(i+1, j) || // S
		calcularLabirinto(i, j+1) || // L
		calcularLabirinto(i, j-1) || // O
		calcularLabirinto(i-1,j-1)|| // NO
		calcularLabirinto(i-1,j+1)|| // NE
		calcularLabirinto(i+1,j-1)|| // SO
		calcularLabirinto(i+1,j+1)   // SE
	  ){
		c.print();
		return true;
	}

	return false;
}



main()
{
	scanf("%u %u", &m, &n);

	/// ================= [ LEITURA DA MATRIZ ] ================= ///
	labirinto = (Coordenada**) malloc(sizeof(Coordenada*)*m);
	for(int i=0; i < m; ++i){
		labirinto[i] = (Coordenada*) malloc(sizeof(Coordenada)*n);
		for(int j=0; j < n; ++j){
			unsigned short val; scanf("%hu", &val);
			labirinto[i][j] = Coordenada(i, j, val);
		}
	}

	calcularLabirinto(0,0);
}
