// não exite privative e public no Javascript

var pessoa = function () {
    var nome = "Edgar";
    var idade = 19;
    return {
        add: function () {
            return ++idade;
        }
    }
}

var edgar = pessoa();

console.log(edgar.idade);       // undefined
console.log(edgar.add());       // 20

function aluno(nome) {  // função fabrica com variaval privativa
    return {
        setNome: function (nNome) {
            nome = nNome;
        },
        getNome: function () {
            return nome;
        }
    }
}


var raquel = aluno("Raquel");

console.log(raquel.nome);       // undefined

console.log(raquel.getNome());  // Raquel

raquel.setNome("Vanessa");

console.log(raquel.getNome());  // Vanessa

var Count = function (number) { // função construtora
    this.getNumber = function () {
        return number
    }
    this.setNumber =function (nNumber) {
        number = nNumber;
    }
}

count = new Count(1);

console.log(count.getNumber());

count.setNumber(2);

console.log(count.getNumber());