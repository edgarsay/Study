function getIdade() {
    return this.idade;
}

var edgar = {
    nome: "Edgar",
    idade: 19,
    getIdade: getIdade
}

console.log(edgar.getIdade());

var edgar = {
    nome: "Edgar",
    idade: 19,
    getIdade: function () {
        return this.idade;
    }
}

console.log(edgar.getIdade());