function dropdown1(){
    var selectBox = document.getElementById("projects");
    var value = selectBox.options[selectBox.selectedIndex].value;
    var p1lang = document.getElementById("py");
    var p2lang = document.getElementById("m");
    var p3lang = document.getElementById("dax");
    var p4lang = document.getElementById("proj4");

    var proj1 = document.getElementById("project1");
    var proj2 = document.getElementById("project2");
    var proj3 = document.getElementById("project3");
    var proj4 = document.getElementById("project4");

    if (value == "proj1"){
        proj1.style.display = "block";
        proj2.style.display = "none";
        proj3.style.display = "none";
        proj4.style.display = "none";

        p1lang.style.display = "block";
        p2lang.style.display = "none";
        p3lang.style.display = "none";
        p4lang.style.display = "none";

        p1lang.style.alignContent = "center";

    }else if (value == "proj2"){
        proj1.style.display = "none";
        proj2.style.display = "block";
        proj3.style.display = "none";
        proj4.style.display = "none";

        p1lang.style.display = "none";
        p2lang.style.display = "block";
        p2lang.style.textAlign = "center";
        p3lang.style.display = "none";
        p4lang.style.display = "none";

    }else if (value == "proj3"){
        proj1.style.display = "none";
        proj2.style.display = "none";
        proj3.style.display = "block";
        proj4.style.display = "none";

        p1lang.style.display = "none";
        p2lang.style.display = "none";
        p3lang.style.display = "block";
        p4lang.style.display = "none";

    }else if (value == "proj4"){
        proj1.style.display = "none";
        proj2.style.display = "none";
        proj3.style.display = "none";
        proj4.style.display = "block";

        p1lang.style.display = "none";
        p2lang.style.display = "none";
        p3lang.style.display = "none";
        p4lang.style.display = "block";

    }
}