// função contrutora

var Pessoa = function (nome, idade) {
    this.nome = nome;
    this.idade = idade;
}

var lista = [];
lista.push(new Pessoa("jubileu", 50));
lista.push(new Pessoa("edgar", 19));

console.log(lista);

//função fabrica

var criaPessoa = function (nome, idade) {
    return {
        nome: nome,
        idade: idade
    };
}

var lista2 = [];
lista.push(criaPessoa("jubileu", 50));
lista.push(criaPessoa("edgar", 19));

console.log(lista2);
