var array = [
    { nome: "alef", idade: 24 },
    { nome: "edgar", idade: 19 },
    { nome: "aaaa", idade: 24 }
]

array.sort(function (a, b) {
    return a.nome.localeCompare(b.nome);
});

console.log(array);