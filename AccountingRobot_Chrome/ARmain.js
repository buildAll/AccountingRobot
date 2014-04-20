var out;

var expense;

//var total = {};

var testflag = 0;





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
    
    document.getElementById("testDB").innerHTML = 'start test';
    
    //expense = localStorage.getItem("consume");
   // expense = chrome.storage.local.get("consume");
  /* if (testflag == 0 ) {
   	chrome.storage.local.set({"total":"parseFloat(expense)"},function(){
   		testflag = 1;


   	});
   };
   
   chrome.storage.local.set({total:parseFloat(expense)},function(){
   		testflag = 1;


   	});
   

    chrome.storage.local.get(total,function(val){
          document.getElementById("testDB").innerHTML = val.total;
     	});

*/
   document.getElementById("testDB").innerHTML = expense;


    //if (expense == "NaN") {expense = 0;};
    
    document.getElementById('box').hidden = true;
   // out = document.getElementById('replace');
   out = document.getElementById('displayMessage');
    
   // newExpense.onsubmit = dbUpdate();
   newExpense.onsubmit = function(){
    var number = newInput.value;
     

      //chrome.storage.local.set({"total":number},function(){;});
      chrome.storage.local.get("total",function(val){
          document.getElementById("testDB").innerHTML = val.total;
     	});
     // chrome.storage.local.set({"total":expense},function(){;});
/*
     chrome.storage.local.get("total",function(val){
          expense = val;
          if (expense == "NaN") {expense = 0}; 
     	});
*/
   // chrome.storage.local.get({"consume":expense},function());
/*
    chrome.storage.local.get("consume",function(){
           if (consume == null) {expense = 0;}
           else{
           	expense = consume;
           }
           if (expense == "NaN") {expense = 0;};
              
     	});
 */
    //expense = localStorage.getItem("consume");
   // expense = chrome.storage.local.get("consume");

      chrome.storage.local.get("total",function(val){
          expense = val.total;
          if (expense == "NaN") {expense = 0}; 
     	});

    if (expense == "NaN") {expense = 0;};

    //document.getElementById("testDB").innerHTML = expense;

   	expense = parseFloat(expense) + parseFloat(number);
     
     //expense = parseFloat(expense);  

     (expense).toString();

    //chrome.storage.local.set("consume",expense);
     chrome.storage.local.set({"total":expense},function(){;});

    
     //localStorage.setItem("consume", expense); 
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