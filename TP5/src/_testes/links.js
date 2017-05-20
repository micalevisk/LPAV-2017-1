// http://www.binarypuzzle.com/puzzles.php?size=6

(function getPuzzle(ordem, printParaRequisicao=false){
	const arr = document.getElementsByClassName('puzzlecel')
	let saida=""

	for(let i=1; i <= arr.length; ++i ){
		let cell = arr[i-1].textContent.trim().replace(/^$/, '-')
		saida += cell

		if(i%ordem == 0) saida += '\n'
		else saida += ','
	}

	///para o arquivo de entrada
	console.error(`=== ENTRADA ${ordem}x${ordem} ===`);
	console.log(saida.replace(/,/g, '').replace(/-/g, '2').replace(/./g, '$& '))

	if(printParaRequisicao){
		let linhas = saida.split('\n').filter((e) => e.trim())
		linhas = linhas.map( (e) => '[' + e.replace(/[01-]/g, '"$&"') + ']' )
		console.log( '[' + linhas.join(',') + ']' )
	}
})(6);


// onde 'strmatriz' é uma string dada pela saída da
// execução do programa com o a matriz gerada acima
var strmatriz = ``

function preencherCom(strMatriz){
	const strToMatriz = (m) => {
		return m.split('\n')
			.filter(x => x.trim())
			.map(x => x.trim())
			.map(x => x.split(' '))
	}

	let matriz = strToMatriz(strMatriz)

	matriz.forEach((linha, i) => {
		linha.forEach((n, j) => {
			let l=i+1, c=j+1
			let cell = document.getElementById(`cel_${l}_${c}`)
			if(cell.style.color !== "rgb(0, 0, 0)"){//célula passível de edição
				CelClick(l, c)//muda pra 0
				if(matriz[i][j] === '1') CelClick(l, c)//muda pra 1
			}
		})
	})
}
preencherCom(strmatriz)



/*
// http://www.magmeister.be/binarypuzzlesolver/solve.php?puzzle=
var puzzles = [
	 '[["-","-","1","-","-","-"],["0","0","-","1","-","-"],["0","-","-","-","-","-"],["-","-","-","-","-","-"],["-","-","-","1","-","-"],["-","-","-","-","0","-"]]' //1
	,'[["-","0","-","-","-","-"],["-","-","-","-","-","-"],["1","-","-","-","-","-"],["-","0","-","-","0","-"],["1","-","-","0","-","-"],["-","0","-","-","-","0"]]' //2
	,'[["-","1","-","-","-","1"],["-","1","-","-","1","1"],["-","-","-","-","-","-"],["-","-","-","-","1","-"],["-","-","-","-","-","0"],["-","-","-","-","-","-"]]' //36
	,'[["0","-","-","1","-","0"],["-","1","-","-","-","-"],["-","-","-","1","-","-"],["1","-","-","-","-","-"],["-","-","-","-","-","0"],["1","-","-","1","-","-"]]' //41
	,'[["-","-","-","0","-","-"],["0","1","-","0","-","-"],["-","1","-","-","-","0"],["-","-","-","-","-","-"],["-","-","-","0","-","-"],["-","-","1","-","-","-"]]' //55
	,'[["1","-","-","-","-","-"],["-","-","-","0","-","-"],["-","-","1","-","1","-"],["-","0","-","-","-","-"],["-","0","-","-","1","-"],["-","-","1","-","-","-"]]' //82
	,'[["-","-","-","-","-","-"],["-","-","1","1","-","-"],["0","-","1","-","-","0"],["-","-","-","-","-","-"],["-","-","-","-","1","-"],["-","-","-","-","0","0"]]' //100
]

puzzles.forEach(function(puzzle, index){
	var URL = 'http://www.magmeister.be/binarypuzzlesolver/solve.php?puzzle=' + puzzle
	var request = new XMLHttpRequest();

	request.open('GET', URL, true);
	request.onload = function(){
		if(request.status >= 200 && request.status < 400){
			console.error(index+1)
			console.log( JSON.parse(request.responseText).join('\n').replace(/,/g, ' ') )
		}
	};
	request.send();
})
*/
