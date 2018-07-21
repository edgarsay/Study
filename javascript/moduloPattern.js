var counter = (function (nome) {
return{
    getNome : function () {
        return nome;
    },
    setNome : function (newNome) {
        return nome = newNome;
    }
}
})(); // alto invocando a função

console.log(counter.nome);
console.log(counter.getNome());

counter.setNome("Edgar dos Santos");

console.log(counter.getNome());