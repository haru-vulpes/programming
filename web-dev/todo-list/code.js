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
	const addtxt = document.getElementById('addtxt');
	addtxt.style.width = "100%";
	if (addtxt.childElementCount > 0)
	{
		const sep = document.createElement("div");
		sep.style.height = "1px";
		sep.style.width = "100%";
		sep.style.backgroundColor = "rgb(148 163 184)";
		addtxt.appendChild(sep);
	}
	para.appendChild(node);
	addtxt.appendChild(para);
	element.value = null;
}