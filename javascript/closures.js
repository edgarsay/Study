var HelloWord = function () {
    return "hello my friend!";
}

var hello = function () {
    return HelloWord;
}


console.log(hello()); //    [Function]
console.log(hello()()); //  hello my friend!