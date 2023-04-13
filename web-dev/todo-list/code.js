window.addEventListener('keydown', onKeydown);
const element = document.getElementById('note');

function onKeydown(event){
	if (element === document.activeElement && event.key === 'Enter'){
		addNote();	
	}
}

function addNote(){
	const para = document.createElement("p");
	const node = document.createTextNode(document.querySelector("#note").value);
	para.appendChild(node);


	const element2 = document.getElementById('addtxt');
	element2.appendChild(para);
	element.value = null;
	if (document.getElementById('addtxt').hasChildNodes() > 0)
	{
		const sep = document.createElement("div");
		element2.appendChild(para);
	}
}