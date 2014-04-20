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
    out.textContent = 'You have spent :';
    document.getElementById('box').hidden = true;
    document.getElementById('number').hidden = false;
    document.getElementById('record').hidden = true;
     chrome.storage.sync.get("total",function(val){
          
          if (typeof(val.total) == 'undefined') {
            val.total = 0;
          };
          document.getElementById('number').innerHTML = val.total;
      });
    
    });
}


function startApp()
{
    var button1 = document.getElementById('new');
    var button2 = document.getElementById('check');
    var newExpense = document.getElementById('userInterface'); 
    var newInput = document.getElementById('box'); 
    

   chrome.storage.sync.get("total",function(val){
          if (typeof(val.total) == 'undefined') {
            val.total = 0;
          };
          expense = val.total;
      });

    
    document.getElementById('box').hidden = true;
   out = document.getElementById('displayMessage');
    
   newExpense.onsubmit = function(){
    var number = newInput.value;
    //document.getElementById("testInput").innerHTML = number;


      chrome.storage.sync.get("total",function(val){
          
          if (typeof(val.total) == 'undefined') {
            val.total = 0;
          };
          expense = val.total;
     	});

     // document.getElementById("testDB").innerHTML = expense;


   	expense = parseFloat(expense) + parseFloat(number);
    
  //  document.getElementById("testSum").innerHTML = expense; 

     (expense).toString();

     chrome.storage.sync.set({"total":expense},function(){;});

    

    
     newInput.value = '';
     document.getElementById('record').hidden = false;
     document.getElementById('record').innerHTML = 'Expense Recorded!'
     //return false;       
   };    
    displayNewExpense(button1);
    displayCheckExpens(button2);
}

window.onload = startApp();