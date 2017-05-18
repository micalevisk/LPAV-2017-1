// http://www.binarypuzzle.com/puzzles.php?size=6
(function getPuzzle(){
	const arr = document.getElementsByClassName('puzzlecel')
	let saida=""

	for(let i=1; i <= arr.length; ++i ){
		let cell = arr[i-1].textContent.trim().replace(/^$/, '-')
		saida += cell

		if(i%6 == 0) saida += '\n'
		else saida += ','
	}

	///para o arquivo de entrada
	console.log(saida.replace(/,/g, '').replace(/-/g, '2').replace(/./g, '$& '))


	let linhas = saida.split('\n').filter((e) => e.trim())
	linhas = linhas.map( (e) => '[' + e.replace(/[01-]/g, '"$&"') + ']' )

	///para o parâmetro da requisição
	console.log( '[' + linhas.join(',') + ']' )
})()



// http://www.magmeister.be/binarypuzzlesolver/solve.php?puzzle=
var puzzles = [
	 '[["-","-","1","-","-","-"],["0","0","-","1","-","-"],["0","-","-","-","-","-"],["-","-","-","-","-","-"],["-","-","-","1","-","-"],["-","-","-","-","0","-"]]' //1
	,'[["-","0","-","-","-","-"],["-","-","-","-","-","-"],["1","-","-","-","-","-"],["-","0","-","-","0","-"],["1","-","-","0","-","-"],["-","0","-","-","-","0"]]' //2
	,'[["-","1","-","-","-","1"],["-","1","-","-","1","1"],["-","-","-","-","-","-"],["-","-","-","-","1","-"],["-","-","-","-","-","0"],["-","-","-","-","-","-"]]' //36
	,'[["0","-","-","1","-","0"],["-","1","-","-","-","-"],["-","-","-","1","-","-"],["1","-","-","-","-","-"],["-","-","-","-","-","0"],["1","-","-","1","-","-"]]' //41
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
