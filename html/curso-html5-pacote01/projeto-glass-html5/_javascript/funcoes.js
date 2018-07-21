function mudaFoto(foto){
    document.getElementById("icone").src = foto;
}

function calc_total(){
    var quantidade = parseInt(document.getElementById("iquantidade").value);
    total = quantidade * 1500;
    document.getElementById("ipreco").value = total;
    
}