function Pessoa(nome,idade){
    this.nome = nome;
    this.idade = idade;
}

Pessoa.prototype.sexo = "masculino";

var edgar = new Pessoa("edgar",19);
var miguel = new Pessoa("miguel",19);

console.log(edgar.sexo);
console.log(miguel.sexo);