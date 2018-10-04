
function show(x) {
    window.open('../Code/' + x);
}
function reveal(x){
	if(document.getElementById(x).style.display === 'block') document.getElementById(x).style.display = 'none';
	else document.getElementById(x).style.display = 'block';
	if(x === 'stack') document.getElementById('queue').style.display = 'none';
	else document.getElementById('stack').style.display = 'none';
}