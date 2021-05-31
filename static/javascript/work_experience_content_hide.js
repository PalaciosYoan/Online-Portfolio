function dropdown1(){
    var selectBox = document.getElementById("workEx");
    var value = selectBox.options[selectBox.selectedIndex].value;
    var x = document.getElementById("ex2");
    var y = document.getElementById("ex1");
    var lang = document.getElementById("languages");
    if (value == "Intel"){
        x.style.display = "none";
        y.style.display = "block";
        lang.style.display="block";
    }else if (value == "UCM-Dining"){
        y.style.display = "none";
        x.style.display = "block";
        lang.style.display="none";

    }
}


function projects(){
    var selectBox = document.getElementById("projects");
    var value = selectBox.options[selectBox.selectedIndex].value;
    var x = document.getElementById("project1");
    var y = document.getElementById("project2");
    var lang1 = document.getElementById("py");
    var lang2 = document.getElementById("m");
    var lang3 = document.getElementById("dax");
    if (value == "project1"){
        x.style.display = "block";
        y.style.display = "none";
        lang1.style.display="block";
        lang2.style.display="none";
        lang3.style.display="none";

    }else if (value == "project2"){
        y.style.display = "block";
        x.style.display = "none";
        lang1.style.display="none";
        lang2.style.display="block";
        lang3.style.display="block";
    }
}
