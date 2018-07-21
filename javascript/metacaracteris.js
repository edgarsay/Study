// . - Representa qualquer caractere
// /w - letra maiusculas e minusculas de 0-9 e '_'
// /W - é a negação de /w
// /d - [0-9]
// /D - [^0-9]
// /s - espaço em branco
// /S - ||
// /n - quebra de linha
// /t - tab

regExp = /\(\d{2}\)\s\d{4,5}-?\d{4,5}/;

table = "<table><tr><td>(21) 94934-4050</td><td>(51) 2923-7953</td></tr><tr><td>(11) 98815-5544</td><td>(81) 3467-7713</td></tr></table>";

console.log(table.match(regExp));

// i - Case-insensitive matching
// g - Global matching
// m - Multiline matching

regExp = /\(\d{2}\)\s\d{4,5}-?\d{4,5}/g;

table = "<table><tr><td>(21) 94934-4050</td><td>(51) 2923-7953</td></tr><tr><td>(11) 98815-5544</td><td>(81) 3467-7713</td></tr></table>";

console.log(table.match(regExp));
console.log(table.replace(regExp,"telefone"));
