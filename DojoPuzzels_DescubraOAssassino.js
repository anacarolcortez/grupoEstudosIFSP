//http://dojopuzzles.com/problemas/exibe/descubra-o-assassino/

const suspeito = ['Charles B. Abbage' , 'Donald Duck Knuth', 'Ada L. Ovelace', 'Alan T. Uring', 'Ivar J. Acobson', 'Ras Mus Ler Dorf'];
const local = ['Redmond', 'Palo Alto', 'San Francisco', 'Tokio', 'Restaurante no Fim do Universo', 'São Paulo', 'Cupertino', 'Helsinki', 'Maida Vale', 'Toronto'];
const arma = ['Peixeira', 'DynaTAC 8000X', 'Trezoitão', 'Trebuchet', 'Maçã', 'Gládio'];
let tentativas = 5;
let cont = 1;
let errado = true;

function escolhaSuspeitoArma(lista) {
	x = ((Math.random()/2).toFixed(1))*10;
	return lista[x];
}

function escolhaLocal(lista) {
	x = (Math.random().toFixed(1))*10;
	return lista[x];
}

function crime(){
	s = escolhaSuspeitoArma(suspeito);
	l = escolhaLocal(local);
	a = escolhaSuspeitoArma(arma);
	return crimeEscolhido = [s, l, a];
}

crime = crime();
//console.log(crime);

function confereChute(crime, chuteSuspeito, chuteLocal, chuteArma){

	const confereSuspeito = crime[0] == chuteSuspeito ? 0 : 1;
	const confereLocal = crime[1] == chuteLocal ? 0 : 2;
	const confereArma = crime[2] == chuteArma ? 0 : 3;

	console.log(confereSuspeito, confereLocal, confereArma);

	if (confereSuspeito == 0 && confereLocal == 0 && confereArma == 0){
		errado = false;
		console.log("Parabéns, você acertou!");
	}
}

while (errado && tentativas > 0){
	console.log("\nTentativa nº " + cont);

	let chuteSuspeito = prompt("Adivinhe o criminoso: ");
	let chuteLocal = prompt("Adivinhe o local: ");
	let chuteArma = prompt("Adivinhe a arma: ");

	confereChute(crime, chuteSuspeito, chuteLocal, chuteArma);
	
	tentativas--;
	cont++;

}

