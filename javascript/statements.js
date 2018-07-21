try {
    var test = require('fs').readFileSync('test.txt', 'utf-8'); // fopen do javascript
} catch (e) {
    console.log("Erro : " + e);
}


if (1) throw "Deu merda";
// try and catch tratamento de erro

console.log(test);