var getNome = function (mais) {
    return this.nome + mais;
}

var Edgar = {
    nome : "Edgar",
    idade : 19
}

console.log(getNome.call(Edgar, " dos Santos")); // parametros normal

console.log(getNome.apply(Edgar,[" Oliveira"])); // parametros todos em forma de array

// caso eu passe mais argumentos que o definido na funçao o execente é iginorado e um 
// caso passe menos sera considerado 'undefined'
// para acessar essa argumentos posso usar 'arguments'