//EXEMPLO 1 ==================================
var regExp = /9999-9999/;
var telefone = "9999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

//EXEMPLO 2 ==================================
var regExp = /(48) 9999-9999/;
var telefone = "(48) 9999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

var regExp = /\(48\) 9999-9999/; 
// '(' e ')' são expressões regulares
var telefone = "(48) 9999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

var regExp = /\(48\) 9999-9999/; 
// '(' e ')' são expressões regulares
var telefone = "O telefone é (48) 9999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

//EXEMPLO 3 ==================================

// '^' DIZ QUE TEM QUE COMEÇAR COM ESSE CARACTER
// '$' DIZ QUE TEM QUE TERMINAR COM ESSE CARACTER

var regExp = /^\(48\) 9999-9999$/; 
var telefone = "(48) 9999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

//EXEMPLO 4 ==================================

// '[]' CRIA UM GRUPO DE CARACTERES COM NO C

var regExp = /\([0-9][0-9]\) [0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]/; 
var telefone = "eu disse a ele que o numero era (48) 9999-9999, mas pode estar errado!";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

//EXEMPLO 5 ==================================

// Quantificadores 

//{n} - eu quero exatamente 2 ou 3
//{n,} - n é o minimo
//[n,m] - entre n e m

var regExp = /\([0-9]{2}\) [0-9]{4}-[0-9]{4}/; 
var telefone = "eu disse a ele que o numero era (48) 9999-9999, mas pode estar errado!";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test

var regExp = /\([0-9]{2}\) [0-9]{4,5}-[0-9]{4}/; 
var telefone = "(48) 9999-9999 ou (48) 99999-9999";

console.log(regExp.exec(telefone)); // exec 

console.log(regExp.test(telefone)); // test


//EXEMPLO 6 ==================================

// Quantificadores 2

// ? 1 ou 0 esse numero aqui é opcnal
// * 0 ou mais
// # 1 ou mais

var regExp = /\([0-9]{2}\) [0-9]{4,5}-?[0-9]{4}/;
var telefone = "(88) 99999999"

console.log(regExp.test(telefone)); // test


