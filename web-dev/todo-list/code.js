window.addEventListener('keydown', onKeydown);
const element = document.getElementById('note');

function onKeydown(event){
	if (element === document.activeElement && event.key === 'Enter'){
		addNote();	
	}
}

function deletOnClick(event){
	const previousSeparator = event.target.parentNode.parentNode.previousSibling
	const nextSeparator = event.target.parentNode.parentNode.nextSibling

	if (previousSeparator && previousSeparator.tagName === 'DIV'){
		previousSeparator.remove();
	}
	else if (nextSeparator && nextSeparator.tagName === 'DIV'){
		nextSeparator.remove();
	}
	event.target.parentNode.parentNode.remove();
}

function editOnClick(event){
	const txt = event.target.parentNode.parentNode.querySelector('p');
	console.log(txt);
}

function addNote(){
	const para = document.createElement("p");
	const node = document.createTextNode(document.querySelector("#note").value);
	const addtxt = document.getElementById('addtxt');
	const txtcase = document.createElement("div");
	const txtedit = document.createElement("div");
	const txtdelet = document.createElement("div");
	const txtcontrol = document.createElement("div");
	addtxt.classList.add("w-full", "flex");

	if (addtxt.childElementCount > 0)
	{
		const sep = document.createElement("div");
		sep.className = "bg-slate-400 w-full h-px";
		addtxt.appendChild(sep);
	}

	txtedit.style.backgroundImage = "url(/home/haru/studies/computer_science/programming/web-dev/todo-list/pen.svg)";
	txtdelet.style.backgroundImage = "url(/home/haru/studies/computer_science/programming/web-dev/todo-list/trash.svg)";
	txtcase.classList.add("flex", "w-full", "justify-between", "flex-row");
	txtcontrol.classList.add("flex", "flex-row", "gap-3")
	txtdelet.classList.add("flex", "w-5", "h-5", "bg-cover", "bg-no-repeat", "bg-center", "bg-auto");
	txtedit.classList.add("flex", "w-5", "h-5", "bg-cover", "bg-no-repeat", "bg-center", "bg-auto");
	para.appendChild(node);
	txtcase.appendChild(para);
	txtdelet.addEventListener('click', deletOnClick);
	txtedit.addEventListener('click', editOnClick);
	txtcontrol.appendChild(txtedit);
	txtcontrol.appendChild(txtdelet);
	txtcase.appendChild(txtcontrol);
	addtxt.appendChild(txtcase);
	addtxt.appendChild(txtcase);
	
	element.value = null;
}