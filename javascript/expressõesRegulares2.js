regExp = /<table>(<tr>(<td>\([0-9]{2}\) [0-9]{4,5}-[0-9]{4}<\/td>)+<\/tr>)+<\/table>/;

table = "<table><tr><td>(21) 94934-4050</td><td>(51) 2923-7953</td></tr><tr><td>(11) 98815-5544</td><td>(81) 3467-7713</td></tr></table>";

console.log(regExp.test(table));