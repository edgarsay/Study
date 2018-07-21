// 0 == '' -> true
// 0 == '0' -> true
// false == undefined -> false
// false == null -> false
// null == undefined -> true
// 1 == true -> true
// 0 == false -> true
// 0 == '\n' -> true

var Ob = function (v1,v2){
    this.v1 = v1;
    this.v2 = v2;
};

ob1 = new Ob(1,2);

console.log(ob1 instanceof Ob);

delete ob1.v2;

console.log(ob1 instanceof Ob);