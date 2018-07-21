sexo = {
    sexo:"masculino"
}

pessoa1 = {
    nome: "Nome1",
    idade: 1,
    __proto__ : sexo // __proto__ não padrão em todos os navegadores
}

console.log(pessoa1.sexo);

pessoa2 = {
    nome: "Nome2",
    idade: 2,
}

Object.setPrototypeOf(pessoa2,sexo);

console.log(pessoa2.sexo);

pessoa3 = Object.create(sexo);
pessoa3.nome = "Nome3";
pessoa3.idade = 3;

console.log(pessoa3.sexo); // caso o Objecto ja tenha a propriedade ele não vai herdar


