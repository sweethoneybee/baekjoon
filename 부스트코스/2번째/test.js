var oReq = new XMLHttpRequest();
oReq.addEventListener("load", function() {
    console.log(this.responseText);
});

oReq.open("GET", "./json.txt");
oReq.send();

//arrow function
// var getName = (name)=>"Kim " + name; 