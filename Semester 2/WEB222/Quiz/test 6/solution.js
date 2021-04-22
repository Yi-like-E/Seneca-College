// create the global event handlers using onload so that it's content will fire when the webpage has loaded
window.onload = function() {
    // change the title
    document.title = "Test 6";
    // change the content by selecting the class intro
    let intro = document.querySelector(".intro");
    intro.innerText = "YiHsun Lee";
    // set the id for class intro with my student number
    intro.id = "129713202";
    // create an event listener to add div elements inside <main> when the start button is clicked
    let btn = document.querySelector("#start");
    btn.addEventListener("click", function(){
        let div = document.createElement("div");
        let msg = "Start was clicked!";
        div.innerText = msg;
        let main = document.querySelector("main");
        main.appendChild(div);
    });
    // use setInterval() to update the h1 every 8 seconds to show how many div elements are inside the <main>
    setInterval(function(){
        let list = document.querySelectorAll("div");  // get a list of all the div elements 
        let num = (list.length)-1;                        // calculate how many elements are in the list. -1 to exclude the first div elements that are outside of <main>
        let h1 = document.querySelector("h1");
        h1.innerText = `There are ${num} of div elements in main`;  // display the message for h1
        
    }, 8*1000);
};

