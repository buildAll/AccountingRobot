var out;

var expense;





function displayNewExpense(button)
{
	//document.getElementById("replace").innerHTML = 'I am Zhao Biao';
	//document.write("Pls enter:");
	 button.addEventListener('click', function() {
   // tracker.sendEvent('Flavor', 'Choose', button.id);
    out.textContent = 'How much money did you spend?';
    //out.innerHTML = 'ok';
    document.getElementById('box').hidden = false;
    document.getElementById('number').hidden = true;
    });


}

function displayCheckExpens(button)
{
	button.addEventListener('click', function() {
   // tracker.sendEvent('Flavor', 'Choose', button.id);
    out.textContent = 'You have spent :';
    //out.innerHTML = 'ok';
    document.getElementById('box').hidden = true;
    document.getElementById('number').hidden = false;
    document.getElementById('record').hidden = true;
    //expense = localStorage.getItem("consume");
    document.getElementById('number').innerHTML = expense;
    });
}


function startApp()
{
    var button1 = document.getElementById('new');
    var button2 = document.getElementById('check');
    var newExpense = document.getElementById('userInterface'); 
    var newInput = document.getElementById('box'); 

    expense = localStorage.getItem("consume");
    
    if (expense == "NaN") {expense = 0;};
    
    document.getElementById('box').hidden = true;
   // out = document.getElementById('replace');
   out = document.getElementById('displayMessage');
    
   // newExpense.onsubmit = dbUpdate();
   newExpense.onsubmit = function(){
    var number = newInput.value;


      
    expense = localStorage.getItem("consume");
    
    if (expense == "NaN") {expense = 0;};

    //document.getElementById("testDB").innerHTML = expense;

   	expense = parseFloat(expense) + parseFloat(number);
     
     //expense = parseFloat(expense);   

     localStorage.setItem("consume", expense); 
   	//number.replac(/ /g,'');
    
    // Check to make sure the text is not blank (or just spaces).
    
     newInput.value = '';
     document.getElementById('record').hidden = false;
     document.getElementById('record').innerHTML = 'Expense Recorded!'
     //return false;       
   };    
    //button1 = testReplace;
    displayNewExpense(button1);
    displayCheckExpens(button2);
}

window.onload = startApp();