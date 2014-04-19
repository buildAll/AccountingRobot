var out;

function newexpense()
{
	document.write("Pls enter:");
}


function displayNewExpense(button)
{
	//document.getElementById("replace").innerHTML = 'I am Zhao Biao';
	//document.write("Pls enter:");
	 button.addEventListener('click', function() {
   // tracker.sendEvent('Flavor', 'Choose', button.id);
    out.textContent = 'How much money did you spend?';
    //out.innerHTML = 'ok';
    document.getElementById('box').hidden = false;
    });


}

function displayCheckExpens(button)
{
	button.addEventListener('click', function() {
   // tracker.sendEvent('Flavor', 'Choose', button.id);
    out.textContent = 'You have spent :';
    //out.innerHTML = 'ok';
    });
}


function startApp()
{
    var button1 = document.getElementById('new');
    var button2 = document.getElementById('check');
     document.getElementById('box').hidden = true;
   // out = document.getElementById('replace');
    out = document.getElementById('display');

    //button1 = testReplace;
    displayNewExpense(button1);
    displayCheckExpens(button2);
}

window.onload = startApp();