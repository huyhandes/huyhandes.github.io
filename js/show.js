function show(x){
	//document.writeln(x);
	//window.open(x);
	document.getElementById('frame').src = x;
	var e = document.getElementById('frame').style.display;
	if ( e === "block") document.getElementById('frame').style.display = "none";
	else document.getElementById('frame').style.display = "block";
}