var count = 0;
var add = function () {
    return count += 1;
};
add();
add();
add();

var lista = [];
var add = function (n) {
    return lista.push(n);
};
add('a');
add('b');
add('c');
add('d');
add();      //undefined

console.log(count);
console.log(lista);

var count = {
    count: 0,
    add: function(){
        this.count += 1;
    }
}

count.add();
count.add();
count.add();

var lista = {
    lista: [],
    add: function (x) {
        this.lista.push(x);
    }
}

lista.add('a');
lista.add('b');
lista.add('c');
count.add();    //funcionado corretamente


console.log(count.count);
console.log(lista.lista);

// evitar erro atravez do encapisulamento
// problema! : ainda é possivel acessa as variaveis diretamente o que pode gerar um NaN